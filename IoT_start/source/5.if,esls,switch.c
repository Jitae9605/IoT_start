#include <stdio.h>


// 5. 조건문
// if, if-else, switch-case 등등

int main_if(void)
{
	// 1. if문의 기본 문법

	/*

	// 1) if문

	 if (조건부)
	 {
	 	실행부;
	 }

	// * if 문 예제 * 
	int a = 20;
	int b = 0;

	if (a > 10)								// a가 10보다 크면 조건식은 참
	{
		b = a;								// b = a 대입문 실행
	}

	printf("a : %d, b : %d\n", a, b);		// 대입이 수행되면 두 값은 같음

	*/

	/*

	// 2) if_else문

	if (조건부)
	{
		실행부1;
	}
	else
	{
		실행부2;
	}

	// * if-else문 예제 * 

	int a = 10;

	if (a >= 0)
	{
		a = 1;		// a가 0보다 크거나 닽으면 a에 1 대입
	}
	else
	{
		a = -1;		// a 가 0보다 작다면 a에 -1 대입
	}
	printf("a : %d\n", a);

	*/

	/*

	// 3) if_else if문
	// else if는 몇개든 상관 X

	if (조건부1)
	{
		실행부1;
	}
	else if (조건부2)
	{
		실행부2;
	}
	else
	{
		실행부3;
	}

	// * if-else if문 예제 * 

	int a = 0, b = 0;

	if (a > 0)			// a가 0보다 크면 b에 1 대입
	{
		b = 1;
	}
	else if (a == 0)		// a가 0이면 b에 2 대입
	{
		b = 2;
	}
	else					// a가 0보다 크지않고 0도 아니면 b에 3 대입
	{
		b = 3;
	}

	printf("b : %d\n", b);

	*/


	// 2. if문 중첩
	// if문의 실행부에 다시 if문을 배치한 것

	/*

	if (조건부1)
	{
		실행부1
		if (조건부2)
		{
			실행부2
		}
	}

	// * 중첩 if문 예제 * 
	int a = 20, b = 10;

	if (a > 10)				// a가 10보다 크면  수행부의 if문 수행
	{
		if (b >= 0)			// b가 0이상이면 b에 1을 대입
		{
			b = 1;
		}
		else
		{
			b = -1;			// b가 0보다 작으면 b에 -1 대입
		}
	}

	printf("a : %d, b : %d\n", a, b);

		*/
		
	/*

	// 3. switch ~ case 문
	// switch ~ case 문은 수식을 사용X  
	// 단순 다른 연산에서의 결과값에 따라 결과를 출력
	// break 나올때까지 조건맞은 이후의 모든 case수행부분 전부 실행

	// * switch ~ case 문 예제 1 *
	// 기본적인 switch ~ case 문 의 사용

	int rank = 2, m = 0;
	
	switch (rank)		//rank 값 확인
	{
	case 1:
		m = 300;
		break;
	case 2:
		m = 200; 
		break;
	case 3:
		m = 100;
		break;
	default:
		m = 10;
		break;
	}

	printf("m : %d\n", m);

	// * switch ~ case 문 예제 2 *
	// switch ~ case 문에서의 break 활용 및 필요성

	int rank1 = 2, rank2 = 4, m1 = 0, m2 = 0;

	switch (rank1)					// rank1 값 확인
	{
	case 1:
		m1 += 100;
	case 2:
		m1 += 100;
	case 3:
		m1 += 100;
		break;
	case 4:
		m1 += 100;
	case 5:
		m1 += 100;
	case 6:
		m1 += 100;
		break;
	}

	switch (rank2)					// rank2 값 확인
	{
	case 1:
		m2 += 100;
	case 2:
		m2 += 100;
	case 3:
		m2 += 100;
		break;
	case 4:
		m2 += 100;
	case 5:
		m2 += 100;
	case 6:
		m2 += 100;
		break;
	}

	printf("rank1의 점수 : %d\n", m1); // m1 : 200
	printf("rank2의 점수 : %d\n", m2); // m2 : 300

	*/


	return 0;
}