#include <stdio.h>
#include <time.h>

// 프로젝트
// 머리에 4개의 약병중 둘 이상의 무작위의 약을 뿌리고 볓번의 약병에 발모제가 있는지 맞추기

int main_array_project(void)
{
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 ===\n\n");
	int answer; // 사용자 입력값 (= 답안작성란)
	int treatment = rand() % 4; // 발모제의 번호 (0 ~ 3)

	int cntShowBottle = 0; // 이번 게임에서 보여줄 병 갯수
	int prevCntShowBottle = 0; // 앞 게임에서 보여준 병 갯수
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음엔 2개 -> 3개...)

	// 3번의 투약 = 4개의 병중 여러개를 무작위로 골라 총 3번 투여후 반응 출력
	for (int i = 1; i <= 3; i++) // i = 투약 횟수 
	{
		int bottle[4] = { 0, 0, 0, 0 }; // 약병이 총 4개 임을 의미
										// 0 = 선택x, 1 = 선택o
										// 또한, 시도마다 선택값을 0으로 초기화시킴
		
		// 투약하는 약병의 갯수를 무작위로 선택
		// 단, 이전 투약때와 같은 수의 병이 선택되면 투약하는 약병의 수를 다시 설정
		do {
			cntShowBottle = rand() % 2 + 2; // 투약할 병 갯수뽑기 (0~1 + 2 = 2~3개)
		} while (cntShowBottle == prevCntShowBottle); // 투약수가 이전과 다르게 하기(2<->3)
		prevCntShowBottle = cntShowBottle; // 이번의 결과를 전의 결과값에 갱신/저장

		int isIncluded = 0; // 보여줄 병에 발모제가 포함되어 있는지 여부
		printf(" %d 번째 투약 : ", i);

		// 투약하는 약병의 번호 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0 ~ 3 사이의 번호 랜덤

			// 아직 선택되지 않은 병이면, 선택처리
			if (bottle[randBottle] == 0) // bottle[0~3] = {0,0,0,0}로 초기에 초기화 상태
			{
				bottle[randBottle] = 1; // randBottle에 선택된 번호의 병은 값이 {1}이 됨
				if (randBottle == treatment) // 그 선택된 병이 발모제인 경우
				{
					isIncluded = 1; 
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시 선택
			else
			{
				j--;
			}
		}

		// 사용자에게 투약시도 마다의 투약된 약의 번호와 그 결과를 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d번 ", k + 1); // 투약된 약병 번호들을 선언
			}
		}
		printf("물약을 머리에 바릅니다.\n\n");

		if (isIncluded == 1)
		{
			printf(" >> 성공! 머리가 났어요!! \n");
		}
		else
		{
			printf(" >> 실패! 머리가 나지 않았어요...ㅜㅜ\n");
		}

		printf("\n... 계속 하시려면 아무키나 누르세요 ...\n");
		getchar(); // 아무키나 눌러지면 다음으로 진행하는 함수

			
	}

	// 사용자에게 문제/질문 출력

	printf(" \n\n 발모제는 몇번 일까요? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다!\n");
	}
	else
	{
		printf("\n >> 땡! 틀렸습니다! 정답은 %d 입니다.\n", treatment + 1);
	}


	return 0;
}