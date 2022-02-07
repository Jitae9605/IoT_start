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
#define How_Many_Time_Play_DiffGame 5	// 게임 반복 횟수
#define Length_of_Array 5				// 배열 길이(x)
#define Height_of_Array 5				// 배열 높이(y)
#define Over_the_Time_limit -1			// 시간제한을 넘겼을때 적용될 값
#define Succes_to_Login 1				// 로그인 성공
#define Amsan_count 3					// 암산 stageNUM

int loginCheck = 1;						// 로그인 성공=1, 실패 또는 로그아웃=0
int Curent_id_num = 0;					// 현재 로그인된 아이디의 번호

int front = -1, rear = -1;				// 원형 큐에 사용할 front, rear
int Rank_num_total[max_player] = { 0 };


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

int start(); // 시작화면 함수
void join(struct player allPlayerList[]); // 플레이어 등록 함수
int logIn(struct player p, struct player allPlayerList[]); // 로그인 함수
int main_menu(); // 메인메뉴 함수
int isFull(); // 원형 큐가 다 찼는지 판별하는 함수

int isFull() {
	int temp = (rear + 1) % (max_player + 1); // 원형 큐에서 rear+1을 배열크기로 나눈 나머지값이
	if (temp == front) return 1; // front와 같으면 큐는 가득 차있는 상태
	else return 0;
}

// ----------------------------------------- 틀린그림찾기 함수선언 ----------------------------------------------------------------
void Print_diff_Mainmenu(void);										// 매인메뉴 출력 함수
int Cal_Score(int Set_endTime);										// 스코어 계산 함수
int Make_Random_Num(int Random_Num_Range);							// 난수출력 함수
int Make_Random_Num_Range(int from, int end);						// 특정범위의 난수 출력함수
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// 틀린그림찾기 판 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// 정답 입력받아 확인
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame]);	// 최종점수 출력 함수

// ----------------------------------------- 암산 함수선언 --------------------------------------------------------------------
int RandNum1(int i);
int RandNum2(int i);
int Calc(Num1, Num2);
int InsertDap(void);
int Print(int i);
int Game(int i);
void StartMenu();
void End_Menu();

// ----------------------------------------- updown함수선언 --------------------------------------------------------------------
int upDown_menu(void); // updown 메인메뉴
int game1(void);		   // updown 함수


int main1212() {
	srand((unsigned)time(NULL)); // 난수 초기화

	int start_choice = 0, menu_choice = 0, rank_choice = 0, select_quit = 0;
	struct player p = { 0, }; // 플레이어 구조체 변수 선언
	struct player allPlayerList[max_player + 1] = { 0, }; // 모든 플레이어 정보 저장할 구조체 배열 선언


	for (int i = 0; i < max_player; i++) {
		strcpy(allPlayerList[i].id, "EMPTY");
		strcpy(allPlayerList[i].pw, "0000");
		
		 //플레이어 아이디, 비번 배열초기화
	}


	// ----------------------------------------- 틀린그림찾기변수선언 -------------------------------------------------------------------------------------
	int score[How_Many_Time_Play_DiffGame] = { 0 };						// 게임 실행 별 점수
	int Final_Score = 0;												// 최종점수
	int Judg_num = 0;													// 제한시간 넘겼을 경우 최종점수 없음
	int Select_diff_main_menu = 0;										// 메뉴선택 선택지 저장
	int Select_diff_ResetMenu = 0;										// 초기화메뉴 선택지 저장
	int Select_diff_RankingMenu = 0;									// 랭킹확인메뉴 선택지 저장
	int Rank_num_diff[max_player] = { 0 };								// 전체랭킹 계산
	

	int original_array[Length_of_Array][Height_of_Array] = { 0 };		// 랜덤으로 꼽힌 숫자들을 저장하는 배열
	int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original과 다른 부분을 만들어 저장할 배열

	// ----------------------------------------- 업다운 변수선언 -------------------------------------------------------------------------------------
	int upDown_choice = 0;
	int game1_rank_num[max_player] = { 0 };
	int game1_score = 0;

	// ----------------------------------------- 청기백기 변수선언 -------------------------------------------------------------------------------------
	int choice = 0;
	int sumscore = 0;
	int player = -55;
	int player1 = -55;
	int player2 = -55;
	int player3 = -55;

	int com = 0;
	int com1 = 0;
	int com2 = 0;
	int com3 = 0;

	int score0 = 0;
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;

	while (1) {
		start_choice = start(); // 시작화면 출력

		if (start_choice == 1) { // 로그인 선택했을 때
			Curent_id_num = logIn(p, allPlayerList); // 로그인 함수 호출

			if (loginCheck == 0) continue; // 등록된 아이디 없을 때 시작화면으로 돌아가기
			else { // 로그인 성공, 메인화면으로
				while (1){
					menu_choice = main_menu();

					if (menu_choice == 1) { // 업다운 게임 선택했을 때
						while (1){
							upDown_choice = upDown_menu(); // updown 메인메뉴 호출
							
							if (upDown_choice == 1){
								// 게임 시작 전 설명 출력
								system("cls");
								printf("\n===============================================\n");
								printf("\n 10초 동안 랜덤으로 나오는 숫자 중 화면에 \n");
								printf("\n 표시된대로 가장 큰 수나 작은 수를 입력하세요. \n");
								printf("\n===============================================\n");
								Sleep(2000);
								system("cls");

								int sec = 3;
								// 게임 시작 전 대기
								for (sec; sec > 0; sec--)
								{
									printf("\n 게임시작 %d초전..", sec);
									Sleep(1000);
									system("cls");
								}

								game1_score = game1();															// 첫번째게임 실행 후 game1_final_score에 점수 저장
								allPlayerList[Curent_id_num].sc.upDown = game1_score;								// 플레이어 기록에 스코어 추가
								printf("\n=========================================\n");
								printf("\n%s님의 최종 점수는 %d 입니다\n", allPlayerList[Curent_id_num].id, game1_score);	// 점수 출력
								printf("\n=========================================\n");
								system("pause");
								system("cls");
							}
							// 2. 초기화
							else if (upDown_choice == 2)
							{

								while (1)
								{
									int Select_UpDown_ResetMenu = 0;
									system("cls");
									printf("초기화 메뉴입니다. 플레이어님의 Up / Down 기록을 초기화 하시겠습니까?\n");
									printf(" 1. 진행 \t 2. 취소\n");
									scanf("%d", &Select_UpDown_ResetMenu);

									// 2.1 초기화 진행
									if (Select_UpDown_ResetMenu == 1)
									{
										allPlayerList[Curent_id_num].sc.upDown = 0;
										printf("초기화 되었습니다.");
										break;
									}

									// 2.2 뒤로
									else if (Select_UpDown_ResetMenu == 2)
									{
										break;
									}

									// 2.3 잘못된 값 처리
									else
									{
										printf("잘못된 입력 값 입니다. 다시 입력 해주세요\n");
									}
								}
							}
							// 3. 랭킹확인
							else if (upDown_choice == 3)
							{
								while (1)
								{
									int Select_UpDown_RankingMenu = 0;
									system("cls");
									printf("\n랭킹확인 메뉴입니다. 원하는 메뉴를 선택 해주세요\n");
									printf("\n1. 개인랭킹 \t 2. 전체랭킹 \t 3. 뒤로\n");
									scanf("%d", &Select_UpDown_RankingMenu);

									// 3.1 개인랭킹
									if (Select_UpDown_RankingMenu == 1)
									{
										system("cls");
										printf("\n===============================================\n");
										printf("\nUp / Down 개인랭킹 페이지 입니다.\n\n");
										printf("\n\n%s 님의 Up / Down 기록은 %d 점 입니다.\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.upDown);
										printf("\n===============================================\n");
										system("PAUSE");
										system("cls");
										break;
									}
									// 3.2 전체랭킹
									else if (Select_UpDown_RankingMenu == 2)
									{
										system("cls");
										printf("\nUp / Down 전체랭킹 페이지 입니다.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" 등수\t 아이디\t\t 점수 \n\n");

										for (int i = 0; i < max_player; i++)					// 등수 구하기
										{
											game1_rank_num[i] = max_player + 1;					// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.upDown >= allPlayerList[j].sc.upDown)				// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
													game1_rank_num[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (game1_rank_num[j] == i + 1) {
													char temp[10] = "EMPTY";
													int id_check = -1;
													id_check = strcmp(allPlayerList[j].id, temp);
													if (id_check != 0) printf(" %2d등\t %12s\t %5d\n", game1_rank_num[j], allPlayerList[j].id, allPlayerList[j].sc.upDown);
												}
											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}
									// 3.3 뒤로
									else if (Select_UpDown_RankingMenu == 3)
									{

										break;
									}
									// 3.4 잘못된 값 처리
									else
									{

										printf("\n잘못된 입력 값 입니다. 다시 입력 해주세요\n");
									}
								}

							}
							// 4. 뒤로
							else if (upDown_choice == 4)
							{
								system("cls");
								break;
							}
							// 4.1 잘못된 값 처리
							else
							{

								printf("\n잘못된 입력 값 입니다. 다시 입력 해주세요\n");
							}
						}
					}

					else if (menu_choice == 2) {  // 암산 게임 선택
						//암산 게임 호출 작성하기
						while (1)
						{
							int act = 0;
							int act2 = 0;
							int i = 0;
							StartMenu(); ///시작 메뉴 함수 호출
							scanf("%d", &act); // 사용자 메뉴 입력

							if (act == 1) //////암산 게임 시작
							{

								int score[Amsan_count] = { 0 };
								int Score = 0;
								for (i = 1; i < Amsan_count; i++)
								{
									score[i] = Game(i);
									Score += score[i];
									printf("총 점수는 %d입니다.\n", Score);
								}
								allPlayerList[Curent_id_num].sc.cal = Score;
							}

							else if (act == 2)  ///암산게임 점수 초기화
							{
								int Select_cal_ResetMenu = 0;
								system("cls");
								printf("초기화");
								printf(" 1. 진행 \t 2. 취소\n");
								scanf("%d", &Select_cal_ResetMenu);

								// 2.1 초기화 진행
								if (Select_cal_ResetMenu == 1)
								{
									allPlayerList[Curent_id_num].sc.cal = 0;
									printf(" 초기화 되었습니다. 초기화면으로 돌아갑니다.");
									system("PAUSE");
									system("cls");
								}

								// 2.2 뒤로
								else if (Select_cal_ResetMenu == 2)
								{
									break;
								}

								// 2.3 잘못된 값 처리
								else
								{
									printf(" 잘못된 입력값입니다. 다시입력해주세요\n");
								}

							}

							else if (act == 3) //////암산 게임 랭킹 확인

							{
								int Rank_num_cal[max_player] = { 0 };
								system("cls");
								printf("\n 암산 전체랭킹 페이지입니다.\n");
								printf("\n----------------------------------------------------------------\n");
								printf(" 등수\t 아이디\t\t 점수 \n\n");

								for (int i = 0; i < max_player; i++)								// 등수 구하기
								{
									Rank_num_cal[i] = max_player + 1;											// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
									for (int j = 0; j < max_player; j++)
									{
										if (allPlayerList[i].sc.cal >= allPlayerList[j].sc.cal)							// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
											Rank_num_cal[i]--;
									}
								}

								for (int i = 0; i < max_player; i++)
								{
									for (int j = 0; j < max_player; j++)
									{
										
										if (Rank_num_cal[j] == i + 1) {
											char temp[10] = "EMPTY";
											int id_check = -1;
											id_check = strcmp(allPlayerList[j].id, temp);
											if (id_check != 0) printf(" %2d등\t %12s\t %5d\n", Rank_num_cal[j], allPlayerList[j].id, allPlayerList[j].sc.cal);
										}

									}
								}
								printf("\n----------------------------------------------------------------\n");
								system("PAUSE");
								system("cls");

							}

							else if (act == 4)  //////암산게임 시작메뉴에서 뒤로가기
							{
								printf("뒤로가기");
								break;
							}


							End_Menu();  //////암산 게임 후 뜨는 메뉴 함수
							scanf("%d", &act2);

							if (act2 == 1) ///////암산게임 재도전
							{
								int score[Amsan_count] = { 0 };
								int Score = 0;
								for (int i = 1; i < Amsan_count; i++)
								{
									score[i] = Game(i);
									Score += score[i];
									printf("총 점수는 %d입니다.\n", Score);
								}
								allPlayerList[Curent_id_num].sc.cal = Score;
							}

							else if (act2 == 2) /////암산게임 점수 초기화
							{
								int Select_cal_ResetMenu2 = 0;
								system("cls");
								printf("초기화");
								printf(" 1. 진행 \t 2. 취소\n");
								scanf("%d", &Select_cal_ResetMenu2);

								// 2.1 초기화 진행
								if (Select_cal_ResetMenu2 == 1)
								{
									allPlayerList[Curent_id_num].sc.cal = 0;
									printf(" 초기화 되었습니다. 초기화면으로 돌아갑니다.");
									system("PAUSE");
									system("cls");
								}

								// 2.2 뒤로
								else if (Select_cal_ResetMenu2 == 2)
								{
									break;
								}

								// 2.3 잘못된 값 처리
								else
								{
									printf(" 잘못된 입력값입니다. 다시입력해주세요\n");
								}
							}

							else if (act == 3) /////암산게임 랭킹확인
							{
								while (1)
								{
									int Select_cal_RankingMenu = 0;
									system("cls");
									printf(" 랭킹확인 메뉴입니다. 원하는 메뉴를 선택해주세요\n");
									printf("\n 1. 개인랭킹 \t 2. 전체랭킹 \t 3. 뒤로\n");
									scanf("%d", &Select_cal_RankingMenu);

									if (Select_cal_RankingMenu == 1)
									{
										// 3.1 개인랭킹
										system("cls");
										printf("\n----------------------------------------------------------------\n");
										printf("\n %s 님의 암산게임 기록은 < %d > 점입니다.\n\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.cal);
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}

									else if (Select_cal_RankingMenu == 2)
									{
										// 3.2 전체랭킹
										system("cls");
										printf("\n 암산 전체랭킹 페이지입니다.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" 등수\t 아이디\t\t 점수 \n\n");
										int Rank_num_cal[max_player] = { 0 };

										for (int i = 0; i < max_player; i++)								// 등수 구하기
										{
											Rank_num_cal[i] = max_player + 1;											// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.cal >= allPlayerList[j].sc.cal)							// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
													Rank_num_cal[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (Rank_num_cal[j] == i + 1) {
													char temp[10] = "EMPTY";
													int id_check = -1;
													id_check = strcmp(allPlayerList[j].id, temp);
													if (id_check != 0) printf(" %2d등\t %12s\t %5d\n", Rank_num_cal[j], allPlayerList[j].id, allPlayerList[j].sc.cal);
												}
											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
									}

									else if (Select_cal_RankingMenu == 3)
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

							else if (act == 4) /////암산게임에서 뒤로가기
							{
								printf("뒤로가기");
								break;
							}
						}
					}

					// 청기백기 게임
					else if (menu_choice == 3) {  
						//청기백기 게임 호출 작성하기
						while (1)
						{
							printf("                               ----- 청기 백기 게임 입니다 -----\n");
							printf("                   화면에 등장하는 지시에 맞춰 답을 입력 후 ENTER를 눌러주세요\n");
							printf("\n");
							printf("                                           규칙                \n");
							printf("                                     1.청기 올려 - 1번\n");
							printf("                                     2.청기 내려 - 2번\n");
							printf("                                     3.백기 올려 - 3번\n");
							printf("                                     4.백기 내려 - 4번\n");
							printf("\n");


							int NUM3 = 0;   
							int BW_Select_Quit = 0;// 정수형 NUM3 초기화
							printf("                   *1번 : 게임시작\n");
							printf("                   *2번 : 뒤로가기\n");
							printf("                   *3번 : 랭킹확인\n");
							scanf("%d", &NUM3);


							if (NUM3 == 1)                                                     // 1일때 게임을 시작
							{
								printf("                                게임을 시작합니다\n");
								//점수 계산
								int FinishTime = (unsigned)time(NULL);                         //끝나는 시간을 양수로 정의
								FinishTime += 15;                                              //끝나는 시간 30초

								char Coma[4][35] = { "청기올려","청기내려","백기올려","백기내려" }; /// 1,2,3,4
								char Comb[4][35] = { "백기 올리지 말고 청기 올려","청기 올리지 말고 내려","백기 내리지 말고 백기 올려","청기 내리지 말고 백기 내려" }; /// 1,2,3,4
								char Comc[4][35] = { "청기 내리지 말고 올려","백기 올리지 말고 청기 내려","청기 올리지 말고 백기 올려","청기 올리지 말고 백기 내려" }; /// 1,2,3,4
								char Comd[4][35] = { "백기 내리지 말고 청기 올려","백기 내리지 말고 청기 내려","청기 내리지 말고 백기 올려","청기 내리지 말고 백기 내려" }; /// 1,2,3,4

								srand((unsigned int)time(NULL));                            //매번 다른 값을 적용


								while (1)
								{
									system("cls");													//화면을 지움
									int StartTime = (unsigned)time(NULL);							//시작시간 while에 적용되어 점차 시간이 증가
									printf("%d초\n", FinishTime - StartTime);						//종료시간에서 현재까지 흐른 시간을 뺌
									Sleep(1);														//시간을 0.01초 지연   


									if (com - player == 0)
									{
										score0 = score0 + 10;
									}
									if (com1 - player1 == 0)
									{
										score1 = score1 + 10;
									}
									if (com2 - player2 == 0)
									{
										score2 = score2 + 10;
									}
									if (com3 - player3 == 0)
									{
										score3 = score3 + 10;
									}

									if (FinishTime - StartTime <= 0)                             // 시간 초과로 인한 게임 종료
									{
										printf("종료되었습니다.\n");
										break;
									}
									//rand함수 범위 0~32767
									com = rand() % 4 + 1;
									com1 = rand() % 4 + 1;
									com2 = rand() % 4 + 1;
									com3 = rand() % 4 + 1;                                  //컴퓨터가 청기 백기 랜덤으로 인출해야 되는 문장

									if (com == 1)										//컴퓨터와 플레이어 값을 비교                          
									{
										printf("%s\n", Coma[0]);
										printf("플레이어 선택:");
										scanf("%d", &player);
									}
									else if (com == 2)
									{
										printf("%s\n", Coma[1]);
										printf("플레이어 선택:");
										scanf("%d", &player);
									}
									else if (com == 3)
									{
										printf("%s\n", Coma[2]);
										printf("플레이어 선택:");
										scanf("%d", &player);
									}
									else if (com == 4)
									{
										printf("%s\n", Coma[3]);
										printf("플레이어 선택:");
										scanf("%d", &player);
									}


									if (com1 == 1)										//컴퓨터와 플레이어 값을 비교                          
									{
										printf("%s\n", Comb[0]);
										printf("플레이어 선택:");
										scanf("%d", &player1);
									}
									else if (com1 == 2)
									{
										printf("%s\n", Comb[1]);
										printf("플레이어 선택:");
										scanf("%d", &player1);
									}
									else if (com1 == 3)
									{
										printf("%s\n", Comb[2]);
										printf("플레이어 선택:");
										scanf("%d", &player1);
									}
									else if (com1 == 4)
									{
										printf("%s\n", Comb[3]);
										printf("플레이어 선택:");
										scanf("%d", &player1);
									}



									if (com2 == 1)										//컴퓨터와 플레이어 값을 비교                          
									{
										printf("%s\n", Comc[0]);
										printf("플레이어 선택:");
										scanf("%d", &player2);
									}
									else if (com2 == 2)
									{
										printf("%s\n", Comc[1]);
										printf("플레이어 선택:");
										scanf("%d", &player2);
									}
									else if (com2 == 3)
									{
										printf("%s\n", Comc[2]);
										printf("플레이어 선택:");
										scanf("%d", &player2);
									}
									else if (com2 == 4)
									{
										printf("%s\n", Comc[3]);
										printf("플레이어 선택:");
										scanf("%d", &player2);
									}

									if (com3 == 1)										//컴퓨터와 플레이어 값을 비교                          
									{
										printf("%s\n", Comd[0]);
										printf("플레이어 선택:");
										scanf("%d", &player3);
									}
									else if (com3 == 2)
									{
										printf("%s\n", Comd[1]);
										printf("플레이어 선택:");
										scanf("%d", &player3);
									}
									else if (com3 == 3)
									{
										printf("%s\n", Comd[2]);
										printf("플레이어 선택:");
										scanf("%d", &player3);
									}
									else if (com3 == 4)
									{
										printf("%s\n", Comd[3]);
										printf("플레이어 선택:");
										scanf("%d", &player3);
									}

									else
									{
										printf("잘못된 값입니다");
									}


								}

								sumscore = score0 + score1 + score2 + score3;
								printf("당신의 총 점수는:%d점입니다", sumscore);
								allPlayerList[Curent_id_num].sc.BW = sumscore;

							}
							else if (NUM3 == 2)                                                  // 2일때 게임을 종료
							{
								printf("게임을 종료합니다\n");
								BW_Select_Quit = 1;
								system("PAUSE");
								system("cls");
								break;
							}

							else if (NUM3 == 3)
							{
								// 3. 랭킹확인
								while (1)
								{
									int Select_BW_RankingMenu = 0;
									system("cls");
									printf(" 랭킹확인 메뉴입니다. 원하는 메뉴를 선택해주세요\n");
									printf("\n 1. 개인랭킹 \t 2. 전체랭킹 \t 3. 뒤로\n");
									scanf("%d", &Select_BW_RankingMenu);

									if (Select_BW_RankingMenu == 1)
									{
										// 3.1 개인랭킹
										system("cls");
										printf("\n----------------------------------------------------------------\n");
										printf("\n %s 님의 청기백기 기록은 < %d > 점입니다.\n\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.BW);
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
									}

									else if (Select_BW_RankingMenu == 2)
									{
										int Rank_num_BW[max_player] = { 0 };
										// 3.2 전체랭킹
										system("cls");
										printf("\n 청기백기 전체랭킹 페이지입니다.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" 등수\t\t 아이디\t\t 점수 \n\n");

										for (int i = 0; i < max_player; i++)								// 등수 구하기
										{
											Rank_num_BW[i] = max_player + 1;											// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.BW >= allPlayerList[j].sc.BW)							// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
													Rank_num_BW[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (Rank_num_BW[j] == i + 1) {
													char temp[10] = "EMPTY";
													int id_check = -1;
													id_check = strcmp(allPlayerList[j].id, temp);
													if (id_check != 0)
														printf(" %2d등\t %12s\t %5d\n", Rank_num_BW[j], allPlayerList[j].id, allPlayerList[j].sc.BW);
												}
											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
									}

									else if (Select_BW_RankingMenu == 3)
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

							if (BW_Select_Quit == 1)
							{
								break;
							}

						}
					}
						

					// 틀린그림찾기 게임 선택
					else if (menu_choice == 4) {  
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

												if (Rank_num_diff[j] == i + 1) {
													char temp[10] = "EMPTY";
													int id_check = -1;
													id_check = strcmp(allPlayerList[j].id, temp);
													if (id_check != 0) {
														printf(" %2d등\t %12s\t %5d\n", Rank_num_diff[j], allPlayerList[j].id, allPlayerList[j].sc.spot);
													}
												}
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
						
					// 통합 랭킹 조회
					else if (menu_choice == 5) {  
					allPlayerList[Curent_id_num].sc.total = allPlayerList[Curent_id_num].sc.spot + allPlayerList[Curent_id_num].sc.BW + allPlayerList[Curent_id_num].sc.cal + allPlayerList[Curent_id_num].sc.upDown;
						while (1){
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

							for (int i = 0; i < max_player; i++){
								for (int j = 0; j < max_player; j++){
									if (Rank_num_total[j] == i + 1) {
										char temp[10] = "EMPTY";
										int id_check = -1;
										id_check = strcmp(allPlayerList[j].id, temp);
										if (id_check != 0) printf(" %2d등\t %12s\t\t %5d\n", Rank_num_total[j], allPlayerList[j].id, allPlayerList[j].sc.total);
									}
								}
							}
							printf("\n----------------------------------------------------------------\n");
							system("PAUSE");
							system("cls");
							break;
							}
						}
					

					else if (menu_choice == 6) {  // 로그아웃
						printf("로그아웃되었습니다.\n");
						loginCheck = 0;
						Curent_id_num = 0;
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
	


// ------------------------ 로그인 및 메인메뉴 함수 ---------------------------------------------------------
int start() {
	int choice;

	printf("\n [미니게임천국]\n\n"); 
	printf(" (1) 로그인\n");
	printf(" (2) 플레이어 등록\n");
	printf(" (3) 종료\n");
	printf(" 입력 : ");
	scanf(" %d", &choice);

	return choice;
}

void join(struct player allPlayerList[]) {
	int id_check = -1;
	char id_temp[id_limit + 1] = { NULL, };

	printf("[플레이어 등록]\n\n");
	while (1) {
		printf(" 사용할 아이디를 입력하세요(최대 영어12글자, 한글6글자)\n");
		printf(" 입력 : ");
		scanf(" %s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교

			if (id_check == 0) { // 존재하는 아이디일 때
				printf(" 이미 존재하는 아이디입니다.\n");
				break;
			}
		}

		if (id_check != 0) { // 생성 가능한 아이디일 때
			if (isFull()) { // 큐가 다 차있을 때 
				front = (front + 1) % (max_player + 1); // delete queue(FIFO)
			}
			else { // 큐가 다 차있지 않을 때
				rear = (rear + 1) % (max_player + 1); // 빈자리로 이동
			}

			strcpy(allPlayerList[rear].id, id_temp); // add queue (빈자리에 아이디 저장)
			printf("사용 가능한 아이디입니다.\n");
			printf("비밀번호를 입력하세요(4자리 숫자)\n");
			printf("입력 : ");
			scanf("%s", allPlayerList[rear].pw); // 비밀번호 저장
			printf("등록이 완료되었습니다.\n");
			break;
		}
	}
}

int logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL, };
	char pw_temp[pw_limit + 1] = { NULL, };
	int id_check = -1, pw_check = -1;
	int check_id_temp = 0;

	printf(" [로그인]\n\n");
	while (1) {
		printf(" 아이디 : ");
		scanf(" %s", id_temp);

		for (int i = 0; i < max_player + 1; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교
			if (id_check == 0) { // 존재하는 아이디일 때
				printf(" 비밀번호 :");
				scanf(" %s", pw_temp);
				pw_check = strcmp(allPlayerList[i].pw, pw_temp); // 비번 맞는지 확인
				check_id_temp = i;
				break;
			}
		}

		if (id_check != 0) { // 존재하는 아이디가 아닐 때,
			printf(" 존재하지 않는 아이디입니다.\n");
			loginCheck = 0;
			check_id_temp = 0;
			break;
		}

		if (id_check == 0 && pw_check == 0) { // 로그인 성공
			printf(" 로그인되었습니다.\n");
			loginCheck = 1;
			strcpy(p.id, id_temp);
			strcpy(p.pw, pw_temp); // 구조체 변수에 아디, 비번 멤버 저장
			Curent_id_num = check_id_temp;
			//  메인메뉴 화면으로 보내주기
			break;
		}
		else if (id_check == 0 && pw_check != 0) { // 아이디 있는데 비번 틀릴 때
			printf(" 잘못된 비밀번호 입니다.\n");
			check_id_temp = 0;
		}
	}

	return Curent_id_num;
}

int main_menu() {
	int choice = 0;

	printf(" [메인 메뉴]\n\n");
	printf(" (1) 업다운\n");
	printf(" (2) 암산\n");
	printf(" (3) 청기백기\n");
	printf(" (4) 틀린그림찾기\n");
	printf(" (5) 랭킹 조회\n");
	printf(" (6) 로그아웃\n");
	printf(" (7) 프로그램 종료\n");
	printf(" 입력 : ");
	scanf(" %d", &choice);

	return choice;
}


// ------------------------ 틀린그림찾기 함수정의 ----------------------------------------------------------
// 걸린 시간을 통한 점수 산출
// 기본을 100으로 하여 (걸린시간*2)만큼을 100에서 뺀다
int Cal_Score(int StartTime)
{
	int Score = 100;					// 기본점수
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // 걸린 시간

	printf("\n 걸린 시간은 %d 초 입니다.\n ", totalElapsedTime);

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
	printf("\n ==================================================================================\n\n\n");
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
	printf("\n ==================================================================================\n");
}

// 정답 체크 및 안내문 출력
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y)
{
	while (1)
	{
		int ans_x = 0;
		int ans_y = 0;
		printf(" 서로다른 부분의 좌표를 입력하세요(1~5)(1~5) : ");
		scanf(" %d %d", &ans_x, &ans_y);

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
	printf("\n ===============================================\n");
	printf("\t\t 틀린 그림 찾기 \t\t");
	printf("\n ===============================================\n");
	printf("\n\t\t 1. 도전\n\n\t\t 2. 초기화\n\n\t\t 3. 랭킹확인\n\n\t\t 4. 뒤로\n\n");
	printf("\n ===============================================\n");
}

//--------------------------암산게임 함수---------------------------------------------------------------


int RandNum1(int i) //랜덤으로 숫자 뽑아주는 함수1
{
	srand((unsigned)time(0));
	int Num1 = (rand() % (10 * i)) + 1; //연산할 랜덤 숫자1

	if (i >= 4)
	{
		int Num1 = (rand() % (100 * (i - 3))) + 1; //연산할 랜덤 숫자1
	}
	else if (i >= 6)
	{
		int Num1 = (rand() % (1000 * (i - 5))) + 1; //연산할 랜덤 숫자1
	}
	return Num1;
}

int RandNum2(int i) //랜덤으로 숫자 뽑아주는 함수2
{
	srand((unsigned)time(NULL));
	int Num2 = (rand() % 10 * i) + 1; // 연산할 랜덤 숫자2

	if (i >= 3)
	{
		int Num1 = (rand() % (100 * (i - 2))) + 1; //연산할 랜덤 숫자1
	}
	else if (i >= 5)
	{
		int Num1 = (rand() % (1000 * (i - 4))) + 1; //연산할 랜덤 숫자1
	}
	return Num2;
}



int Calc(Num1, Num2) //4칙연산자 랜덤으로 봅는 함수
{
	int calc = (Num1 + Num2) % 4; // 랜덤 두수를 더해서 나머지로 사칙연산자 뽑기
	int RealDap;// 정답
	switch (calc) {

	case 0:
		printf("%d + %d = \n", Num1, Num2);
		RealDap = Num1 + Num2;
		break;

	case 1:
		printf("%d - %d = \n", Num1, Num2);
		RealDap = Num1 - Num2;
		break;

	case 2:
		printf("%d * %d = \n", Num1, Num2);
		RealDap = Num1 * Num2;
		break;

	case 3:
		printf("%d / %d = \n", Num1, Num2);
		RealDap = Num1 / Num2;
		break;
	}
	return RealDap;
}

int InsertDap(void) //유저 답 입력 함수
{
	int Dap;
	printf("답을 입력하시오:");
	scanf("%d", &Dap);
	return Dap;
}

int Print(int i) //채점 후 출력함수
{
	int Num1 = RandNum1(i);
	int Num2 = RandNum2(i);

	int RealDap = Calc(Num1, Num2);
	int Dap = InsertDap();

	int score = 0;

	if (Dap == RealDap)
	{
		printf("\n ****** 정답입니다 *******\n");
		score++;
	}
	else
	{
		printf("\n ****** 오답입니다 *******\n");
		score--;
	}
	return score;
}



int Game(int i) // 단계별 게임 실행 함수
{
	system("cls");
	printf("\t -----------\n");
	printf("\t  |  Stage %d  |\n", i);
	printf("\t -----------\n");

	int endTime = (unsigned)time(NULL);
	endTime += 5;

	int score[Amsan_count] = { 0 };

	while (1)
	{
		int startTime = (unsigned)time(NULL);

		printf("\n -------------------------- \n");
		printf("\t%d 초\n", endTime - startTime);
		printf(" ------------------------- \n");


		score[i] += Print(i);


		if (endTime - startTime <= 0)
		{
			printf("\n ////////////////////////////\n");
			printf(" /////////TIME OVER//////////\n");
			printf(" ///////////////////////////\n");

			printf(" -------------------------\n");
			printf(" %d단계 점수는 %d입니다.\n", i, score[i]);
			printf(" -------------------------\n");

			Sleep(5000);

			return score[i];

			break;
		}
	}
}

void StartMenu() //암산게임 시작 전 나오는 메뉴 함수

{

	printf("\n --------------------------\n");

	printf("\t(1)도전\n");

	printf("\t(2)초기화\n");

	printf("\t(3)랭킹확인\n");

	printf("\t(4)뒤로가기");

	printf("\n --------------------------\n");

}


void End_Menu() ////암산게임 게임 종료후 나오는 메뉴 함수

{

	printf("\n --------------------------\n");

	printf("\t(1)재도전\n");

	printf("\t(2)초기화\n");

	printf("\t(3)랭킹확인\n");

	printf("\t(4)뒤로가기");

	printf("\n --------------------------\n");

}


// ----------------------------------------- updown 함수정의 --------------------------------------------------------------------
int upDown_menu() { // updown 메인메뉴 출력
	int choice = 0;

	printf("\n\n ===============================================\n");
	printf("\t\t Up / Down \t\t");
	printf("\n ===============================================\n");
	printf("\n\t\t 1. 도전\n\n\t\t 2. 초기화\n\n\t\t 3. 랭킹 확인\n\n\t\t 4. 뒤로\n");
	printf("\n ===============================================\n");

	printf("원하는 메뉴의 번호를 입력 하세요\n");
	scanf("%d", &choice);

	return choice;
}

// updown 함수
int game1(void){
	int num1 = 0;														// 숫자1
	int num2 = 0;														// 숫자2
	int num3 = 0;														// 숫자3 
	int num4 = 0;														// 숫자4 
	int num5 = 0;														// 숫자5
	int answer = 0;														// 정답 입력
	int	max = 0;														// 최대값 저장
	int min = 0;														// 최소값 저장
	int score = 0;														// 점수 저장

	srand((unsigned)time(0));														//난수 초기화

	clock_t old_time, cur_time;											// 시간 제한 변수

	old_time = clock();
	// 10초동안 게임반복
	while (1)
	{
		// 0점일 때 2자리 숫자 두개 중 큰 수 고르기
		if (score == 0)
		{
			printf("\n 큰 수를 입력하세요! \n\n");
			num1 = rand() % 100 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 100 + 1;
			printf(" %5d \n\n", num2);

			max = (num1 > num2) ? num1 : num2;

			scanf("\n%d", &answer);
			if (max == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 10점일 때 3자리 숫자 2개 중 작은 수 고르기
		else if (score == 10)
		{
			printf("\n 작은 수를 입력하세요! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf(" %5d \n\n", num2);

			min = (num1 < num2) ? num1 : num2;

			scanf("\n %d", &answer);
			if (min == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 20점일 때 3자리 숫자 3개 중 작은 수 고르기
		else if (score == 20)
		{
			printf("\n 작은 수를 입력하세요! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 1000 + 1;
			printf(" %5d \n\n", num3);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;

			scanf("\n %d", &answer);
			if (min == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 30점일 때 3자리 숫자 3개 중 큰 수 고르기
		else if (score == 30)
		{
			printf("\n 큰 수를 입력하세요! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t %d ", num1);
			num2 = rand() % 1000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 1000 + 1;
			printf(" %5d \n\n", num3);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;

			scanf("\n %d", &answer);
			if (max == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 40점일 때 3자리 숫자 4개 중 작은 수 고르기
		else if (score == 40)
		{
			printf("\n 작은 수를 입력하세요! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t %d ", num1);
			num2 = rand() % 1000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 1000 + 1;
			printf(" %5d ", num3);
			num4 = rand() % 1000 + 1;
			printf(" %5d \n\n", num4);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;
			min = (min < num4) ? min : num4;

			scanf("\n %d", &answer);
			if (min == answer)
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 50점일 때 3자리 숫자 4개 중 큰 수 고르기
		else if (score == 50)
		{
			printf("\n 큰 수를 입력하세요! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t %d ", num1);
			num2 = rand() % 1000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 1000 + 1;
			printf(" %5d ", num3);
			num4 = rand() % 1000 + 1;
			printf(" %5d \n\n", num4);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;
			max = (max > num4) ? max : num4;

			scanf("\n %d", &answer);
			if (max == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 60점일 때 4자리 숫자 5개 중 작은 수 고르기
		else if (score == 60)
		{
			printf("\n 작은 수를 입력하세요! \n\n");
			num1 = rand() % 10000 + 1;
			printf("\n\t %d ", num1);
			num2 = rand() % 10000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 10000 + 1;
			printf(" %5d ", num3);
			num4 = rand() % 10000 + 1;
			printf(" %5d ", num4);
			num5 = rand() % 10000 + 1;
			printf(" %5d \n\n", num4);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;
			min = (min < num4) ? min : num4;
			min = (min < num5) ? min : num5;

			scanf("\n %d", &answer);
			if (min == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 70점이상 일 때 4자리 숫자 5개 중 큰 수 고르기
		else
		{
			printf("\n 큰 수를 입력하세요! \n\n");
			num1 = rand() % 10000 + 1;
			printf("\n\t %d ", num1);
			num2 = rand() % 10000 + 1;
			printf(" %5d ", num2);
			num3 = rand() % 10000 + 1;
			printf(" %5d ", num3);
			num4 = rand() % 10000 + 1;
			printf(" %5d ", num4);
			num5 = rand() % 10000 + 1;
			printf(" %5d \n\n", num4);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;
			max = (max > num4) ? max : num4;
			max = (min > num5) ? max : num5;

			scanf("\n %d", &answer);
			if (max == answer)											// 정답을 입력했을시 화면정리 후 정답! 출력, +10점
			{
				system("cls");
				printf("\n\t정답! \n\n");
				score += 10;
			}
		}

		// 게임시작 10초 후 종료
		cur_time = clock();
		if ((cur_time - old_time) > (10 * CLOCKS_PER_SEC))
		{
			break;
		}
	}

	system("cls");														// 화면 정리
	printf("시간 종료! \n\n");											// 시간 종료! 출력 후 점수 리턴
	return score;
}