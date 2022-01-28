#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 프로젝트
// 서로 다른 10마리의 동물 (각 동물당 2장의카드 = 20장의 카드)
// 사용자로 부터 2개의 입력값을 받음 -> 해당 카드 뒤집음 -> 같은 카드면 뒤집기
//모든 동물쌍 찾으면 게임종료
// 종료후 실패 횟수 알려주기

// 함수 선언
void initAnimalArray(); // 동물이 들어갈 공간(배열)만들기 (= 필드생성)
int arrayAnimal[4][5]; // 동물의 수(배열)
void initAnimalName(); // 동물의 이름
char* strAnimal[10]; // 동물의 이름 배열(포인터)
void shufflAnimal(); // 동물들의 배치와 배열을 섞는다
int getEmptyPosition(); // 빈공간의 좌표를 찾는 함수
int checkAnimal[4][5]; // 카드가 뒤집혔는지 여부 확인
void printAnimals();
void printQuestion();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main_m_array_project(void)
{
	srand(time(NULL));

	initAnimalArray(); // 동물배치
	initAnimalName(); //동물 리스트에 이름과 번호 붙이기

	shufflAnimal(); // 동물들의 배치와 배열을 섞는다

	int failCount = 0; // 실패횟수

	while (1)
	{
		int select1 = 0; // 사용자가 선택한 첫번째 수(카드)
		int select2 = 0; // 사용자가 선택한 두번째 수(카드)

		printAnimals(); //동물 위치 출력
		printQuestion(); // 물제출력(현재카드지도 및 상태출력)
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) // 같은 카드 선택은 무효후 다시 선택
			continue;

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인

		// 정수좌표를 (x,y) 로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// 카드가 이미 뒤집혀진 카드인지확인하고 같은 동물인지 확인
		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
				&& checkAnimal[secondSelect_x][secondSelect_y] == 0
			&&
			arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
		{
			// 뒤집은 두 카드가 일치할 경우
			printf("\n\n빙고! : %s 발견!\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		else // 선택한 카드가 이미 뒤집힌 카드 or 두 카드가 일치X
		{
			printf("\n\n 떙!! 틀렸거나 이미 뒤집힌 카드입니다.\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++; // 실수/시도 횟수 카운팅
		}

		// 모든 동물을 찾은경우(모든 카드 뒤집은 경우)
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 축하합니다! 모두 찾았습니다\n");
			printf("총 %d 번의 실수 만에 모두 찾았습니다\n", failCount);
			break;
		}
	}


	return 0;
}

void initAnimalArray() // 동물이 들어갈 공간(배열)만들기 (= 필드생성)
{
	for (int i = 0; i < 4; i++ )
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
}

void initAnimalName() // 배열에 동물들 집어넣고 각 동물들 의 종류(이름)붙이기
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "기린"; 
	strAnimal[6] = "낙타";
	strAnimal[7] = "타조";
	strAnimal[8] = "호랑이";
	strAnimal[9] = "코끼리";
}

void shufflAnimal() // 동물들의 배치와 배열을 섞는다
{
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// 이런 빈공간에 무작위로 두장의 같은 동물 카드를 배치하는 함수(= 섞어서 필드에 배치)
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++) // 카드는 2장씩이므로 한 동물에 2번을 수행
		{
			int pos = getEmptyPosition(); // 빈공간의 좌표를 받는다
			int x = conv_pos_x(pos); // 받은 좌표값의 x값을 변수x에 저장
			int y = conv_pos_y(pos); // 받은 좌표값의 x값을 변수x에 저장

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition() // 빈공간 찾아서 좌표값 따는 함수
{
	// ㅁㅁㅁㅁㅁ   0  1  2  3  4
	// ㅁㅁㅁㅁㅁ   5  6  7  8  9
	// ㅁㅁㅁㅁㅁ  10 11 12 13 14  
	// ㅁㅁㅁㅁㅁ  15 16 17 18 19  
	while (1)
	{
		int randPos = rand() % 20; // 0~ 19 사이의 숫자 반환(이걸 좌표로 바궈야한다)
		// ex) 19 = (3,4) 와 같이 좌표변환이 필요
		int x = conv_pos_x(randPos); // 받은 좌표값의 x값을 변수x에 저장
		int y = conv_pos_y(randPos); // 받은 좌표값의 y값을 변수y에 저장 

		if (arrayAnimal[x][y] == -1) // 빈자리(= -1)일경우 그곳의 좌표값 반환
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x) // 받은 좌표값의 x값을 변수x에 저장
{
	// ㅁㅁㅁㅁㅁ   0  1  2  3  4   (나누기 5) ->  0 0 0 0 0 
	// ㅁㅁㅁㅁㅁ   5  6  7  8  9   (나누기 5) ->  1 1 1 1 1
	// ㅁㅁㅁㅁㅁ  10 11 12 13 14   (나누기 5) ->  2 2 2 2 2
	// ㅁㅁㅁㅁㅁ  15 16 17 18 19   (나누기 5) ->  3 3 3 3 3
	// int 형이므로 0 ~ 19는 5로 나누었을때 x 값이 나온다
	return x / 5;
}

int conv_pos_y(int y) // 받은 좌표값의 y값을 변수y에 저장
{
	// ㅁㅁㅁㅁㅁ   0  1  2  3  4   (나누기 5의 나머지) ->  0 1 2 3 4 
	// ㅁㅁㅁㅁㅁ   5  6  7  8  9   (나누기 5의 나머지) ->  0 1 2 3 4
	// ㅁㅁㅁㅁㅁ  10 11 12 13 14   (나누기 5의 나머지) ->  0 1 2 3 4
	// ㅁㅁㅁㅁㅁ  15 16 17 18 19   (나누기 5의 나머지) ->  0 1 2 3 4
	// int 형이므로 0 ~ 19는 5로 나눈 나머지가 y값이다
	return y % 5;
}

void printAnimals() //동물 위치 출력
{
	// ㅁㅁㅁㅁㅁ   0  1  2  3  4
	// ㅁㅁㅁㅁㅁ   5  6  7  8  9
	// ㅁㅁㅁㅁㅁ  10 11 12 13 14  
	// ㅁㅁㅁㅁㅁ  15 16 17 18 19 

	printf("\n============= 문제 시험동작을 위한 공개답안 ===============\n\n"); // 구분선
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]); // %8s = 8칸의 공간(= 동물의 이름의 용량(8byte))
		}
		printf("\n"); // 가독성을 위한 반복마다의 줄넘김
	 }
	printf("\n===================================\n\n"); // 구분선
}

void printQuestion() // 물제출력(현재카드지도 및 상태출력)
{
	printf("\n\n(문제)\n");
	int seq = 0; // seq = 좌표가 아닌 동물 카드 숫자의 위치 (0 ~ 19)

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답이면 '동물이름'(앞면)
			if (checkAnimal[i][j] != 0)  // 카드가 뒤집혔는지 여부 확인
			{
				// 이미 뒤집혔으면 동물이름을 출력
				printf("%8s", strAnimal[arrayAnimal[i][j]]); // 8s는 줄맞춤을 위한 공백생성
			}

			// 못맞췄으면 카드위치숫자(뒷면)
			else
			{
				// 안뒤집혔으면 숫자출력
				printf("%8d", seq); // 여기에 seq++ 하면 번호판이 바뀜
			}
			seq++;  // 카드판에 숫자로 어디가 몇번인지 알수있게 번호써서 번호판 출력
		}
		printf("\n");
	}
}

int foundAllAnimals() // 모든 동물을 찾았을 경우 참값(=1)을 반환하는 함수
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0) // 
			{
				return 0;
			}
		}
	}
	return 1;
}