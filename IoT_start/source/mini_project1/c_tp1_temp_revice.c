#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define id_limit 12
#define pw_limit 4
#define game 4
#define max_player 10
#define How_Many_Time_Play_DiffGame 5								// 게임 반복 횟수
#define Length_of_Array 5											// 배열 길이(x)
#define Height_of_Array 5											// 배열 높이(y)
#define Over_the_Time_limit -1										// 시간제한을 넘겼을때 적용될 값
#define Succes_to_Login 1											// 로그인 성공


int loginCheck = 1; // 로그인 성공=1, 실패 또는 로그아웃=0
int Curent_id_num = 0;

struct score {   // [게임 점수 구조체]
	int upDown;  // 업다운 점수
	int cal;     // 암산 점수
	int BW;      // 청기백기 점수
	int spot;    // 틀린그림 찾기
	int total;   // 통합 점수
};

struct player {              // [플레이어 정보 관리 구조체]
	struct score sc;		 // score 구조체를 멤버로 사용
	char id[id_limit + 1];   // 아이디
	char pw[pw_limit + 1];   // 비밀번호
	int rank;                // 랭킹
	int join;                // 등록 순서
};

int start();
void join(struct player allPlayerList[]); // 플레이어 등록 함수
struct player logIn(struct player p, struct player allPlayerList[]);
int main_menu();
int rank();
void Print_diff_Mainmenu(void);										// 매인메뉴 출력 함수
int Cal_Score(int Set_endTime);										// 스코어 계산 함수
int Make_Random_Num(int Random_Num_Range);							// 난수출력 함수
int Make_Random_Num_Range(int from, int end);						// 특정범위의 난수 출력함수
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// 틀린그림찾기 판 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// 정답 입력받아 확인
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame]);	// 최종점수 출력 함수

int main() {

	// 난수 초기화
	srand((unsigned)time(NULL));

	int start_choice = 0, menu_choice = 0, rank_choice = 0, select_quit = 0;
	struct player p = { 0, }; // 플레이어 구조체 변수 선언
	struct player allPlayerList[max_player]; // 모든 플레이어 정보 저장할 구조체 배열 선언
	
	for (int i = 0; i < max_player; i++) {
		for (int j = 0; j <= id_limit; j++) {
			allPlayerList[i].id[j] = '\0';
		}
	} //플레이어 아이디 배열 null로 초기화


	// ----------------------------------------- 틀린그림찾기변수선언 -------------------------------------------------------------------------------------
	int score[How_Many_Time_Play_DiffGame] = { 0 };						// 게임 실행 별 점수
	int Final_Score = 0;												// 최종점수
	int Judg_num = 0;													// 제한시간 넘겼을 경우 최종점수 없음
	int Select_diff_main_menu = 0;										// 메뉴선택 선택지 저장
	int Select_diff_ResetMenu = 0;										// 초기화메뉴 선택지 저장
	int Select_diff_RankingMenu = 0;									// 랭킹확인메뉴 선택지 저장
	int Rank_num_diff[max_player] = { 0 };								// 전체랭킹 계산
	int Rank_num_total[max_player] = { 0 };
	int Curent_id_num = 0;												// 현재 로그인된 아이디의 번호
	int original_array[Length_of_Array][Height_of_Array] = { 0 };		// 랜덤으로 꼽힌 숫자들을 저장하는 배열
	int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original과 다른 부분을 만들어 저장할 배열
	


		//------------------ 랭킹시스템 확인을 위한 임시 구조체 정보입력 -----------------------

	for (int i = 0; i < max_player; i++)
	{
		strcpy(allPlayerList[i].pw, "0000");
		allPlayerList[i].sc.total = 0;
		allPlayerList[i].sc.upDown = (rand() % (How_Many_Time_Play_DiffGame * 100));
		allPlayerList[i].sc.cal = (rand() % (How_Many_Time_Play_DiffGame * 100));
		allPlayerList[i].sc.BW = (rand() % (How_Many_Time_Play_DiffGame * 100));
		allPlayerList[i].sc.spot = (rand() % (How_Many_Time_Play_DiffGame * 100));
		allPlayerList[i].sc.total += allPlayerList[i].sc.spot + allPlayerList[i].sc.BW + allPlayerList[i].sc.cal + allPlayerList[i].sc.upDown;
	}

	strcpy(allPlayerList[0].id, "아이디0");
	strcpy(allPlayerList[1].id, "아이디1");
	strcpy(allPlayerList[2].id, "아이디2");
	strcpy(allPlayerList[3].id, "아이디3");
	strcpy(allPlayerList[4].id, "아이디4");
	strcpy(allPlayerList[5].id, "아이디5");
	strcpy(allPlayerList[6].id, "아이디6");
	strcpy(allPlayerList[7].id, "아이디7");
	strcpy(allPlayerList[8].id, "아이디8");
	strcpy(allPlayerList[9].id, "아이디9");


	while (1) {
		start_choice = start(); // 시작화면 출력

		if (start_choice == 1) { // 로그인 선택했을 때
			p = logIn(p, allPlayerList); // 로그인 함수 호출

			if (loginCheck == 0) continue; // 등록된 아이디 없을 때 시작화면으로 돌아가기
			else { // 로그인 성공, 메인화면으로

				while (1)
				{
					menu_choice = main_menu();

					if (menu_choice == 1) {       // 업다운 게임 선택
						//업다운 게임 호출 작성하기
					}
					else if (menu_choice == 2) {  // 암산 게임 선택
						//암산 게임 호출 작성하기
					}
					else if (menu_choice == 3) {  // 청기백기 게임 선택
						//청기백기 게임 호출 작성하기
					}
					else if (menu_choice == 4) {  // 틀린그림찾기 게임 선택
						//틀린그림찾기 게임 호출 작성하기

						while (1)
						{
							Print_diff_Mainmenu();										// 메뉴 레이아웃 출력
							printf(" 원하는 메뉴의 번호를 입력하세요\n");					// 메뉴 선택
							scanf("%d", &Select_diff_main_menu);						// 사용자한테 메뉴 입력받음

							if (Select_diff_main_menu == 1)
							{
								// 1. 게임 실행부
								system("cls");

								for (int q = 0; q < How_Many_Time_Play_DiffGame; q++)			// 틀린그림찾기게임 반복횟수
								{

									// 걸린 시간 계산을 위한 시작시간 기록 및 초기화
									long StartTime = 0; // 게임시작 시간 초기화
									long totlaElapsedTime = 0; // 총 경과시간 초기화
									StartTime = clock(); // 게임시작 시간 기록

									// 랜덤 숫자 생성 및 배열에 저장
									for (int i = 0; i < 5; i++)
									{
										for (int j = 0; j < 5; j++)
										{
											original_array[i][j] = Make_Random_Num_Range(33, 126);	// 아스키 코드표상 특수문자 33 ~ 126을 랜덤 출력 (아스키 코드 출력을 통한 특수문자를 출력할 의도)
											different_array[i][j] = original_array[i][j];			// 틀린쪽에 각 내용 덮어쓰기
										}
									}

									// different_array배열에 틀린 부분을 집어 넣기
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
									Final_Score = Print_Diff_Final_Score(score);
									allPlayerList[Curent_id_num].sc.spot = Final_Score;											// 플레이어 기록에 스코어 추가
									printf("\n=========================================\n");
									printf("\n %s님의 최종 점수는 < %d > 점입니다\n", allPlayerList[Curent_id_num].id, Final_Score);
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
									printf(" 초기화 메뉴입니다. 플레이어님의 틀린그림찾기 기록을 초기화하시겠습니까?\n");
									printf(" 1. 진행 \t 2. 취소\n");
									scanf("%d", &Select_diff_ResetMenu);

									// 2.1 초기화 진행
									if (Select_diff_ResetMenu == 1)
									{
										allPlayerList[Curent_id_num].sc.spot = 0;
										printf(" 초기화 되었습니다. 초기화면으로 돌아갑니다.");
										system("PAUSE");
										system("cls");
										break;
									}

									// 2.2 뒤로
									else if (Select_diff_ResetMenu == 2)
									{
										break;
									}

									// 2.3 잘못된 값 처리
									else
									{
										printf(" 잘못된 입력값입니다. 다시입력해주세요\n");
									}
								}

							}

							else if (Select_diff_main_menu == 3)
							{
								// 3. 랭킹확인
								while (1)
								{
									system("cls");
									printf(" 랭킹확인 메뉴입니다. 원하는 메뉴를 선택해주세요\n");
									printf("\n 1. 개인랭킹 \t 2. 전체랭킹 \t 3. 뒤로\n");
									scanf("%d", &Select_diff_RankingMenu);

									if (Select_diff_RankingMenu == 1)
									{
										// 3.1 개인랭킹
										system("cls");
										printf("\n----------------------------------------------------------------\n");
										printf("\n %s 님의 틀린그림찾기 기록은 < %d > 점입니다.\n\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.spot);
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}

									else if (Select_diff_RankingMenu == 2)
									{
										// 3.2 전체랭킹
										system("cls");
										printf("\n 틀린그림찾기 전체랭킹 페이지입니다.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" 등수\t\t 아이디\t\t 점수 \n\n");

										for (int i = 0; i < max_player; i++)								// 등수 구하기
										{
											Rank_num_diff[i] = max_player + 1;											// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.spot >= allPlayerList[j].sc.spot)							// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
													Rank_num_diff[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (Rank_num_diff[j] == i + 1)
													printf(" %2d등\t %12s\t %5d\n", Rank_num_diff[j], allPlayerList[j].id, allPlayerList[j].sc.spot);

											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}

									else if (Select_diff_RankingMenu == 3)
									{
										// 3.3 뒤로
										break;
									}

									else
									{
										// 3.4 잘못된 값 처리
										printf(" 잘못된 입력값입니다. 다시입력해주세요\n");
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
								// 4.1 잘못된 값 처리
								printf(" 잘못된 입력값입니다. 다시입력해주세요\n");
							}
						}

					}
					else if (menu_choice == 5) {  // 랭킹 조회
						while (1)
						{
							rank_choice = rank();

							if (rank_choice == 1) {   // 게임별 랭킹 조회

							}
							else if (rank_choice == 2) {  // 통합 랭킹 조회
								// 통합 전체랭킹 (total)
								system("cls");
								printf("\n 통합 전체랭킹 페이지입니다.\n");
								printf("\n----------------------------------------------------------------\n");
								printf(" 등수\t\t 아이디\t\t 점수 \n\n");

								for (int i = 0; i < max_player; i++)								// 등수 구하기
								{
									Rank_num_total[i] = max_player + 1;								// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
									for (int j = 0; j < max_player; j++)
									{
										if (allPlayerList[i].sc.total >= allPlayerList[j].sc.total)	// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
											Rank_num_total[i]--;
									}
								}

								for (int i = 0; i < max_player; i++)
								{
									for (int j = 0; j < max_player; j++)
									{

										if (Rank_num_total[j] == i + 1)
											printf(" %2d등\t %12s\t\t %5d\n", Rank_num_total[j], allPlayerList[j].id, allPlayerList[j].sc.total);

									}
								}
								printf("\n----------------------------------------------------------------\n");
								system("PAUSE");
								system("cls");
								break;
							}



							else if (rank_choice == 3) {  // 다시 메인화면으로
								break;
							}
							else { // 이상한 거 눌렀을 때
								printf("잘못된 입력입니다.\n");
							}
						}
					
						
					}
					else if (menu_choice == 6) {  // 로그아웃
						printf("로그아웃되었습니다.\n");
						loginCheck = 0;
						break;
					}
					else if (menu_choice == 7) {  // 프로그램 종료
						printf("프로그램을 종료합니다.\n");
						select_quit = 1;
						break;
					}
					else { // 잘못된 선택
						printf("잘못된 입력입니다.\n");
					}
				}
				if (select_quit == 1)
				{
					break;
				}
			}
		}

		else if (start_choice == 2) { // 플레이어 등록 선택했을 때
			join(allPlayerList);
		}

		else if (start_choice == 3) { // 종료 선택했을 때
			printf("프로그램을 종료합니다.\n");
			
			break;
		}

		else printf("잘못된 입력입니다.\n"); // 1,2,3 아닌 거 입력했을 때
	}

	return 0;
}

int start() {
	int choice;

	printf("\n[미니게임천국]\n\n"); 
	printf("(1) 로그인\n");
	printf("(2) 플레이어 등록\n");
	printf("(3) 종료\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}

void join(struct player allPlayerList[]) {
	int id_check = -1;
	char id_temp[id_limit + 1] = { NULL, };
	char check_NULL[id_limit + 1] = { NULL, };

	printf("[플레이어 등록]\n\n");
	while (1) {
		printf("사용할 아이디를 입력하세요(최대 영어12글자, 한글6글자)\n");
		printf("입력 : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교

			if (id_check == 0) { // 존재하는 아이디일 때
				printf("이미 존재하는 아이디입니다.\n");
				break;
			}
		}

		if (id_check != 0) { // 생성 가능한 아이디일 때
			for (int i = 0; i < max_player; i++) {
				if (strcmp(allPlayerList[i].id,check_NULL) == 0) { // 빈자리 찾아서
					strcpy(allPlayerList[i].id, id_temp); // 빈자리에 아이디 저장
					printf("사용 가능한 아이디입니다.\n");
					printf("비밀번호를 입력하세요(4자리 숫자)\n");
					printf("입력 : ");
					scanf("%s", allPlayerList[i].pw); // 비밀번호 저장
					break;
				}
			}

			printf("등록이 완료되었습니다.\n");
			
			break;
		}
	}
}

struct player logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL };
	char pw_temp[pw_limit + 1] = { NULL };
	int id_check = -1, pw_check = -1;
	int check_id_temp = 0;

	printf("[로그인]\n\n");
	while (1) {
		printf("아이디 : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교
			if (id_check == 0) { // 존재하는 아이디일 때
				printf("비밀번호 :");
				scanf("%s", pw_temp);
				pw_check = strcmp(allPlayerList[i].pw, pw_temp); // 비번 맞는지 확인
				check_id_temp = i;
				break;
			}
		
		}

		if (id_check != 0) { // 존재하는 아이디가 아닐 때,
			printf("존재하지 않는 아이디입니다.\n");
			loginCheck = 0;
			check_id_temp = 0;
			break;
		}

		if (id_check == 0 && pw_check == 0) { // 로그인 성공
			printf("로그인되었습니다.\n");
			loginCheck = 1;
			strcpy(p.id, id_temp);
			strcpy(p.pw, pw_temp); // 구조체 변수에 아디, 비번 멤버 저장
			Curent_id_num = check_id_temp;
			//  메인메뉴 화면으로 보내주기
			break;
		}
		else if (id_check == 0 && pw_check != 0) { // 아이디 있는데 비번 틀릴 때
			printf("잘못된 비밀번호 입니다.\n");
			check_id_temp = 0;
		}
	}

	return p;
}

int main_menu() {
	int choice = 0;

	printf("[메인 메뉴]\n\n");
	printf("(1) 업다운\n");
	printf("(2) 암산\n");
	printf("(3) 청기백기\n");
	printf("(4) 틀린그림찾기\n");
	printf("(5) 랭킹 조회\n");
	printf("(6) 로그아웃\n");
	printf("(7) 프로그램 종료\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}

int rank() {
	int choice = 0;

	printf("[랭킹 조회]\n\n");
	printf("(1) 게임별 랭킹 조회\n");
	printf("(2) 통합 랭킹 조회\n");
	printf("(3) 뒤로가기\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}

// ------------------------ 틀린그림찾기 함수 ----------------------------------------------------------



// 걸린 시간을 통한 점수 산출
// 기본을 100으로 하여 (걸린시간*2)만큼을 100에서 뺀다
int Cal_Score(int StartTime)
{
	int Score = 100;					// 기본점수
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // 걸린 시간

	printf("\n걸린 시간은 %d 초 입니다.\n ", totalElapsedTime);

	Score = Score - (totalElapsedTime * 2);				// 최종 점수 = 기본점수 - (걸린시간 * 2)

	if (Score < 0)										// 스코어가 음수가 되면 실격 
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

// 틀린그림찾기 최종 스코어 출력
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame])
{
	int final_score = 0;
	for (int i = 0; i < How_Many_Time_Play_DiffGame; i++)
	{
		final_score = final_score + Score[i];
	}
	return final_score;
}

// 틀린그림찾기 매인메뉴 출력
void Print_diff_Mainmenu(void)
{
	printf("\n===============================================\n");
	printf("\t\t 틀린 그림 찾기 \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. 도전\n\n\t\t 2. 초기화\n\n\t\t 3. 랭킹확인\n\n\t\t 4. 뒤로\n\n");
	printf("\n===============================================\n");
}