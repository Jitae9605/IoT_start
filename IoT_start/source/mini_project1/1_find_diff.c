#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define How_Many_Time_Play_Game 5									// 게임 반복 횟수
#define Length_of_Array 5											// 배열 길이(x)
#define Height_of_Array 5											// 배열 높이(y)
#define Over_the_Time_limit -1										// 시간제한을 넘겼을때 적용될 값

int Cal_Score(int Set_endTime);										// 스코어 계산
int Make_Random_Num(int Random_Num_Range);							// 난수출력함수
int Make_Random_Num_Range(int from, int end);						//특정범위의 난수 출력함수
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// 틀린그림찾기 판 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// 정답 입력받아 확인
int Print_Final_Score(int Score[How_Many_Time_Play_Game]);

// -------------------------------------- 매인 ----------------------------------

int main(void)
{
	// 난수 초기화
	srand(time(NULL));
	
	// 변수 선언
	int score[How_Many_Time_Play_Game] = { 0 };
	int Final_Score = 0;
	
	// 게임 실행부
	for (int q = 0; q < How_Many_Time_Play_Game; q++)
	{

		// 걸린 시간 계산
		long StartTime = 0; // 게임시작 시간 선언
		long totlaElapsedTime = 0; // 총 경과시간 선언
		StartTime = clock(); // 게임시작 시간프 
	
		// 배열 선언
		int original_array[Length_of_Array][Height_of_Array] = { 0 };		// 랜덤으로 꼽힌 숫자들을 저장하는 배열
		int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original과 다른 부분을 만들어 저장할 배열



	// 랜덤 숫자 생성 및 배열에 저장
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				original_array[i][j] = Make_Random_Num_Range(33, 126);	// 아스키 코드표상 특수문자 33 ~ 126을 랜덤 출력 (아스키 코드 출력을 통한 특수문자를 출력할 의도)
				different_array[i][j] = original_array[i][j];			// 틀린쪽에 각 내용 덮어쓰기
			}
		}


		// different_array배열중에 틀린 부분을 집어 넣기
		int Whats_diffent = 0;												// 틀린 값 선언
		int Where_is_diff_x = Make_Random_Num(Length_of_Array);							// 틀린부분 x좌표
		int Where_is_diff_y = Make_Random_Num(Height_of_Array);							// 틀린부분 y좌표

		Whats_diffent = Make_Random_Num_Range(33, 126);						// 틀린 값을 난수로 받아서 생성
		while (different_array[Where_is_diff_x][Where_is_diff_y] == Whats_diffent)		// 난수로 생성된 값이 혹시 틀린부분의 좌표에 해당하는 배열부분과 같진 않는지 확인
		{
			Whats_diffent = Make_Random_Num_Range(33, 126);								// 같지 않을때 까지 반복
		}
	
		different_array[Where_is_diff_x][Where_is_diff_y] = Whats_diffent;				// 같지 않으니까 대입연산


		// 화면에 틀린그림 찾기 내용 출력
		Print_Bingo(original_array, different_array);									// 틀린그림찾기판 출력
		Check_Answer(Where_is_diff_x, Where_is_diff_y);									// 정답입력받아 정답인지 확인하고 안내문 출력


		score[q] = Cal_Score(StartTime);												// 점수 출력
		if (score[q] == Over_the_Time_limit)
		{
			break;
		}
		system("PAUSE");
		system("cls");
	}
	
	// 최종스코어 합산
	Final_Score = Print_Final_Score(score);
	printf("\n=========================================\n");
	printf("\n(플레이어 이름)님의 최종 점수는 %d 입니다\n", Final_Score);
	printf("\n=========================================\n");




	return 0;
}

// ------------------------ 함수 ----------------------------------------------------------



// 걸린 시간을 통한 점수 산출
// 기본을 100으로 하여 (걸린시간*2)만큼을 100에서 뺀다
int Cal_Score(int StartTime)
{
	int Score = 100;
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // 끝나는 시간
	printf("\n걸린 시간은 %d 초 입니다.\n ", totalElapsedTime);

	Score = Score - (totalElapsedTime * 2);

	if (Score < 0)
	{
		printf("땡! 제한시간을 넘겼습니다. 다음에 다시 도전해주세요!");
		Score = Over_the_Time_limit;
	}

	return Score;

}

// 난수를 출력하는 함수
// 출력되는 난수의 범위를 입력받는다.
int Make_Random_Num(int Random_Num_Range)
{
	int num;

	num = rand() % Random_Num_Range;
	return num;
}

// from ~ end 범위의 난수를 출력하는 함수
// from과 end를 포함한다.
int Make_Random_Num_Range(int from, int end)
{
	int num;

	num = rand() % (end - from + 1) + from;
	return num;
}

// 틀린그림 찾기판 출력
// 왼쪽 = 정상
// 오른쪽 = 배열중 1개의 값이 다름
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array])
{
	printf("\n==================================================================================\n\n\n");
	for (int i = 0; i < Height_of_Array; i++)
	{
		printf("\t");
		for (int j = 0; j < Length_of_Array; j++)
		{
			printf("  %c  ", original_array[i][j]);
		}
		printf("\t\t");
		for (int k = 0; k < 5; k++)
		{
			printf("  %c  ", different_array[i][k]);
		}
		printf("\t");
		printf("\n\n");
	}
	printf("\n");
	printf("\n==================================================================================\n");
}

// 정답 체크 및 안내문 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y)
{
	while (1)
	{
		int ans_x = 0;
		int ans_y = 0;
		printf("서로다른 부분의 좌표를 입력하세요(1~5)(1~5) : ");
		scanf("%d %d", &ans_x, &ans_y);

		if (ans_x - 1 == Where_is_diff_y && ans_y - 1 == Where_is_diff_x)
		{
			printf("\n ★ 정답입니다! ★ \n");
			break;
		}
		else
		{
			printf("!!! 땡! 틀렸습니다 !!!\n");
		}
	}

}

// 최종 스코어 출력
int Print_Final_Score(int Score[How_Many_Time_Play_Game])
{
	int final_score = 0;
	for (int i = 0; i < How_Many_Time_Play_Game; i++)
	{
		final_score = final_score + Score[i];
	}
	return final_score;
}

