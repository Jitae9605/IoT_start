#include <stdio.h>

int main_loop(void)
{
	/* 완료한거 주석처리용 - 이거 지우면 됨
	
	// ++
	int a = 10;
	printf("a는 %d\n", a);
	a++;
	printf("a는 %d\n", a);
	a++;
	printf("a는 %d\n", a);
	a++;

	int b = 20;
	printf("b는 %d\n", ++b); // 앞에 ++이 있으면 먼저 +1을 수행하고 값을 참조
	printf("b는 %d\n", b++); // 뒤에 ++이 있으면 먼저 값을 참조하고 +1을 수행
	printf("b는 %d\n", b);


	printf("----------------------------------\n");
	// 반복문
	// for, while, do while

	// for(선언; 조건; 증감) {수행부} 꼴
	// 조건이 참이면 수행부 수행하고 증감부를 수행한다
	for (int i = 1; i <= 10; i++)
	{
		printf("Hello World %d\n", i);
	}

	// while (조건) {수행부}
	// 선언부가 없으니 미리 인수를 선언해야함 + 조건이 참이면 수행부 수행
	int i = 1;
	while (i <= 10)
	{
		printf("Hello World %d\n", i++);
	}

	// do {수행부} while (조건)
	int j = 1;
	do {
		printf("Hello World %c\n", j++);
	} while (j <= 10);
	printf("----------------------------------\n");

	// 이중 반복문
	for (int i = 1; i <= 3; i++)
	{
		printf("첫번째 반복문  : %d\n", i);
		 
		for (int j = 1; j <= 5; j++)
		{
			printf("   두번째 반복문 : %d\n", j);
		}
	}

	// 구구단
	for (int i = 1; i <= 9; i++)
	{
		printf("%d단\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

	// 직각삼각형 만들기
	int length = 8; // 직각삼각형 밑변크기 (실제로는 이등변 삼각형이지만 결과창에서 볼때는 세로가 길어서)
	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	// 직각삼각형(좌우반전)
	int length = 5;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");

	}
		printf("----------------------------------\n");

		완료한거 주석처리용 - 이거 지우면 됨 */

	// 프로젝트
	// 피라미드 쌓기 프로젝트 작성
	int floor;
	printf("몇 층으로 쌓겠느냐? : ");
	scanf_s("%d", & floor);
	for (int i = 0; i < floor; i++) 
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;

}