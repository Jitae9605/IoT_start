#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define How_Many_Time_Play_Game 1									// 게임 반복 횟수
#define Length_of_Array 5											// 배열 길이(x)
#define Height_of_Array 5											// 배열 높이(y)
#define Over_the_Time_limit -1										// 시간제한을 넘겼을때 적용될 값
#define Succes_to_Login 1											// 로그인 성공

#define Length_of_string 20
#define id_limit 12
#define pw_limit 4
#define game 4														// 1.up/down 2.암산 3.청기백기 4.틀린그림찾기
#define max_player 10

void Print_diff_Mainmenu(void);										// 매인메뉴 출력 함수
int Cal_Score(int Set_endTime);										// 스코어 계산 함수
int Make_Random_Num(int Random_Num_Range);							// 난수출력 함수
int Make_Random_Num_Range(int from, int end);						// 특정범위의 난수 출력함수
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// 틀린그림찾기 판 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// 정답 입력받아 확인
int Print_Final_Score(int Score[How_Many_Time_Play_Game]);			// 최종점수 출력 함수

// -------------------------------------- 구조체 -----------------------------------

struct player			// 플레이어 정보관리 구조체
{
	char id[id_limit + 1];  // 아이디
	char pw[pw_limit + 1];   // 비밀번호
	int score[game];    // 게임별 점수
	int total_score;    // 통합 점수
	int join;           // 등록 순서
};

struct Curent_player			// 현재 로그인된 플레이어
{
	char id[id_limit + 1];  // 아이디
	char pw[pw_limit + 1];   // 비밀번호
	int score[game];    // 게임별 점수
	int total_score;    // 통합 점수
	int join;           // 등록 순서
};


// -------------------------------------- 매인 ----------------------------------

int main(void)
{
	// 구조체 등록
	struct player p[max_player] = { 0, };
	struct Curent_player CP = { 0, };

	// 변수선언
	char Check_id[id_limit + 1] = { 0 };
	char Check_pw[pw_limit + 1] = { 0 };
	int check_for_same = 0;
	int check_for_success_to_login = 0;

	// 랭킹시스템 확인을 위한 임시 구조체 정보입력
	for (int i = 0; i < max_player; i++)
	{
		strcpy(p[i].id, "아이디");
		strcpy(p[i].pw, "1234");
		for (int j = 0; j < pw_limit; j++)
		{
			p[i].score[j] = (1000 + ((i+1) * 100 )+ ((j+1) * 10) + ((i+1)*(j+1))) ;
			p[i].total_score += p[i].score[j];
		}
	}

	while (1)
	{
		// 로그인
		printf("아이디 입력 : ");
		scanf("%s", Check_id);

		printf("비번 입력 : ");
		scanf("%s", Check_pw);

		// 입력받은 id 와 pw가 일치하는지 확인
		for (int i = 0; i < max_player; i++)
		{
			for (int j = 0; j < id_limit; j++)
			{
				if (p[i].id[j] == Check_id[j])
				{
					check_for_same++;
				}
			}
			if (check_for_same == id_limit)	// 입력된 아이디가 존재함
			{
				check_for_same = 0;
				// 해당아이디의 pw가 입력받은 pw와 같은지 확인
				for (int k = 0; k < pw_limit; k++)
				{
					if (p[i].pw[k] == Check_pw[k])
					{
						check_for_same++;
					}
				}

				if (check_for_same == pw_limit)	// 등록된 비번도 똑같음
				{
					system("cls");
					printf("\n\t === 환영합니다. %s님 === \t\t\n", p[i].id);
					check_for_success_to_login = Succes_to_Login;

					// 현재 로그인된 플레이어로 정보를 등록(복붙)
					strcpy(CP.id, p[i].id);
					strcpy(CP.pw, p[i].pw);
					for (int j = 0; j < pw_limit; j++)
					{
						CP.score[j] = p[i].score[j];
					}
					CP.total_score = p[i].total_score;
					break;
				}
			}

			else							// 입력된 아이디가 존재하지않음
			{
				printf("Id 또는 Pw를 다시 확인하고 입력해주시기 바랍니다.");
				check_for_same = 0;
				break;
			}
		}
		
		if (check_for_success_to_login == Succes_to_Login) break;

	}

	// 난수 초기화
	srand(time(NULL));

	// 변수 선언
	int score[How_Many_Time_Play_Game] = { 0 };		// 게임 실행 별 점수
	int Final_Score = 0;							// 최종점수
	int Judg_num = 0;								// 제한시간 넘겼을 경우 최종점수 없음
	int Select_diff_main_menu = 0;					// 메뉴선택 선택지 저장
	int Select_diff_ResetMenu = 0;					// 초기화메뉴 선택지 저장
	int Select_diff_RankingMenu = 0;				// 랭킹확인메뉴 선택지 저장

	while (1)
	{
		Print_diff_Mainmenu();
		printf("원하는 메뉴의 번호를 입력하세요\n");
		scanf("%d", &Select_diff_main_menu);

		if (Select_diff_main_menu == 1)
		{
			// 1. 게임 실행부
			system("cls");
			for (int q = 0; q < How_Many_Time_Play_Game; q++)
			{

				// 걸린 시간 계산을 위한 시작시간 기록 및 초기화
				long StartTime = 0; // 게임시작 시간 초기화
				long totlaElapsedTime = 0; // 총 경과시간 초기화
				StartTime = clock(); // 게임시작 시간 기록

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
				int Whats_diffent = 0;															// 틀린 값 선언
				int Where_is_diff_x = Make_Random_Num(Length_of_Array);							// 틀린부분 x좌표
				int Where_is_diff_y = Make_Random_Num(Height_of_Array);							// 틀린부분 y좌표

				Whats_diffent = Make_Random_Num_Range(33, 126);									// 틀린 값을 난수로 받아서 생성
				while (different_array[Where_is_diff_x][Where_is_diff_y] == Whats_diffent)		// 난수로 생성된 값이 혹시 틀린부분의 좌표에 해당하는 배열부분과 같진 않는지 확인
				{
					Whats_diffent = Make_Random_Num_Range(33, 126);								// 같지 않을때 까지 반복
				}

				different_array[Where_is_diff_x][Where_is_diff_y] = Whats_diffent;				// 같지 않으니까 대입연산


				// 화면에 틀린그림 찾기 내용 출력
				Print_Bingo(original_array, different_array);									// 틀린그림찾기판 출력
				Check_Answer(Where_is_diff_x, Where_is_diff_y);									// 정답입력받아 정답인지 확인하고 안내문 출력


				score[q] = Cal_Score(StartTime);												// 점수 출력
				if (score[q] == Over_the_Time_limit)	// 제한시간 넘겼을 때 처리										
				{
					Judg_num = Over_the_Time_limit;
					break;
				}
				system("PAUSE");						// 정답 맞추고 다음으로 넘어가기전 일시정지
				system("cls");							// 화면 정리
			}

			if (Judg_num == Over_the_Time_limit)									// 제한시간 넘기면 최종점수 출력X
			{
				printf("땡! 제한시간을 넘겼습니다. 다음에 다시 도전해주세요!");			// 제한시간 넘겼을 때 출력문구
			}
			else
			{
				// 최종스코어 합산 및 출력
				Final_Score = Print_Final_Score(score);
				CP.score[3] = Final_Score;											// 플레이어 기록에 스코어 추가
				printf("\n=========================================\n");
				printf("\n%s님의 최종 점수는 %d 입니다\n", CP.id, Final_Score);
				printf("\n=========================================\n");
				system("PAUSE");						// 정답 맞추고 다음으로 넘어가기전 일시정지
				system("cls");							// 화면 정리
			}
		}
		else if (Select_diff_main_menu == 2)
		{
			// 2. 초기화
			while (1)
			{
				system("cls");
				printf("초기화 메뉴입니다. 플레이어님의 틀린그림찾기 기록을 초기화하시겠습니까?\n");
				printf(" 1. 진행 \t 2. 취소\n");
				scanf("%d", &Select_diff_ResetMenu);

				if (Select_diff_ResetMenu == 1)
				{
					CP.score[3] = 0;
					printf("초기화 되었습니다.");
					break;
				}
				else if (Select_diff_ResetMenu == 2)
				{
					break;
				}
				else
				{
					printf("잘못된 입력값입니다. 다시입력해주세요\n");
				}
			}

		}

		else if (Select_diff_main_menu == 3)
		{
			// 3. 랭킹확인
			while (1)
			{
				system("cls");
				printf("랭킹확인 메뉴입니다. 원하는 메뉴를 선택해주세요\n");
				printf("\n1. 개인랭킹 \t 2. 전체랭킹 \t 3. 뒤로\n");
				scanf("%d", &Select_diff_RankingMenu);

				if (Select_diff_RankingMenu == 1)
				{
					// 개인랭킹
					system("cls");
					printf("\n%s 님의 틀린그림찾기 기록은 %d 점입니다.\n", CP.id, CP.score[3]);
					break;
				}

				else if (Select_diff_RankingMenu == 2)
				{
					// 전체랭킹
					system("cls");
					printf("틀린그림찾기 전체랭킹 페이지입니다.\n\n");

					break;
				}

				else if (Select_diff_RankingMenu == 3)
				{
					// 뒤로
					break;
				}

				else
				{
					printf("잘못된 입력값입니다. 다시입력해주세요\n");
				}
			}

		}

		else if (Select_diff_main_menu == 4)
		{
			// 4. 뒤로
			system("cls");
			break;
		}

		else
		{
			printf("잘못된 입력값입니다. 다시입력해주세요\n");
		}
	}
	
	return 0;

}

// ------------------------ 함수 ----------------------------------------------------------



// 걸린 시간을 통한 점수 산출
// 기본을 100으로 하여 (걸린시간*2)만큼을 100에서 뺀다
int Cal_Score(int StartTime)
{
	int Score = 100;
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // 걸린 시간
	
	printf("\n걸린 시간은 %d 초 입니다.\n ", totalElapsedTime);

	Score = Score - (totalElapsedTime * 2);

	if (Score < 0)
	{
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

// 매인메뉴 출력
void Print_diff_Mainmenu(void)
{
	printf("\n===============================================\n");
	printf("\t\t 틀린 그림 찾기 \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. 도전\n\n\t\t 2. 초기화\n\n\t\t 3. 랭킹확인\n\n\t\t 4. 뒤로\n\n");
	printf("\n===============================================\n");
}