#include <stdio.h>
#include <time.h>

// 프로젝트

// 물고기 6마리가 사막의 어항속에 있음
// 물이 다 증발하기 전에 어항에 물을 넣어야함

// 전역변수
int level;        // 난이도
int arrayFish[6]; // 어항번호(1 ~ 6)와 각 어항의 물 높이 (1 ~ 100)
int* cursor;      // 어항의 포인터


// 함수선언
void initData();					  // 시작 데이터 (1레벨, 물높이 100 등)
void printFishes();					  // 현재 어항의 상태(물높이 1 ~ 100)
void decreaseWater(long elapsedTime); // 시간경과에 따른 물높이 감소

int main_pointer_project(void)
{
	long startTime = 0; // 게임시작 시간 (시간은 보통 long을 준다)
	long totlaElapsedTime = 0; // 총 경과시간
	long prevElapsedTime = 0; // 직전 경과시간 (= 최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지 -> 사용자 입력
	initData();

	cursor = arrayFish; // corsor = 어항의 포인터

	startTime = clock(); // clock() = 현재 시간을 1000분의 1초 단위호 반환

	while (1) // 물은 시간이 흐름에 따라 지속적으로 감소
	{
		printFishes(); // 현재 어항의 상태(물높이 1 ~ 100)
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);

		// 입력값 체크 ( 어항이 1 ~ 6번이니까 그것만 받는다 )
		if (num < 1 || num > 6)
		{
			printf("\n 입력값이 잘못되었습니다.\n");
			continue;
		}

		// 총 경과시간 출력
		// 총 경과시간 = (현재시간 - 시작시간)의 초단위로의 단위변환(CLOCKS_PER_SEC 함수)
		totlaElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과시간 : %ld 초\n", totlaElapsedTime);

		// 직전 물 준 시간(마지막 물준 시간)으로부터 흐른 시간
		prevElapsedTime = totlaElapsedTime - prevElapsedTime;
		printf("최근 경과시간 : %ld 초\n", prevElapsedTime);

		// 시간경과에 따라 어항의 물을 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 우리가 입력하는 num은 1 ~ 6 받는 실제 배열값은 0 ~ 5이므로 모두 -1 해야함
		// 1. 어항에 물이 이미 0인경우 -> 물을 주지 않는다 (이미 죽음)
		if (cursor[num - 1] <= 0) // <num = 1 ~ 6> <배열 = 0 ~ 5> 주의!
		{
			printf("%d 번 물고기는 이미 죽었습니다... 물을 주지 않습니다\n", num);
		}
		// 2. 어항의 물이 0이 아닌 경우 -> 물을 준다 (단, 100을 넘지 않는지 확인)
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d 번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1; // 물높이 1 증가
		}

		// 레벨업 여부(20초마다 level up)
		if (totlaElapsedTime / 20 > level - 1) // (총 경과시간 / 20 > 레벨 - 1)
		{
			// 1. 경과시간 19.9초 인 경우
			// 좌 : 19.9 / 20 = 0(int 이므로) 
			// 우 : levle(= 1) - 1 = 0 
			//		=> 0 > 0 [false]
			
			// 2. 경과시간 20.1초 인 경우
			// 좌 : 20.1/20 > = 1 
			// 우 : level(= 1) - 1 = 0 
			//		=> 1 > 0 [true]
			
			// 3. 경과시간 39.9초 인 경우
			// 좌 : 39.9 / 20 = 1
			// 우 : levle(= 2) - 1 = 1 
			//		=> 1 > 1 [false]
			
			// 4. 경과시간 40.1초 인 경우
			// 좌 : 40.1 / 20 > = 2 
			// 우 : level(= 2) - 1 = 1 
			//		=> 2 > 1 [true]
			
			level++; // 레벨업 수행
			printf("*** 축 레벨업! 기존 %d 레벨에서 %d 레벨로 레벨업 하였습니다! ***\n\n", level - 1, level);

			// 최종레벨은 5 -> 달성시 게임종료
			if (level == 5)
			{
				printf("\n\n축하합니다! 최고 레벨을 달성하였습니다. 게임을 종료합니다!\n\n");
				exit(0); // 모든 프로젝트 즉시 종료
			}
		}

		// 모든 물고기가 죽었는지 확인(게임종료)
		if (checkFishAlive() == 0)
		{
			// 모두 죽음
			printf("모든 물고기가 죽었습니다ㅜㅜ\n");
			printf("게임을 종료합니다.\n");
			exit(0);
		}
		else
		{
			// 최소 하나 이상의 물고기가 살아있음
			printf("물고기가 아직 살아있습니다! \n ");
		}

		// !!!! 주의 !!!!
		
		// 현재 prevElapsedTime에는 이전 물준 시간으로부터의 "간격"이 저장된다.
		// ex) 시작후 1초에 물을 주고 10초에 물을 주면 prevElapsedTime에는 9초가 기록됨
		
		// 처음은 prevElapsedTime = totlaElapsedTime - prevElapsedTime 로 계산되지만
		// 하지만 세번째 부터 (총 경과시간 - 마지막으로 물을 줄때까지의 경과시간) 으로 계산
		
		// EX) 
		// 1. 시작후 3초후 물을 준다 -> (prevElapsedTime = 3 - 0 = 3)
		// 2. 다음으로 5초후 물을 준다 -> (prevElapsedTime = 8 - 3 = 5)
		// 3. 다음은 10초후 물을 준다 -> (prevElapsedTime = 18 - 5 = 13...?)  오류발생!!!
		//	=> 10이 어야 하는데 13이라는 오류가 발생함
		 
		// 이를 해결하기 위해 반복문의 마지막 줄에서 prevElapsedTime에 "간격"이 아니라
		// 지금까지의 "총 경과시간"을 넣어야 다음 계산에서 마지막 물준 시간사이의 "간격"이 나온다
		prevElapsedTime = totlaElapsedTime; // 다음 반복에서 간격을 계산하기 위해
											
		// 간격대신 마지막 물을주기까지의 총 걸린 시간입력
		// 즉, prevElapsedTime = 지금까지의 총 경과시간 - 마지막으로 물을 줬을때 까지의 경과시간
		// 으로 사이의 "간격"이 나온다
	}


	return 0;
}

void initData()
{
	level = 1; // 게임의 레벨(1 ~ 5) (시간에 따라 상승 -> 물의 증발 속도 빨라짐)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물 높이(1 ~ 100)
	}
}

void printFishes() // 어항의 상태를 보여주는 함수
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) // 시간경과에 따른 물높이 감소
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // level에 따른 난이도상승(* 3)
		
		// 어항의 물높이가 음수가 되면 이를 0으로 바꾼다
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}

	}
}

int checkFishAlive() // 물고기 생존 확인함수
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; // 참(True)
	}
	return 0; // 거짓(False)
}