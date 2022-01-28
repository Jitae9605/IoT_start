#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level); // level이 올라갈수록 넓은 범위와 숫자에서 랜덤값을 가져온다
void showQuestion(int level, int num1, int num2);
void success();
void fail();


int main_function_project(void)
{
	// 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제
	// 맞히면 통과, 틀리면 실패

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		// x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2); // printf("%d x %d ?", num1, num2);

		int answer = -1;
		scanf_s("%d", & answer);

		if (answer == -1) // 사용자가 종료를 원할 경우 
		{
			printf("프로그램을 종료합니다\n");
			exit(0); // exit(0) 는 프로그램을 곧바로 종료해버린다.
		}

		else if (answer == num1 * num2) // 성공
		{
			success();
			count++;
		}
		else // 실패
		{
			fail();
		}

	}

	printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맟췄습니다! \n", count);
	
	return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n############## %d 번째 비밀번호 ############\n", level);
	printf("\n\t%d x %d 는?\n\n", num1, num2); //\t = 탭 = 스페이스바 8번 = 공백 8개
	printf("##################################################\n");
	printf("\n비밀번호를 입력하세요 (종료 = -1) >> ");
}

void success()
{
	printf("\n >> Good! 정답입니다! \n");
}

void fail()
{
	printf("\n >> 땡! 틀렸습니다! \n");
}