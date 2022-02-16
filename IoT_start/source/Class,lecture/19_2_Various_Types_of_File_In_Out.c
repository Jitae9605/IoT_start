#include <stdio.h>
#include <string.h>

// ========================================= 함수 선언부 ====================================================================

// 예제1 함수선언 

// ========================================= main 함수 ====================================================================

int main(void)
{
	// 19.2. 다양한 파일 입출력
	printf("\n------------------- < 1) fgets와 fputs로 한줄씩 입출력 > ---------------------------------------------\n\n");

	// 파일에 문자열을 입렫받아 저장하는 함수 fputs는 입력 받을때 매번 줄넘김을 해서 파일에 저장을 합니다.
	FILE* ifp_1, *ofp_1;				// 파일포인터 선언
	char str_1[80];						// 입력한 문자열 저장할 배열
	char* res_1;						// fgets 함수의 반환값을 저장할 변수

	ifp_1 = fopen("19_2_1_a.txt", "r");			// 입력파일을 읽기전용으로 개방

	if (ifp_1 == NULL)							// 입력파일 열지 못한 경우 처리
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp_1 = fopen("19_2_1_b.txt", "w");			// 출력파일 쓰기전용으로 개방

	if (ofp_1 == NULL)							// 출력파일 열지 못한 경우 처리
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res_1 = fgets(str_1, sizeof(str_1), ifp_1);		// 입력 파일로부터 한줄을 읽어와서 str_1에 저장

		if (res_1 == NULL)								// 읽어올 값이 없으면(NULL) 반복문 탈출
		{
			break;
		}

		str_1[strlen(str_1) - 1] = '\0';				// 개행문자 제거(1줄씩 읽어오니까)
		fputs(str_1, ofp_1);							// 처리 마친 str_1의 내용을 출력파일에 쓰기
		fputs(" ", ofp_1);								// 출력파일에 str_1의 내용 모두 쓴뒤 공백(띄어쓰기) 추가 
	}

	fclose(ifp_1);										// 입력파일 닫기
	fclose(ofp_1);										// 출력파일 닫기

	printf("\n------------------- < 2) fscnaf와 fprintf 로 다양한 형태의 입출력 수행  > ---------------------------------------------\n\n");

	FILE* ifp_2, * ofp_2;
	char name_2[20];
	int kor_2, eng_2, math_2;
	int total_2;
	double avg_2;
	int res_2;

	ifp_2 = fopen("19_2_2_a.txt", "r");			// 입력파일 읽기전용으로 개방
	if (ifp_2 == NULL)							// 입력파일 열지 못한 경우 처리
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp_2 = fopen("19_2_2_b.txt", "w");			// 출력파일 쓰기전용으로 개방

	if (ofp_2 == NULL)							// 출력파일 열지 못한 경우 처리
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res_2 = fscanf(ifp_2, "%s%d%d%d", name_2, &kor_2, &eng_2, &math_2);			// 입력파일로 부터 값을 받아와서 저장
		if (res_2 == EOF)															// 읽어올값이 없으면 종료
		{
			break;
		}
		total_2 = kor_2 + eng_2 + math_2;							// 총점계산
		avg_2 = total_2 / 3.0;										// 평균계산
		fprintf(ofp_2, "%s%5d%7.1lf\n", name_2, total_2, avg_2);	// ofp_2파일에 지정한 형식에 맞게 출력
	}

	fclose(ifp_2);						// 입력파일 닫기
	fclose(ofp_2);						// 출력파일 닫기

	// * 참고
	// fscanf는 모든 값을 읽어 왔으면 EOF를 반환한다.

	printf("\n------------------- < 3) 스트림파일의 버퍼공유문제와 fflush 함수 > ---------------------------------------------\n\n");

	printf(" < 문제 해결전 > \n\n");
	FILE* fp_3_1;
	int age_3_1;
	char name_3_1[20];

	fp_3_1 = fopen("19_2_3_1_a.txt", "r");

	fscanf(fp_3_1, "%d", &age_3_1);
	fgets(name_3_1, sizeof(name_3_1), fp_3_1);

	printf(" 나이: %d ,이름 : %s", age_3_1, name_3_1);
	fclose(fp_3_1);


	// 이렇게 하면 이름이 들어가지 않는다!
	// 이유는 fscanf가 입력버퍼에 남겨놓은 개행문자를 fgets가 보고 개행문자를 가져가서 name_3에 넣어버린다.
	// 이를 해결하고자 fscaf를 이용하면 "Hong GD" 중에서 공백앞의 "Hong"만 가져가서 name_3 에는 Hong만 저장된다.

	// 이를 해결하는 방법은 fgetc함수와 fflush를 통해서 해결할 수 있다.

	printf("\n < 문제 해결후 >\n\n");
	FILE* fp_3_2;
	int age_3_2;
	char name_3_2[20];

	fp_3_2 = fopen("19_2_3_2_a.txt", "r");

	fscanf(fp_3_2, "%d", &age_3_2);
	while (fgetc(fp_3_2) != '\n') {}						// 입력파일의 내용을 한글자씩 들고와서 개행문자 아니면 버리고 개행문자면 반복종료
	fgets(name_3_2, sizeof(name_3_2), fp_3_2);

	printf(" 나이: %d ,이름 : %s", age_3_2, name_3_2);
	fclose(fp_3_2);

	return 0;
}

// ========================================= 함수 정의부 ====================================================================

//	3) getchar 함수를 이용한 문자열 입력 함수정의