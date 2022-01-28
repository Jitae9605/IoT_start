#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_rand(void)
{
	// rand()
	// 랜덤한 난수값 생성 =  실행할때마다 값이 다름
	// <time.h> 와 <stdlib.h> 를 추가해야한다.
	
	// 꼴 : int 이름 = rand() % 난수의 범위
	int num = rand() % 3; // 0 ~ 2 까지의 수 중에서 무작위 선택된다.
	int num1 = rand() % 3 + 1; // 1 ~ 3 까지의 숫자중 하나를 무작위로 갖는다.


	// 난수 초기화 꼭 필요함 = srand(time(NULL))
	
	printf("난수 초기화 이전.. \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9 사이의 랜덤한 수를 10번 뽑는다
	}
	// 난수 초기화 안하면 매번 실행할때 같은 값이 출력된다.

	printf("\n\n난수 초기화 이후..\n");
	srand(time(NULL)); // 난수 초기화
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9 사이의 랜덤한 수를 10번 뽑는다
	}

	

	return 0;
}