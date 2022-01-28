#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 프로젝트
// <고양이 수집게임>
// 5종류의 고양이가 랜덤으로 들어있는 상자
// 상자를 열때마다 동일한 확률로 5마리의 고양이중 한마리가 등장(중복가능)
// 5종류를 모두 모으면 승리

// 고양이
// 이름, 성격, 나이, 키우기 난이도(레벨)

// 구조체(고양이)
typedef struct {
	char* name; // 이름
	int age; // 나이
	char* character; // 성격
	int level; // 키우기 난이도 (1 ~> 5)
} CAT;

// 현재까지 보유한 고양이
int collection[5] = { 0,0,0,0,0 }; // 0 = 아직 없는 것 / 1 = 뽑은 것

// 전체 고양이 리스트
CAT cats[5];

// 함수선언
void initCats(); //고양이 정보 초기화
void printCat(int selected); // 뽑은 고양이의 정보출력 함수
int checkCollection();

int main_struct_project(void)
{
	srand(time(NULL));

	// 초기화 함수
	initCats();

	// 다 뽑을때 까지 반복
	while (1)
	{
		printf("두근두근 어느 고양이의 집사가 될까요? \n아무키나 눌러서 확인하세요!");
		getchar(); // 아무키나 입력될때까지 대기하는 함수
		
		int selected = rand() % 5; // 0 ~ 4 사이의 숫자 반환 = 고양이 뽑기
		printCat(selected); // 뽑은 고양이의 정보를 출력하는 함수
		
		// 뽑은 고양이는 뽑았다고 처리
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1)
		{
			break;
		}

	}

	return 0;
}

void initCats() // 고양이 정보 초기화 및 입력
{
	// 1번 고양이의 정보
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순함";
	cats[0].level = 1;

	// 2번 고양이의 정보
	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "날카로움";
	cats[1].level = 2;

	// 3번 고양이의 정보
	cats[2].name = "수줍이";
	cats[2].age = 7;
	cats[2].character = "늘 잠만 잠";
	cats[2].level = 3;

	// 4번 고양이의 정보
	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "말 많음";
	cats[3].level = 4;

	// 5번 고양이의 정보
	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "항상 배고파함";
	cats[4].level = 5;
}

void printCat(int selected) // 뽑힌 고양이의 정보를 출력하는 함수
{
	printf("\n\n=== 당신은 이 고양이의 잡사가 되었어요! ===\n\n");
	printf("이름			: %s\n", cats[selected].name);
	printf("나이			: %d\n", cats[selected].age);
	printf("특징(성격)		: %s\n", cats[selected].character);
	printf("레벨			: "); // 레벨은 별 갯수로 표시한다
	
	// level 과 같은 갯수의 '★'을 출력
	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "★");
	}
	printf("\n\n"); // 구분을 위한 줄넘김
}

int checkCollection() // 뽑기후의 상태 출력
{
	// 1. 현재 보유한 고양이 목록출력 
	// 2. 모두 모았는지 여부 확인
	int collectAll = 1;

	printf("\n\n ===== 보유한 고양이 목록이에요 ===== \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) // 해당 고양이 미보유 상태(0)
		{
			printf("%10s", " (빈 박스) ");
			collectAll = 0; // 아직 안뽑은 고양이가 있다!
		}
		else // 해당 고양이 보유함(뽑은 적 있음)
		{
			printf(" [%s] ", cats[i].name);
		}
	}
	printf("\n\n=========================================\n\n");

	if (collectAll) // 모든 고양이를 다 모은 경우
	{
		printf("\n\n 축하합니다! 모든 고양이를 다 모았습니다! 열심히 키워주세요\n\n");
	}

	return collectAll;
}