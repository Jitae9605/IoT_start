#include <stdio.h>
#include <time.h>

int main_condition(void)
{
	/* 완료한거 주석처리용 - 이거 지우면 됨
	조건부 = if, else, else if 
	
	// 버스를 탄다고 가정 학생,일반인 으로 구분 (일반인 :20세)
	int age = 15;

	if (age >= 20)
		printf("일반인입니다.\n");
	else
		printf("학생입니다.\n");


	printf("----------------------------------\n");	



	// 초등학생 (8~13) / 중학생(14~16) / 고등학생 (17~19)
	int age;
	printf("몇 살이신가요? : ");
	scanf_s("%d", &age);

	if (age >= 8 && age <= 13)
	{
		printf("초등학생입니다.\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("중학생입니다.\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("고등학생입니다.\n");
	}
	else
		printf("청소년이 아닙니다.\n");

	printf("----------------------------------\n");

	

	// break
	// 1번부터 30번까지 있는 반에서 1번에서 5번까지 조별발표 수행
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break;
		}
		printf("%d 번 학생은 조별발표 준비를 하세요\n", i);
	}

	printf("----------------------------------\n");

	// continue
	// 1번부터 30번까지 있는 반에서 7번 학생이 결석
	// 7번을 제외한 6번부터 10번까지 조별과제 수행
	
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d 번 학생은 결석입니다.\n", i);
				continue;
			}
			printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
		}
	}

	printf("----------------------------------\n");

	// 논리 연산자 &&, ||
	// and = &&  / or = || / == = 일치
	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	
	if (a == b || c == d)
	{
		printf("a 와 b 가 같거나, c 와 d 가 같습니다.\n");
	}
	else
	{
		printf("값이 서로 다르네요\n");
	}

	printf("----------------------------------\n");


	// 가위 0 바위 1 보 2 프로그램
	
	// 1. 난수와 if문 이용
	srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 사이의 난수
	if (i == 0)
	{
		printf("가위\n");
	}
	else if (i == 1)
	{
		printf("바위\n");
	}
	else
	{
		printf("보\n");
	}


	// 2. switch문 이용
	// switch(대상)
	// {
	//	case 대상의 값1: 수행; break;
	//   ...
	//  case 대상의 값n: 수행; break;
	//  default:수행; break;          // case가 정해지지 ㅇ낳은 다른 모든 값
	//	}

	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
	case 0:printf("가위\n"); break;
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("몰?루\n"); break;
	}
	// switch문은 case가 하나 일치하면 그 밑의 모든 케이스를 참으로 보고 전부 수행한다.
	// 이를 막으려면 break;를 쓰고 아니면 빼면된다.
	
	// switch문 심화
	// 나이 범위에 따른 분류
	// 초등학생(8~13) / 중학생(14~16) / 고등학생(17~19)

	int age;
	printf("몇 살이신가요? : ");
	scanf_s("%d", &age);

	switch (age)
	{
	case 8:
	case 9:
	case 10: 
	case 11: 
	case 12:
	case 13:printf("초등학생입니다.\n"); break;
	case 14:
	case 15:
	case 16:printf("중학생입니다.\n"); break;
	case 17:
	case 18:
	case 19:
	default:printf("학생이 아닙니다.\n"); break;
	}
	// 참을 만나면 switch문은 그 이후의 case의 모든 수행부를 수행한다 
	// 이를 이용해 대상이 범위에 있을경우 그에만즌 출력내용과 break;를 끝에만 써서
	// 간단하게 조절가능

	printf("----------------------------------\n");
	완료한거 주석처리용 - 이거 지우면 됨 */

	// 프로젝트
	// Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100 사이의 랜덤한 숫자
	printf("숫자 : %d\n", num);
	int answer = 0; // 정답
	int chance = 5; // 정답 기회
	while (1) // 0은 거짓 1은 참으로 이렇게 하면 while은 언제나 참이다.
	{
		printf("남은 기회 %d 번 \n", chance--);
		printf("숫자를 맞춰보세요 (1 ~ 100) : ");
		scanf_s("%d", &answer);

		if (answer > num)
		{
			printf("Down ↓\n\n");
		}
		else if (answer < num)
		{
			printf("Up ↑\n\n");
		}
		else if (answer == num)
		{
			printf("정답입니다! \n\n");
			break;
		}
		else
		{
			printf("알 수 없는 오류가 발생하였습니다.\n\n");
		}

		if (chance == 0)
		{
			printf("모든 기회를 다 사용하였습니다. 다시 도전해 보세요\n");
				break;
		}

	}
	
	return 0;
}