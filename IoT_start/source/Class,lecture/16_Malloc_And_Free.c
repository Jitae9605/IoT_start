#include <stdio.h>
#include <stdlib.h>		// !!! malloc, free 함수 사용을 위한 헤더 파일 포함 !!!
#include <string.h>

// ========================================= 함수 선언부 ====================================================================

//	예제 2
void print_str_ex2(char** ps_ex2);		//  [ 동적할당영역의 문자열을 출력하는 함수 ] 


// ========================================= main 함수 ====================================================================



int main(void)
{
	// 16. 메모리 동적할당

	printf("\n------------------- < 1) Malloc, Free > ---------------------------------------------\n\n");
	// 동적할당하고 끝나면 반드시 free를 통해 할당한 메모리를 반환해야 메모리 누수를 막을 수 있다.

	int* pi_1;									//	동적할당영역을 연결할 포인터 선언
	double* pd_1;

	pi_1 = (int*)malloc(sizeof(int));			//	메모리 동적할당후 포인터 연결
	if (pi_1 == NULL)							//	동적할당 실패시 NULL 반환되는것을 이용해 예외상황 처리
	{
		printf("# 메모리가 부족합니다.\n");		// 예외상황 처리부분
		exit(1);								// 프로그램 종료
	}

	pd_1 = (double*)malloc(sizeof(double));

	*pi_1 = 10;									//	포인터로 동적할당 영역사용		(값 저장)
	*pd_1 = 3.4;

	printf("정수형으로 사용 : %d\n", *pi_1);			// 동적할당영역(정수부 = pi_1) 에 저장된 값 출력	
	printf("실수형으로 사용 : %.1lf\n", *pd_1);		// 동적할당영역(실수부 = pi_1) 에 저장된 값 출력	

	// !!! 반드시 해야한다 !!!
	free(pi_1);										// 동적할당영역 반환 
	free(pd_1);

	printf("\n------------------- < 2) 동적할당영역을 배열처럼 사용하기 > ---------------------------------------------\n\n");

	int* pi_2;												// 동적 할당 영역을 연결할 포인터
	int sum_2 = 0;

	pi_2 = (int*)malloc(5 * sizeof(int));					// 저장공간 20바이트 할당

	if (pi_2 == NULL)
	{
		printf("메모리가 부족합니다!\n");						// 예외상황 처리부분
		exit(1);
	}

	printf("다섯명의 나이를 입력하세요 : ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &pi_2[i]);									// 배열요소에 입력
		sum_2 += pi_2[i];										// 배열 요소에 값 누적
	}

	printf("다섯 명의 평균 나이 : %.1lf\n", (sum_2 / 5.0));		// 평균나이 출력
	free(pi_2);		// 할당된 메모리 영역 반환

	printf("\n------------------- < 3) 기타 동적할당 함수 > ---------------------------------------------\n\n");

	//  1. calloc 함수	= 할당된 저장공간을 0으로 초기화함	
	//		원형 : void *calloc(unsigned int, unsigned int); 

	//	2. realloc 함수	= 할당괸 저장공간 크기를 조절	
	//		원형 : void *realloc(vodi *, unsigned int); 

	int* pi_3;					// 할당된 저장공간을 연결할 포인터
	int size_3 = 5;				// 한번에 할당할 저장공간의 크기 , int형 변수 5개씩
	int count_3 = 0;			// 현재 입력된 양수 개수

	int num_3 = 0;					// 양수 입력할 변수

	pi_3 = (int*)calloc(size_3, sizeof(int));		// 먼저 5개의 저장공간 할당
	while(1)
	{
		printf("양수만 입력하세요 : ");
		scanf("%d", &num_3);						// 데이터 입력
		if (num_3 <= 0) break;						// 양수가 아니면 ( 0 or 음수 ) 종료

		if (count_3 == size_3)						// 저장공간 모두 사용시 처리
		{
			size_3 += 5;							// 크기 늘려서 재할당
			pi_3 = (int*)realloc(pi_3, size_3 * sizeof(int));
		}
		pi_3[count_3++] = num_3;
	}

	for (int i = 0; i < count_3; i++)
	{
		printf("%5d", pi_3[i]);
	}
	free(pi_3);

	printf("\n------------------- < 동적할당 활용 예제1 > ---------------------------------------------\n\n");

	char temp_ex1[80];
	char* str_ex1[3];

	for (int i = 0; i < 3; i++)									// 3개의 문자열을 입력받는다 
	{
		printF("문자열을 입력하세요 : ");
		gets(temp_ex1);
		str_ex1[i] = (char*)malloc(strlen(temp_ex1) + 1);		// 동적할당을 선언 [ 영역크기 = 문자열 길이구하는 함수를 통한 문자열길이 + 1(NULL문자를 위한공간) ]
		strcpy(str_ex1[i], temp_ex1);							// 동적할당을 통해 공간을 확보하고 그 공간에 입력받아 임시저장한 문자열을 복사
	}

	for (int i = 0; i < 3; i++)
	{
		printf("\n%s\n", str_ex1[i]);		// 입력받은 문자열 출력
	}

	for ( int i = 0; i < 3; i++)		//  동적할당영역 반환 
	{
		free(str_ex1[i]);
	}

	printf("\n------------------- < 동적할당 활용 예제2 > ---------------------------------------------\n\n");

	// 예제1을 포인터를 이용해 함수로 만들어는 예제

	char temp_ex2[80];					// 임시 char 배열
	char* str_ex2[21] = { 0 };			// 문자열을 연결할 포인터 배열, 널값으로 초기화
	int i_ex2 = 0;

	while (i_ex2 < 20)												// 최대 20개의 문자열을 입력받아 동적할당후 저장 
	{
		printf("문자열을 입력하세요 : ");
		gets(temp_ex2);
		if (strcmp(temp_ex2, "end") == 0) break;					// 'end' 를 입력받으면 종료

		str_ex2[i_ex2] = (char*)malloc(strlen(temp_ex2) + 1);		// 동적할당 [ 영역크기 = 입력받은 문자열 길이 + 1(NULL 값을 위한) ]
		strcpy(str_ex2[i_ex2], temp_ex2);							// 할당된 영역에 입력받은 문자열 복사
		i_ex2++;
	}

	print_str_ex2(str_ex2);

	for (int i = 0; str_ex2[i] != NULL; i++)						// str_ex2에 연결된 문자열에 없을떄까지 반복
	{
		free(str_ex2[i]);											// 동적할당영역 반환
	}


	return 0;
}

// ========================================= 함수 정의부 ====================================================================

//	예제 2
void print_str_ex2(char** ps_ex2)		// [ 동적할당영역의 문자열을 출력하는 함수 ]
{
	// * 참고 *
	// main에서 print_str_ex2(str_ex2)로 호출받음
	// 생략되어 보이지 않지만 실제로는 아래의 내용이 있는 것!
	// --------------------------------------------
	// char **ps_ex2 = str_ex2;
	// --------------------------------------------

	while (*ps_ex2 != NULL)				// 포인터 배열의 값이 널이 아닌동안 반복
	{
		printf("%s\n", *ps_ex2);		// ps_ex2가 가리키는 것은 포인터 배열의 요소리고 이를 출력한다.
		ps_ex2++;						// ps_ex2가 다음 배열요소를 가리킨다.
	}

	//	* 참고1 
	//	main에서 print_str_ex2(str_ex2)로 호출받음
	//	**ps_ex2 = str_ex2 = *(*(&str_ex2[0])) = *(str_ex2[0]) [ 이때, str_ex2는 포인터 배열이므로 str_ex2[0]또한 포인터 ]
	//	즉, str_ex[0]의 값(주소값)에 해당하는 주소를 가진 메모리영역의 공간에 저장되어있는 값(입력받은 문자열)에 접근

	//	** 참고2
	//	'ps_ex2++' 는 ps_ex2 = ps_ex2 + 1 이므로 다음 반복에서
	//	printf("%s\n", *(ps_ex2 + 1)); 로 계산되고 
	//	여기서 *(ps_ex2 + 1) = *(*(&str_ex2[0]) + 1 ) = *(str_ex2[0] + 1) = *(str_wx2[1]) 이다.
	//	즉, 다음 포인터 배열에 들어가있는 주소값이 가리키고있는 문자열로 다음번째 입력받은 문자열값이다.
	//	이를 다음 문자열에 저장된 값이 NULL일때까지 반복
 
		
	
}