#include <stdio.h>

// 예제1 함수선언 
void swap_double_ptr(char** ppa, char** ppb);	// [ 이중포인터를 이용한 포인터교환 ]
void swap_ptr(char** ppa, char** ppb);			// [ 포인터를 이용한 포인터 교환 ]



int main(void)
{
	// 14. 응용포인터와 배열포인터

	printf("\n------------------- < 1) 이중포인터 개념 및 사용 > ---------------------------------------------\n");
	// 1) 이중포인터 개념 및 사용
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("변수 \t 변숫값 \t&연산 \t\t*연산 \t **연산 \t\n\n");
	printf("a   %10d \t %10u\n",a, &a);												//	a값			a주소값
	printf("pi  %10u \t %10u \t %10d\n", pi, &pi, *pi);								//	a주소값		pi주소값		a값
	printf("ppi %10u \t %10u \t %10u \t %10u\n", ppi, &ppi, *ppi, **ppi);			//	pi주소값		ppi주소값	a주소값	a값
		
	//	결국 포인터는 값으로 다른 변수의 ㅈ소값을 가지는 것으로 그 자신도 주소를 가지고 있다
	//	이중 포인터는 또하나의 포인터를 선언해 기존의 포인터의 주소를 저장하는 것으로
	//	포인터ppi -> 포인터pi -> 변수a 를 가지게 하는것
	//	
	//	즉, ppi를 출력하면
	// 
	//	ppi = pi의 주소값		( = &pi) 
	// 
	//	&ppi = ppi의 주소값		( = &ppi )
	// 
	//	*ppi = ppi의 값에 해당하는 주소의 메모리공간에 저장된 값 = pi에 저장된 값 = pi값
	//				( = *(&pi) = pi )
	// 
	//	**ppi = ppi의 값에 해당하는 주소의 메모리공간에 저장된 값을 다시 주소로서 해당 주소에 해당하는 메모리공간속의 값
	//				= pi의 값에 해당하는 주소의 메모리공간에 저장된 값 = a에 저장된 값 = a값
	//					( = **ppi = *(*(&pi)) = *pi = *(&a)) = a )	

	printf("\n------------------- < 예제1 > ---------------------------------------------\n\n");
	char* pa_ex1 = "success";
	char* pb_ex1 = "failure";

	printf(" 변경전 : pa -> %s, pb -> %s\n", pa_ex1, pb_ex1);
	swap_double_ptr(&pa_ex1, &pb_ex1);
	printf(" 변경후 : pa -> %s, pb -> %s\n", pa_ex1, pb_ex1);

	printf("\n------------------- < 예제2 > ---------------------------------------------\n\n");
	char pa_ex2 = "success";
	char pb_ex2 = "failure";

	printf(" 변경전 : pa -> %s, pb -> %s\n", pa_ex2, pb_ex2);
	swap_ptr(&pa_ex2, &pb_ex2);
	printf(" 변경후 : pa -> %s, pb -> %s\n", pa_ex2, pb_ex2);


	return 0;
}

// 예제1 함수정의
void swap_double_ptr(char** ppa, char** ppb)	// [ 이중포인터를 이용한 포인터교환 ]
{
	//	포인터의 주소를 매개변수로 이중포인터에 저장하고 포인터의 주소값을 값으로 가진 이중포인터간에 값을 교환
	// 
	//	즉, char **ppa = *(*(&pa_ex1)) = *("succece")
	//		char **ppb = *(*(&pb_ex2)) = *("failure")
	// 
	//	이때, "succec", "failure" 은 문자열이므로 자체적인 주소값을 가지고있다.
	//	즉, **ppa 는 "suceece" 배열의 주소값내의 값을 가리키게 되고,
	//		**ppb 는 "failure" 배열의 주소값내의 값을 가리킨다.

	char* pt;

	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}

void swap_ptr(char* ppa, char* ppb)			// [ 포인터를 이용한 포인터 교환 ]
{
	char* pt;

	pt = ppa;
	ppa = ppb;
	ppb = pt;

}