#include <stdio.h>

int main_1213321(void)
{
	// 10. 포인터

	/*
	
	기본형태 = 선언 = '자료형 *포인터명 = &변수명' ex) int *pa = &a;
			  사용 = *포인터명  ex) *pa = 30;	 ==> 변수 a에 30이 저장됨 (간접참조) 
	의미 : pa라는 포인터에 변수a의 값이 저장된 메모리상의 주소를 저장. *pa를 통해 pa가 가진 주소에 해당하는 변수를 사용/수정

	*/

	int a = 10, b = 20, i = 10, j = 20;
	const int* pa = &a;					// 앞쪽에 const사용 = 포인터 pa를 이용한 간접참조를 통해 값을 수정할수 없다
	int* const pb = &i;					// 뒤쪽에 const사용 = 포인터 pb가 가리키는 주소의 대상을 바꿀수 없다 ( &i 로 고정 )

	printf("a값 : %d\n", *pa);

	pa = &b;
	printf("b값 : %d\n", *pa);
	//*pa = 30;							// 현재 pa가 가리키는 b의 값을 간접참조로 바꾸려고 시도
	//printf("b값 : %d\n", *pa);			// const 때문에 불가능
	
	pa = &a;
	printf("a값 : %d\n", *pa);
	//*pa = 30;							// 현재 pa가 가리키는 a의 값을 간접참조로 바꾸려고 시도
	//printf("b값 : %d\n", *pa);			// const 때문에 불가능

	/*pb = &j;*/						// const로 인해 해당 포인터가 가리키는 변수(&i)를 바꿀수 없다.



	return 0;
}