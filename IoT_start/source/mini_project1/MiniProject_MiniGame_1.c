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
#define How_Many_Time_Play_DiffGame 5								// ���� �ݺ� Ƚ��
#define Length_of_Array 5											// �迭 ����(x)
#define Height_of_Array 5											// �迭 ����(y)
#define Over_the_Time_limit -1										// �ð������� �Ѱ����� ����� ��
#define Succes_to_Login 1											// �α��� ����
#define Amsan_count 3												// �ϻ� stageNUM

int loginCheck = 1; // �α��� ����=1, ���� �Ǵ� �α׾ƿ�=0
int Curent_id_num = 0;

struct score {   // [���� ���� ����ü]
	int upDown;  // ���ٿ� ����
	int cal;     // �ϻ� ����
	int BW;      // û���� ����
	int spot;    // Ʋ���׸� ã��
	int total;   // ���� ����
};

struct player {              // [�÷��̾� ���� ���� ����ü]
	struct score sc;		 // score ����ü�� ����� ���
	char id[id_limit + 1];   // ���̵�
	char pw[pw_limit + 1];   // ��й�ȣ
	int rank;                // ��ŷ
	int join;                // ��� ����
};

int start();
void join(struct player allPlayerList[]); // �÷��̾� ��� �Լ�
struct player logIn(struct player p, struct player allPlayerList[]);
int main_menu();
int rank();

// ----------------------------------------- Ʋ���׸�ã�� �Լ����� --------------------------------------------------------------------

void Print_diff_Mainmenu(void);										// ���θ޴� ��� �Լ�
int Cal_Score(int Set_endTime);										// ���ھ� ��� �Լ�
int Make_Random_Num(int Random_Num_Range);							// ������� �Լ�
int Make_Random_Num_Range(int from, int end);						// Ư�������� ���� ����Լ�
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// Ʋ���׸�ã�� �� ���
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// ���� �Է¹޾� Ȯ��
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame]);	// �������� ��� �Լ�

// ----------------------------------------- �ϻ� �Լ����� --------------------------------------------------------------------

int RandNum1(int i);
int RandNum2(int i);
int Calc(Num1, Num2);
int InsertDap(void);
int Print(int i);
int Game(int i);
void StartMenu();
void End_Menu();

// ----------------------------------------- updown�Լ����� --------------------------------------------------------------------

int game1(void);													// updown �Լ�
void game1_main_menu(void);											// updown ���θŴ�





int main(void) 
{

	// ���� �ʱ�ȭ
	srand((unsigned)time(NULL));

	int start_choice = 0, menu_choice = 0, rank_choice = 0, select_quit = 0;
	struct player p = { 0, }; // �÷��̾� ����ü ���� ����
	struct player allPlayerList[max_player]; // ��� �÷��̾� ���� ������ ����ü �迭 ����
	
	for (int i = 0; i < max_player; i++) {
		for (int j = 0; j <= id_limit; j++) {
			allPlayerList[i].id[j] = NULL;
		}
	} //�÷��̾� ���̵� �迭 null�� �ʱ�ȭ


	// ----------------------------------------- Ʋ���׸�ã�⺯������ -------------------------------------------------------------------------------------

	int score[How_Many_Time_Play_DiffGame] = { 0 };						// ���� ���� �� ����
	int Final_Score = 0;												// ��������
	int Judg_num = 0;													// ���ѽð� �Ѱ��� ��� �������� ����
	int Rank_num_diff[max_player] = { 0 };								// ��ü��ŷ ���
	int Rank_num_total[max_player] = { 0 };
	int Curent_id_num = 0;												// ���� �α��ε� ���̵��� ��ȣ
	int original_array[Length_of_Array][Height_of_Array] = { 0 };		// �������� ���� ���ڵ��� �����ϴ� �迭
	int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original�� �ٸ� �κ��� ����� ������ �迭

		// ----------------------------------------- ���ٿ� �������� -------------------------------------------------------------------------------------

	int game1_rank_num[max_player] = { 0 };
	int game1_score = 0;

	// ----------------------------------------- û���� �������� -------------------------------------------------------------------------------------

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


	//------------------ ��ŷ�ý��� Ȯ���� ���� �ӽ� ����ü �����Է� -----------------------

	for (int i = 0; i < 10; i++)
	{
		strcpy(allPlayerList[i].pw, "0000");
		allPlayerList[i].sc.total = 0;
		allPlayerList[i].sc.upDown = i;
		allPlayerList[i].sc.cal = (i*10);
		allPlayerList[i].sc.BW = (i*100);
		allPlayerList[i].sc.spot = (i*1000);
		allPlayerList[i].sc.total = allPlayerList[i].sc.spot + allPlayerList[i].sc.BW + allPlayerList[i].sc.cal + allPlayerList[i].sc.upDown;
	}

	strcpy(allPlayerList[0].id, "���̵�0");
	strcpy(allPlayerList[1].id, "���̵�1");
	strcpy(allPlayerList[2].id, "���̵�2");
	strcpy(allPlayerList[3].id, "���̵�3");
	strcpy(allPlayerList[4].id, "���̵�4");
	strcpy(allPlayerList[5].id, "���̵�5");
	strcpy(allPlayerList[6].id, "���̵�6");
	strcpy(allPlayerList[7].id, "���̵�7");
	strcpy(allPlayerList[8].id, "���̵�8");
	strcpy(allPlayerList[9].id, "���̵�9");


	while (1) {
		start_choice = 0;
		start_choice = start(); // ����ȭ�� ���

		if (start_choice == 1) { // �α��� �������� ��
			p = logIn(p, allPlayerList); // �α��� �Լ� ȣ��

			if (loginCheck == 0) continue; // ��ϵ� ���̵� ���� �� ����ȭ������ ���ư���
			else { // �α��� ����, ����ȭ������

				while (1)
				{
					menu_choice = 0;
					menu_choice = main_menu();

					if (menu_choice == 1) {       // ���ٿ� ���� ����
						//���ٿ� ���� ȣ�� �ۼ��ϱ�
						while (1)
						{
							game1_main_menu();										// updown ���θŴ� ȣ��
							printf("���ϴ� �޴��� ��ȣ�� �Է� �ϼ���\n");
							scanf("%d", &Select_diff_main_menu);

							// 1. ���� ����
							if (Select_diff_main_menu == 1)
							{
								// ���� ���� �� ���� ���
								system("cls");
								printf("\n===============================================\n");
								printf("\n 10�� ���� �������� ������ ���� �� ȭ�鿡 \n");
								printf("\n ǥ�õȴ�� ���� ū ���� ���� ���� �Է��ϼ���. \n");
								printf("\n===============================================\n");
								Sleep(2000);
								system("cls");

								int sec = 3;
								// ���� ���� �� ���
								for (sec; sec > 0; sec--)
								{
									printf("\n ���ӽ��� %d����..", sec);
									Sleep(1000);
									system("cls");
								}

								game1_score = game1();															// ù��°���� ���� �� game1_final_score�� ���� ����
								allPlayerList[Curent_id_num].sc.upDown = game1_score;								// �÷��̾� ��Ͽ� ���ھ� �߰�
								printf("\n=========================================\n");
								printf("\n%s���� ���� ������ %d �Դϴ�\n", allPlayerList[Curent_id_num].id, game1_score);	// ���� ���
								printf("\n=========================================\n");
								system("pause");
								system("cls");
							}
							// 2. �ʱ�ȭ
							else if (Select_diff_main_menu == 2)
							{

								while (1)
								{
									system("cls");
									printf("�ʱ�ȭ �޴��Դϴ�. �÷��̾���� Up / Down ����� �ʱ�ȭ �Ͻðڽ��ϱ�?\n");
									printf(" 1. ���� \t 2. ���\n");
									scanf("%d", &Select_diff_ResetMenu);

									// 2.1 �ʱ�ȭ ����
									if (Select_diff_ResetMenu == 1)
									{
										allPlayerList[Curent_id_num].sc.upDown = 0;
										printf("�ʱ�ȭ �Ǿ����ϴ�.");
										break;
									}

									// 2.2 �ڷ�
									else if (Select_diff_ResetMenu == 2)
									{
										break;
									}

									// 2.3 �߸��� �� ó��
									else
									{
										printf("�߸��� �Է� �� �Դϴ�. �ٽ� �Է� ���ּ���\n");
									}
								}
							}
							// 3. ��ŷȮ��
							else if (Select_diff_main_menu == 3)
							{
								while (1)
								{
									system("cls");
									printf("\n��ŷȮ�� �޴��Դϴ�. ���ϴ� �޴��� ���� ���ּ���\n");
									printf("\n1. ���η�ŷ \t 2. ��ü��ŷ \t 3. �ڷ�\n");
									scanf("%d", &Select_diff_RankingMenu);

									// 3.1 ���η�ŷ
									if (Select_diff_RankingMenu == 1)
									{
										system("cls");
										printf("\n===============================================\n");
										printf("\nUp / Down ���η�ŷ ������ �Դϴ�.\n\n");
										printf("\n\n%s ���� Up / Down ����� %d �� �Դϴ�.\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.upDown);
										printf("\n===============================================\n");
										system("PAUSE");
										system("cls");
										break;
									}
									// 3.2 ��ü��ŷ
									else if (Select_diff_RankingMenu == 2)
									{
										system("cls");
										printf("\nUp / Down ��ü��ŷ ������ �Դϴ�.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" ���\t ���̵�\t\t ���� \n\n");

										for (int i = 0; i < max_player; i++)					// ��� ���ϱ�
										{
											game1_rank_num[i] = max_player + 1;					// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.upDown >= allPlayerList[j].sc.upDown)				// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
													game1_rank_num[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (game1_rank_num[j] == i + 1)
													printf(" %2d��\t %12s\t %5d\n", game1_rank_num[j], allPlayerList[j].id, allPlayerList[j].sc.upDown);

											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}
									// 3.3 �ڷ�
									else if (Select_diff_RankingMenu == 3)
									{

										break;
									}
									// 3.4 �߸��� �� ó��
									else
									{

										printf("\n�߸��� �Է� �� �Դϴ�. �ٽ� �Է� ���ּ���\n");
									}
								}

							}
							// 4. �ڷ�
							else if (Select_diff_main_menu == 4)
							{
								system("cls");
								break;
							}
							// 4.1 �߸��� �� ó��
							else
							{

								printf("\n�߸��� �Է� �� �Դϴ�. �ٽ� �Է� ���ּ���\n");
							}
						}
					}

					else if (menu_choice == 2) {  // �ϻ� ���� ����
					//�ϻ� ���� ȣ�� �ۼ��ϱ�
					while (1)
					{
						int act = 0;
						int i = 0;
						int Select_cal_ResetMenu = 0;

						StartMenu(); ///���� �޴� �Լ� ȣ��
						scanf("%d", &act); // ����� �޴� �Է�

						if (act == 1) //////�ϻ� ���� ����
						{

							int score[Amsan_count] = { 0 };
							int Score = 0;
							for (i = 1; i < Amsan_count; i++)
							{
								score[i] = Game(i);
								Score += score[i];
								printf("�� ������ %d�Դϴ�.\n", Score);
							}
							allPlayerList[Curent_id_num].sc.cal = Score;
						}

						else if (act == 2)  ///�ϻ���� ���� �ʱ�ȭ
						{
							system("cls");
							printf("�ʱ�ȭ");
							printf(" 1. ���� \t 2. ���\n");
							scanf("%d", &Select_cal_ResetMenu);

							// 2.1 �ʱ�ȭ ����
							if (Select_cal_ResetMenu == 1)
							{
								allPlayerList[Curent_id_num].sc.cal = 0;
								printf(" �ʱ�ȭ �Ǿ����ϴ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
								system("PAUSE");
								system("cls");
							}

							// 2.2 �ڷ�
							else if (Select_cal_ResetMenu == 2)
							{
								break;
							}

							// 2.3 �߸��� �� ó��
							else
							{
								printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
							}

						}

						else if (act == 3) //////�ϻ� ���� ��ŷ Ȯ��

						{
							system("cls");
							printf("\n �ϻ���� ��ü��ŷ �������Դϴ�.\n");
							printf("\n----------------------------------------------------------------\n");
							printf(" ���\t ���̵�\t\t ���� \n\n");

							for (int i = 0; i < max_player; i++)								// ��� ���ϱ�
							{
								Rank_num_diff[i] = 21;											// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
								for (int j = 0; j < max_player; j++)
								{
									if (allPlayerList[i].sc.cal >= allPlayerList[j].sc.cal)							// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
										Rank_num_diff[i]--;
								}
							}

							for (int i = 0; i < max_player; i++)
							{
								for (int j = 0; j < max_player; j++)
								{

									if (Rank_num_diff[j] == i + 1)
										printf(" %2d��\t %12s\t %5d\n", Rank_num_diff[j], allPlayerList[j].id, allPlayerList[j].sc.cal);

								}
							}
							printf("\n----------------------------------------------------------------\n");
							system("PAUSE");
							system("cls");
							break;

						}

						else if (act == 4)  //////�ϻ���� ���۸޴����� �ڷΰ���
						{
							printf("�ڷΰ���");
						}


						End_Menu();  //////�ϻ� ���� �� �ߴ� �޴� �Լ�
						scanf("%d", &act);

						if (act == 1) ///////�ϻ���� �絵��
						{
							int score[Amsan_count] = { 0 };
							int Score = 0;
							for (int i = 1; i < Amsan_count; i++)
							{
								score[i] = Game(i);
								Score += score[i];
								printf("�� ������ %d�Դϴ�.\n", Score);
							}
							allPlayerList[Curent_id_num].sc.cal = Score;
						}

						else if (act == 2) /////�ϻ���� ���� �ʱ�ȭ
						{
							system("cls");
							printf("�ʱ�ȭ");
							printf(" 1. ���� \t 2. ���\n");
							scanf("%d", &Select_diff_ResetMenu);

							// 2.1 �ʱ�ȭ ����
							if (Select_diff_ResetMenu == 1)
							{
								allPlayerList[Curent_id_num].sc.cal = 0;
								printf(" �ʱ�ȭ �Ǿ����ϴ�. �ʱ�ȭ������ ���ư��ϴ�.");
								system("PAUSE");
								system("cls");
								break;
							}

							// 2.2 �ڷ�
							else if (Select_diff_ResetMenu == 2)
							{
								break;
							}

							// 2.3 �߸��� �� ó��
							else
							{
								printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
							}
						}

						else if (act == 3) /////�ϻ���� ��ŷȮ��
						{
							while (1)
							{
								system("cls");
								printf(" ��ŷȮ�� �޴��Դϴ�. ���ϴ� �޴��� �������ּ���\n");
								printf("\n 1. ���η�ŷ \t 2. ��ü��ŷ \t 3. �ڷ�\n");
								scanf("%d", &Select_diff_RankingMenu);

								if (Select_diff_RankingMenu == 1)
								{
									// 3.1 ���η�ŷ
									system("cls");
									printf("\n----------------------------------------------------------------\n");
									printf("\n %s ���� Ʋ���׸�ã�� ����� < %d > ���Դϴ�.\n\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.cal);
									printf("\n----------------------------------------------------------------\n");
									system("PAUSE");
									system("cls");
									break;
								}

								else if (Select_diff_RankingMenu == 2)
								{
									// 3.2 ��ü��ŷ
									system("cls");
									printf("\n Ʋ���׸�ã�� ��ü��ŷ �������Դϴ�.\n");
									printf("\n----------------------------------------------------------------\n");
									printf(" ���\t ���̵�\t\t ���� \n\n");

									for (int i = 0; i < max_player; i++)								// ��� ���ϱ�
									{
										Rank_num_diff[i] = 21;											// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
										for (int j = 0; j < max_player; j++)
										{
											if (allPlayerList[i].sc.cal >= allPlayerList[j].sc.cal)							// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
												Rank_num_diff[i]--;
										}
									}

									for (int i = 0; i < max_player; i++)
									{
										for (int j = 0; j < max_player; j++)
										{

											if (Rank_num_diff[j] == i + 1)
												printf(" %2d��\t %12s\t %5d\n", Rank_num_diff[j], allPlayerList[j].id, allPlayerList[j].sc.cal);

										}
									}
									printf("\n----------------------------------------------------------------\n");
									system("PAUSE");
									system("cls");
									break;
								}

								else if (Select_diff_RankingMenu == 3)
								{
									// 3.3 �ڷ�
									break;
								}

								else
								{
									// 3.4 �߸��� �� ó��
									printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
								}
							}

						}

						else if (act == 4) /////�ϻ���ӿ��� �ڷΰ���
						{
							printf("�ڷΰ���");
						}
					}
						
						

					
					else if (menu_choice == 3) {  // û���� ���� ����
						//û���� ���� ȣ�� �ۼ��ϱ�


						printf("                               ----- û�� ��� ���� �Դϴ� -----\n");
						printf("                   ȭ�鿡 �����ϴ� ���ÿ� ���� ���� �Է� �� ENTER�� �����ּ���\n");
						printf("\n");
						printf("                                           ��Ģ                \n");
						printf("                                     1.û�� �÷��� 1��\n");
						printf("                                     2.û�� ������ 2��\n");
						printf("                                     3.��� �÷��� 3��\n");
						printf("                                     4.��� ������ 4��\n");
						printf("\n");


						int NUM3 = 0;                                                      // ������ NUM3 �ʱ�ȭ
						printf("                   *������ �����Ͻ÷��� 1���� �׸��Ͻ÷��� 2���� �����ּ���*\n");
						scanf("%d", &NUM3);


						if (NUM3 == 1)                                                     // 1�϶� ������ ����
						{
							printf("                                ������ �����մϴ�\n");
							//���� ���
							int FinishTime = (unsigned)time(NULL);                         //������ �ð��� ����� ����
							FinishTime += 15;                                              //������ �ð� 30��

							char Coma[4][35] = { "û��÷�","û�⳻��","���÷�","��⳻��" }; /// 1,2,3,4
							char Comb[4][35] = { "��� �ø��� ���� û�� �÷�","û�� �ø��� ���� ����","��� ������ ���� ��� �÷�","û�� ������ ���� ��� ����" }; /// 1,2,3,4
							char Comc[4][35] = { "û�� ������ ���� �÷�","��� �ø��� ���� û�� ����","û�� �ø��� ���� ��� �÷�","û�� �ø��� ���� ��� ����" }; /// 1,2,3,4
							char Comd[4][35] = { "��� ������ ���� û�� �÷�","��� ������ ���� û�� ����","û�� ������ ���� ��� �÷�","û�� ������ ���� ��� ����" }; /// 1,2,3,4

							srand((unsigned int)time(NULL));                            //�Ź� �ٸ� ���� ����


							while (1)
							{
								system("cls");													//ȭ���� ����
								int StartTime = (unsigned)time(NULL);							//���۽ð� while�� ����Ǿ� ���� �ð��� ����
								printf("%d��\n", FinishTime - StartTime);						//����ð����� ������� �帥 �ð��� ��
								Sleep(1);													//�ð��� 0.01�� ����   


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

								if (FinishTime - StartTime <= 0)                             // �ð� �ʰ��� ���� ���� ����
								{
									printf("����Ǿ����ϴ�.\n");
									break;
								}
								//rand�Լ� ���� 0~32767
								com = rand() % 4 + 1;
								com1 = rand() % 4 + 1;
								com2 = rand() % 4 + 1;
								com3 = rand() % 4 + 1;                                  //��ǻ�Ͱ� û�� ��� �������� �����ؾ� �Ǵ� ����

								if (com == 1)										//��ǻ�Ϳ� �÷��̾� ���� ��                          
								{
									printf("%s\n", Coma[0]);
									printf("�÷��̾� ����:");
									scanf("%d", &player);
								}
								else if (com == 2)
								{
									printf("%s\n", Coma[1]);
									printf("�÷��̾� ����:");
									scanf("%d", &player);
								}
								else if (com == 3)
								{
									printf("%s\n", Coma[2]);
									printf("�÷��̾� ����:");
									scanf("%d", &player);
								}
								else if (com == 4)
								{
									printf("%s\n", Coma[3]);
									printf("�÷��̾� ����:");
									scanf("%d", &player);
								}


								if (com1 == 1)										//��ǻ�Ϳ� �÷��̾� ���� ��                          
								{
									printf("%s\n", Comb[0]);
									printf("�÷��̾� ����:");
									scanf("%d", &player1);
								}
								else if (com1 == 2)
								{
									printf("%s\n", Comb[1]);
									printf("�÷��̾� ����:");
									scanf("%d", &player1);
								}
								else if (com1 == 3)
								{
									printf("%s\n", Comb[2]);
									printf("�÷��̾� ����:");
									scanf("%d", &player1);
								}
								else if (com1 == 4)
								{
									printf("%s\n", Comb[3]);
									printf("�÷��̾� ����:");
									scanf("%d", &player1);
								}



								if (com2 == 1)										//��ǻ�Ϳ� �÷��̾� ���� ��                          
								{
									printf("%s\n", Comc[0]);
									printf("�÷��̾� ����:");
									scanf("%d", &player2);
								}
								else if (com2 == 2)
								{
									printf("%s\n", Comc[1]);
									printf("�÷��̾� ����:");
									scanf("%d", &player2);
								}
								else if (com2 == 3)
								{
									printf("%s\n", Comc[2]);
									printf("�÷��̾� ����:");
									scanf("%d", &player2);
								}
								else if (com2 == 4)
								{
									printf("%s\n", Comc[3]);
									printf("�÷��̾� ����:");
									scanf("%d", &player2);
								}

								if (com3 == 1)										//��ǻ�Ϳ� �÷��̾� ���� ��                          
								{
									printf("%s\n", Comd[0]);
									printf("�÷��̾� ����:");
									scanf("%d", &player3);
								}
								else if (com3 == 2)
								{
									printf("%s\n", Comd[1]);
									printf("�÷��̾� ����:");
									scanf("%d", &player3);
								}
								else if (com3 == 3)
								{
									printf("%s\n", Comd[2]);
									printf("�÷��̾� ����:");
									scanf("%d", &player3);
								}
								else if (com3 == 4)
								{
									printf("%s\n", Comd[3]);
									printf("�÷��̾� ����:");
									scanf("%d", &player3);
								}

								else
								{
									printf("�߸��� ���Դϴ�\n");
								}


							}

							sumscore = score0 + score1 + score2 + score3;
							printf("����� �� ������: %d ���Դϴ�.\n\n", sumscore);
							system("PAUSE");
							system("cls");

						}

						else if (NUM3 == 2)                                                  // 2�϶� ������ ����
						{
							printf("������ �����մϴ�\n");

						}
						
					}
					else if (menu_choice == 4) {  // Ʋ���׸�ã�� ���� ����
						//Ʋ���׸�ã�� ���� ȣ�� �ۼ��ϱ�

						while (1)
						{
							Print_diff_Mainmenu();										// �޴� ���̾ƿ� ���
							printf(" ���ϴ� �޴��� ��ȣ�� �Է��ϼ���\n");					// �޴� ����
							scanf("%d", &Select_diff_main_menu);						// ��������� �޴� �Է¹���

							if (Select_diff_main_menu == 1)
							{
								// 1. ���� �����
								system("cls");

								for (int q = 0; q < How_Many_Time_Play_DiffGame; q++)			// Ʋ���׸�ã����� �ݺ�Ƚ��
								{

									// �ɸ� �ð� ����� ���� ���۽ð� ��� �� �ʱ�ȭ
									long StartTime = 0; // ���ӽ��� �ð� �ʱ�ȭ
									long totlaElapsedTime = 0; // �� ����ð� �ʱ�ȭ
									StartTime = clock(); // ���ӽ��� �ð� ���

									// ���� ���� ���� �� �迭�� ����
									for (int i = 0; i < 5; i++)
									{
										for (int j = 0; j < 5; j++)
										{
											original_array[i][j] = Make_Random_Num_Range(33, 126);	// �ƽ�Ű �ڵ�ǥ�� Ư������ 33 ~ 126�� ���� ��� (�ƽ�Ű �ڵ� ����� ���� Ư�����ڸ� ����� �ǵ�)
											different_array[i][j] = original_array[i][j];			// Ʋ���ʿ� �� ���� �����
										}
									}

									// different_array�迭�� Ʋ�� �κ��� ���� �ֱ�
									int Whats_diffent = 0;															// Ʋ�� �� ����
									int Where_is_diff_x = Make_Random_Num(Length_of_Array);							// Ʋ���κ� x��ǥ
									int Where_is_diff_y = Make_Random_Num(Height_of_Array);							// Ʋ���κ� y��ǥ

									Whats_diffent = Make_Random_Num_Range(33, 126);									// Ʋ�� ���� ������ �޾Ƽ� ����
									while (different_array[Where_is_diff_x][Where_is_diff_y] == Whats_diffent)		// ������ ������ ���� Ȥ�� Ʋ���κ��� ��ǥ�� �ش��ϴ� �迭�κа� ���� �ʴ��� Ȯ��
									{
										Whats_diffent = Make_Random_Num_Range(33, 126);								// ���� ������ ���� �ݺ�
									}

									different_array[Where_is_diff_x][Where_is_diff_y] = Whats_diffent;				// ���� �����ϱ� ���Կ���


									// ȭ�鿡 Ʋ���׸� ã�� ���� ���
									Print_Bingo(original_array, different_array);									// Ʋ���׸�ã���� ���
									Check_Answer(Where_is_diff_x, Where_is_diff_y);									// �����Է¹޾� �������� Ȯ���ϰ� �ȳ��� ���


									score[q] = Cal_Score(StartTime);												// ���� ���
									if (score[q] == Over_the_Time_limit)	// ���ѽð� �Ѱ��� �� ó��										
									{
										Judg_num = Over_the_Time_limit;
										break;
									}
									system("PAUSE");						// ���� ���߰� �������� �Ѿ���� �Ͻ�����
									system("cls");							// ȭ�� ����
								}

								if (Judg_num == Over_the_Time_limit)									// ���ѽð� �ѱ�� �������� ���X
								{
									printf("��! ���ѽð��� �Ѱ���ϴ�. ������ �ٽ� �������ּ���!");			// ���ѽð� �Ѱ��� �� ��¹���
								}

								else
								{
									// �������ھ� �ջ� �� ���
									Final_Score = Print_Diff_Final_Score(score);
									allPlayerList[Curent_id_num].sc.spot = Final_Score;											// �÷��̾� ��Ͽ� ���ھ� �߰�
									printf("\n=========================================\n");
									printf("\n %s���� ���� ������ < %d > ���Դϴ�\n", allPlayerList[Curent_id_num].id, Final_Score);
									printf("\n=========================================\n");
									system("PAUSE");						// ���� ���߰� �������� �Ѿ���� �Ͻ�����
									system("cls");							// ȭ�� ����
								}
							}
							else if (Select_diff_main_menu == 2)
							{
								// 2. �ʱ�ȭ
								while (1)
								{
									system("cls");
									printf(" �ʱ�ȭ �޴��Դϴ�. �÷��̾���� Ʋ���׸�ã�� ����� �ʱ�ȭ�Ͻðڽ��ϱ�?\n");
									printf(" 1. ���� \t 2. ���\n");
									scanf("%d", &Select_diff_ResetMenu);

									// 2.1 �ʱ�ȭ ����
									if (Select_diff_ResetMenu == 1)
									{
										allPlayerList[Curent_id_num].sc.spot = 0;
										printf(" �ʱ�ȭ �Ǿ����ϴ�. �ʱ�ȭ������ ���ư��ϴ�.");
										system("PAUSE");
										system("cls");
										break;
									}

									// 2.2 �ڷ�
									else if (Select_diff_ResetMenu == 2)
									{
										break;
									}

									// 2.3 �߸��� �� ó��
									else
									{
										printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
									}
								}

							}

							else if (Select_diff_main_menu == 3)
							{
								// 3. ��ŷȮ��
								while (1)
								{
									system("cls");
									printf(" ��ŷȮ�� �޴��Դϴ�. ���ϴ� �޴��� �������ּ���\n");
									printf("\n 1. ���η�ŷ \t 2. ��ü��ŷ \t 3. �ڷ�\n");
									scanf("%d", &Select_diff_RankingMenu);

									if (Select_diff_RankingMenu == 1)
									{
										// 3.1 ���η�ŷ
										system("cls");
										printf("\n----------------------------------------------------------------\n");
										printf("\n %s ���� Ʋ���׸�ã�� ����� < %d > ���Դϴ�.\n\n", allPlayerList[Curent_id_num].id, allPlayerList[Curent_id_num].sc.spot);
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}

									else if (Select_diff_RankingMenu == 2)
									{
										// 3.2 ��ü��ŷ
										system("cls");
										printf("\n Ʋ���׸�ã�� ��ü��ŷ �������Դϴ�.\n");
										printf("\n----------------------------------------------------------------\n");
										printf(" ���\t\t ���̵�\t\t ���� \n\n");

										for (int i = 0; i < max_player; i++)								// ��� ���ϱ�
										{
											Rank_num_diff[i] = max_player + 1;											// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
											for (int j = 0; j < max_player; j++)
											{
												if (allPlayerList[i].sc.spot >= allPlayerList[j].sc.spot)							// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
													Rank_num_diff[i]--;
											}
										}

										for (int i = 0; i < max_player; i++)
										{
											for (int j = 0; j < max_player; j++)
											{

												if (Rank_num_diff[j] == i + 1)
													printf(" %2d��\t %12s\t %5d\n", Rank_num_diff[j], allPlayerList[j].id, allPlayerList[j].sc.spot);

											}
										}
										printf("\n----------------------------------------------------------------\n");
										system("PAUSE");
										system("cls");
										break;
									}

									else if (Select_diff_RankingMenu == 3)
									{
										// 3.3 �ڷ�
										break;
									}

									else
									{
										// 3.4 �߸��� �� ó��
										printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
									}
								}

							}

							else if (Select_diff_main_menu == 4)
							{
								// 4. �ڷ�
								system("cls");
								break;
							}

							else
							{
								// 4.1 �߸��� �� ó��
								printf(" �߸��� �Է°��Դϴ�. �ٽ��Է����ּ���\n");
							}
						}

					}
					else if (menu_choice == 5) {  // ��ŷ ��ȸ
						while (1)
						{
							rank_choice = rank();

							if (rank_choice == 1) {   // ���Ӻ� ��ŷ ��ȸ

							}
							else if (rank_choice == 2) {  // ���� ��ŷ ��ȸ
								// ���� ��ü��ŷ (total)
								system("cls");
								printf("\n ���� ��ü��ŷ �������Դϴ�.\n");
								printf("\n----------------------------------------------------------------\n");
								printf(" ���\t\t ���̵�\t\t ���� \n\n");

								for (int i = 0; i < max_player; i++)								// ��� ���ϱ�
								{
									Rank_num_total[i] = max_player + 1;								// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
									for (int j = 0; j < max_player; j++)
									{
										if (allPlayerList[i].sc.total >= allPlayerList[j].sc.total)	// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
											Rank_num_total[i]--;
									}
								}

								for (int i = 0; i < max_player; i++)
								{
									for (int j = 0; j < max_player; j++)
									{

										if (Rank_num_total[j] == i + 1)
											printf(" %2d��\t %12s\t\t %5d\n", Rank_num_total[j], allPlayerList[j].id, allPlayerList[j].sc.total);

									}
								}
								printf("\n----------------------------------------------------------------\n");
								system("PAUSE");
								system("cls");
								break;
							}



							else if (rank_choice == 3) {  // �ٽ� ����ȭ������
								break;
							}
							else { // �̻��� �� ������ ��
								printf("�߸��� �Է��Դϴ�.\n");
							}
						}
					
						
					}
					else if (menu_choice == 6) {  // �α׾ƿ�
						printf("�α׾ƿ��Ǿ����ϴ�.\n");
						loginCheck = 0;
						break;
					}
					else if (menu_choice == 7) {  // ���α׷� ����
						printf("���α׷��� �����մϴ�.\n");
						select_quit = 1;
						break;
					}
					else { // �߸��� ����
						printf("�߸��� �Է��Դϴ�.\n");
					}
				}
				if (select_quit == 1)
				{
					break;
				}
			}
		}

		else if (start_choice == 2) { // �÷��̾� ��� �������� ��
			join(allPlayerList);
		}

		else if (start_choice == 3) { // ���� �������� ��
			printf("���α׷��� �����մϴ�.\n");
			
			break;
		}

		else printf("�߸��� �Է��Դϴ�.\n"); // 1,2,3 �ƴ� �� �Է����� ��
	}

	return 0;
}

// ------------------------ �α��� �� ���θ޴� �Լ� ----------------------------------------------------------

int start() {
	int choice;

	printf("\n[�̴ϰ���õ��]\n\n"); 
	printf("(1) �α���\n");
	printf("(2) �÷��̾� ���\n");
	printf("(3) ����\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

void join(struct player allPlayerList[]) {
	int id_check = -1;
	char id_temp[id_limit + 1] = { NULL, };

	printf("[�÷��̾� ���]\n\n");
	while (1) {
		printf("����� ���̵� �Է��ϼ���(�ִ� ����12����, �ѱ�6����)\n");
		printf("�Է� : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // �����ϴ� ���̵����� ��

			if (id_check == 0) { // �����ϴ� ���̵��� ��
				printf("�̹� �����ϴ� ���̵��Դϴ�.\n");
				break;
			}
		}

		if (id_check != 0) { // ���� ������ ���̵��� ��
			for (int i = 0; i < max_player; i++) {
				if (allPlayerList[i].id != NULL) { // ���ڸ� ã�Ƽ�
					strcpy(allPlayerList[i].id, id_temp); // ���ڸ��� ���̵� ����
					printf("��� ������ ���̵��Դϴ�.\n");
					printf("��й�ȣ�� �Է��ϼ���(4�ڸ� ����)\n");
					printf("�Է� : ");
					scanf("%s", allPlayerList[i].pw); // ��й�ȣ ����
					break;
				}
				else 
				{
					printf("���ڸ��� �����ϴ�. ���̵� ������ ��� �ٶ��ϴ�.")
				}
			}

			printf("����� �Ϸ�Ǿ����ϴ�.\n");
			
			break;
		}
	}
}

struct player logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL, };
	char pw_temp[pw_limit + 1] = { NULL, };
	int id_check = -1, pw_check = -1;
	int check_id_temp = 0;

	printf("[�α���]\n\n");
	while (1) {
		printf("���̵� : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // �����ϴ� ���̵����� ��
			if (id_check == 0) { // �����ϴ� ���̵��� ��
				printf("��й�ȣ :");
				scanf("%s", pw_temp);
				pw_check = strcmp(allPlayerList[i].pw, pw_temp); // ��� �´��� Ȯ��
				check_id_temp = i;
				break;
			}
		
		}

		if (id_check != 0) { // �����ϴ� ���̵� �ƴ� ��,
			printf("�������� �ʴ� ���̵��Դϴ�.\n");
			loginCheck = 0;
			check_id_temp = 0;
			strcpy(id_temp,'/0');
			break;
		}

		if (id_check == 0 && pw_check == 0) { // �α��� ����
			printf("�α��εǾ����ϴ�.\n");
			loginCheck = 1;
			strcpy(p.id, id_temp);
			strcpy(p.pw, pw_temp); // ����ü ������ �Ƶ�, ��� ��� ����
			Curent_id_num = check_id_temp;
			//  ���θ޴� ȭ������ �����ֱ�
			break;
		}
		else if (id_check == 0 && pw_check != 0) { // ���̵� �ִµ� ��� Ʋ�� ��
			printf("�߸��� ��й�ȣ �Դϴ�.\n");
			check_id_temp = 0;
		}
	}

	return p;
}

int main_menu() {
	int choice = 0;

	printf("\n[���� �޴�]\n\n");
	printf("(1) ���ٿ�\n");
	printf("(2) �ϻ�\n");
	printf("(3) û����\n");
	printf("(4) Ʋ���׸�ã��\n");
	printf("(5) ��ŷ ��ȸ\n");
	printf("(6) �α׾ƿ�\n");
	printf("(7) ���α׷� ����\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

int rank() {
	int choice = 0;

	printf("\n[��ŷ ��ȸ]\n\n");
	printf("(1) ���Ӻ� ��ŷ ��ȸ\n");
	printf("(2) ���� ��ŷ ��ȸ\n");
	printf("(3) �ڷΰ���\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

// ------------------------ Ʋ���׸�ã�� �Լ����� ----------------------------------------------------------



// �ɸ� �ð��� ���� ���� ����
// �⺻�� 100���� �Ͽ� (�ɸ��ð�*2)��ŭ�� 100���� ����
int Cal_Score(int StartTime)
{
	int Score = 100;					// �⺻����
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // �ɸ� �ð�

	printf("\n�ɸ� �ð��� %d �� �Դϴ�.\n ", totalElapsedTime);

	Score = Score - (totalElapsedTime * 2);				// ���� ���� = �⺻���� - (�ɸ��ð� * 2)

	if (Score < 0)										// ���ھ ������ �Ǹ� �ǰ� 
	{
		Score = Over_the_Time_limit;
	}

	return Score;

}

// ������ ����ϴ� �Լ�
// ��µǴ� ������ ������ �Է¹޴´�.
int Make_Random_Num(int Random_Num_Range)
{
	int num;

	num = rand() % Random_Num_Range;
	return num;
}

// from ~ end ������ ������ ����ϴ� �Լ�
// from�� end�� �����Ѵ�.
int Make_Random_Num_Range(int from, int end)
{
	int num;

	num = rand() % (end - from + 1) + from;
	return num;
}

// Ʋ���׸� ã���� ���
// ���� = ����
// ������ = �迭�� 1���� ���� �ٸ�
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

// ���� üũ �� �ȳ��� ���
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y)
{
	while (1)
	{
		int ans_x = 0;
		int ans_y = 0;
		printf("���δٸ� �κ��� ��ǥ�� �Է��ϼ���(1~5)(1~5) : ");
		scanf("%d %d", &ans_x, &ans_y);

		if (ans_x - 1 == Where_is_diff_y && ans_y - 1 == Where_is_diff_x)
		{
			printf("\n �� �����Դϴ�! �� \n");
			break;
		}
		else
		{
			printf("!!! ��! Ʋ�Ƚ��ϴ� !!!\n");
		}
	}

}

// Ʋ���׸�ã�� ���� ���ھ� ���
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame])
{
	int final_score = 0;
	for (int i = 0; i < How_Many_Time_Play_DiffGame; i++)
	{
		final_score = final_score + Score[i];
	}
	return final_score;
}

// Ʋ���׸�ã�� ���θ޴� ���
void Print_diff_Mainmenu(void)
{
	printf("\n===============================================\n");
	printf("\t\t Ʋ�� �׸� ã�� \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. ����\n\n\t\t 2. �ʱ�ȭ\n\n\t\t 3. ��ŷȮ��\n\n\t\t 4. �ڷ�\n\n");
	printf("\n===============================================\n");
}

//--------------------------�ϻ���� �Լ�---------------------------------------------------------------


int RandNum1(int i) //�������� ���� �̾��ִ� �Լ�1
{
	srand((unsigned)time(0));
	int Num1 = (rand() % (10 * i)) + 1; //������ ���� ����1

	if (i >= 4)
	{
		int Num1 = (rand() % (100 * (i - 3))) + 1; //������ ���� ����1
	}
	else if (i >= 6)
	{
		int Num1 = (rand() % (1000 * (i - 5))) + 1; //������ ���� ����1
	}
	return Num1;
}

int RandNum2(int i) //�������� ���� �̾��ִ� �Լ�2
{
	srand((unsigned)time(NULL));
	int Num2 = (rand() % 10 * i) + 1; // ������ ���� ����2

	if (i >= 3)
	{
		int Num1 = (rand() % (100 * (i - 2))) + 1; //������ ���� ����1
	}
	else if (i >= 5)
	{
		int Num1 = (rand() % (1000 * (i - 4))) + 1; //������ ���� ����1
	}
	return Num2;
}



int Calc(Num1, Num2) //4Ģ������ �������� ���� �Լ�
{
	int calc = (Num1 + Num2) % 4; // ���� �μ��� ���ؼ� �������� ��Ģ������ �̱�
	int RealDap;// ����
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

int InsertDap(void) //���� �� �Է� �Լ�
{
	int Dap;
	printf("���� �Է��Ͻÿ�:");
	scanf("%d", &Dap);
	return Dap;
}

int Print(int i) //ä�� �� ����Լ�
{
	int Num1 = RandNum1(i);
	int Num2 = RandNum2(i);

	int RealDap = Calc(Num1, Num2);
	int Dap = InsertDap();

	int score = 0;

	if (Dap == RealDap)
	{
		printf("\n******�����Դϴ�*******\n");
		score++;
	}
	else
	{
		printf("\n******�����Դϴ�*******\n");
		score--;
	}
	return score;
}



int Game(int i) // �ܰ躰 ���� ���� �Լ�
{
	system("cls");
	printf("\t---------\n");
	printf("\t|Stage %d|\n", i);
	printf("\t---------\n");

	int endTime = (unsigned)time(NULL);
	endTime += 5;

	int score[Amsan_count] = { 0 };

	while (1)
	{
		int startTime = (unsigned)time(NULL);

		printf("\n--------------------------\n");
		printf("\t%d��\n", endTime - startTime);
		printf("-------------------------\n");


		score[i] += Print(i);


		if (endTime - startTime <= 0)
		{
			printf("\n////////////////////////////\n");
			printf("/////////TIME OVER//////////\n");
			printf("///////////////////////////\n");

			printf("-------------------------\n");
			printf("%d�ܰ� ������ %d�Դϴ�.\n", i, score[i]);
			printf("-------------------------\n");

			Sleep(5000);

			return score[i];

			break;
		}
	}
}

void StartMenu() //�ϻ���� ���� �� ������ �޴� �Լ�

{

	printf("\n--------------------------\n");

	printf("\t(1)����\n");

	printf("\t(2)�ʱ�ȭ\n");

	printf("\t(3)��ŷȮ��\n");

	printf("\t(4)�ڷΰ���");

	printf("\n--------------------------\n");

}


void End_Menu() ////�ϻ���� ���� ������ ������ �޴� �Լ�

{

	printf("\n--------------------------\n");

	printf("\t(1)�絵��\n");

	printf("\t(2)�ʱ�ȭ\n");

	printf("\t(3)��ŷȮ��\n");

	printf("\t(4)�ڷΰ���");

	printf("\n--------------------------\n");

}


// ----------------------------------------- updown �Լ����� --------------------------------------------------------------------


// updown �Լ�
int game1(void)
{
	int num1 = 0;														// ����1
	int num2 = 0;														// ����2
	int num3 = 0;														// ����3 
	int num4 = 0;														// ����4 
	int num5 = 0;														// ����5
	int answer = 0;														// ���� �Է�
	int	max = 0;														// �ִ밪 ����
	int min = 0;														// �ּҰ� ����
	int score = 0;														// ���� ����

	srand((unsigned)time(0));														//���� �ʱ�ȭ

	clock_t old_time, cur_time;											// �ð� ���� ����

	old_time = clock();
	// 10�ʵ��� ���ӹݺ�
	while (1)
	{
		// 0���� �� 2�ڸ� ���� �ΰ� �� ū �� ������
		if (score == 0)
		{
			printf("\nū ���� �Է��ϼ���! \n\n");
			num1 = rand() % 100 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 100 + 1;
			printf("%5d \n\n", num2);

			max = (num1 > num2) ? num1 : num2;

			scanf("\n%d", &answer);
			if (max == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 10���� �� 3�ڸ� ���� 2�� �� ���� �� ������
		else if (score == 10)
		{
			printf("\n���� ���� �Է��ϼ���! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf("%5d \n\n", num2);

			min = (num1 < num2) ? num1 : num2;

			scanf("\n%d", &answer);
			if (min == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 20���� �� 3�ڸ� ���� 3�� �� ���� �� ������
		else if (score == 20)
		{
			printf("\n���� ���� �Է��ϼ���! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 1000 + 1;
			printf("%5d \n\n", num3);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;

			scanf("\n%d", &answer);
			if (min == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 30���� �� 3�ڸ� ���� 3�� �� ū �� ������
		else if (score == 30)
		{
			printf("\nū ���� �Է��ϼ���! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 1000 + 1;
			printf("%5d \n\n", num3);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;

			scanf("\n%d", &answer);
			if (max == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 40���� �� 3�ڸ� ���� 4�� �� ���� �� ������
		else if (score == 40)
		{
			printf("\n���� ���� �Է��ϼ���! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 1000 + 1;
			printf("%5d ", num3);
			num4 = rand() % 1000 + 1;
			printf("%5d \n\n", num4);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;
			min = (min < num4) ? min : num4;

			scanf("\n%d", &answer);
			if (min == answer)
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 50���� �� 3�ڸ� ���� 4�� �� ū �� ������
		else if (score == 50)
		{
			printf("\nū ���� �Է��ϼ���! \n\n");
			num1 = rand() % 1000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 1000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 1000 + 1;
			printf("%5d ", num3);
			num4 = rand() % 1000 + 1;
			printf("%5d \n\n", num4);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;
			max = (max > num4) ? max : num4;

			scanf("\n%d", &answer);
			if (max == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 60���� �� 4�ڸ� ���� 5�� �� ���� �� ������
		else if (score == 60)
		{
			printf("\n���� ���� �Է��ϼ���! \n\n");
			num1 = rand() % 10000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 10000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 10000 + 1;
			printf("%5d ", num3);
			num4 = rand() % 10000 + 1;
			printf("%5d ", num4);
			num5 = rand() % 10000 + 1;
			printf("%5d \n\n", num4);

			min = (num1 < num2) ? num1 : num2;
			min = (min < num3) ? min : num3;
			min = (min < num4) ? min : num4;
			min = (min < num5) ? min : num5;

			scanf("\n%d", &answer);
			if (min == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// 70���̻� �� �� 4�ڸ� ���� 5�� �� ū �� ������
		else
		{
			printf("\nū ���� �Է��ϼ���! \n\n");
			num1 = rand() % 10000 + 1;
			printf("\n\t%d ", num1);
			num2 = rand() % 10000 + 1;
			printf("%5d ", num2);
			num3 = rand() % 10000 + 1;
			printf("%5d ", num3);
			num4 = rand() % 10000 + 1;
			printf("%5d ", num4);
			num5 = rand() % 10000 + 1;
			printf("%5d \n\n", num4);

			max = (num1 > num2) ? num1 : num2;
			max = (max > num3) ? max : num3;
			max = (max > num4) ? max : num4;
			max = (min > num5) ? max : num5;

			scanf("\n%d", &answer);
			if (max == answer)											// ������ �Է������� ȭ������ �� ����! ���, +10��
			{
				system("cls");
				printf("\n\t����! \n\n");
				score += 10;
			}
		}

		// ���ӽ��� 10�� �� ����
		cur_time = clock();
		if ((cur_time - old_time) > (10 * CLOCKS_PER_SEC))
		{
			break;
		}
	}

	system("cls");														// ȭ�� ����
	printf("�ð� ����! \n\n");											// �ð� ����! ��� �� ���� ����
	return score;
}

// updown ���θ޴� ���
void game1_main_menu(void)
{
	printf("\n\n===============================================\n");
	printf("\t\t Up / Down \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. ����\n\n\t\t 2. �ʱ�ȭ\n\n\t\t 3. ��ŷ Ȯ��\n\n\t\t 4. �ڷ�\n");
	printf("\n===============================================\n");
}

// -------------------------------------------------------------------------------------------------------------------------------------------