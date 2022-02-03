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
void Print_diff_Mainmenu(void);										// ���θ޴� ��� �Լ�
int Cal_Score(int Set_endTime);										// ���ھ� ��� �Լ�
int Make_Random_Num(int Random_Num_Range);							// ������� �Լ�
int Make_Random_Num_Range(int from, int end);						// Ư�������� ���� ����Լ�
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// Ʋ���׸�ã�� �� ���
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// ���� �Է¹޾� Ȯ��
int Print_Diff_Final_Score(int Score[How_Many_Time_Play_DiffGame]);	// �������� ��� �Լ�

int main() {

	// ���� �ʱ�ȭ
	srand((unsigned)time(NULL));

	int start_choice = 0, menu_choice = 0, rank_choice = 0, select_quit = 0;
	struct player p = { 0, }; // �÷��̾� ����ü ���� ����
	struct player allPlayerList[max_player]; // ��� �÷��̾� ���� ������ ����ü �迭 ����
	
	for (int i = 0; i < max_player; i++) {
		for (int j = 0; j <= id_limit; j++) {
			allPlayerList[i].id[j] = '\0';
		}
	} //�÷��̾� ���̵� �迭 null�� �ʱ�ȭ


	// ----------------------------------------- Ʋ���׸�ã�⺯������ -------------------------------------------------------------------------------------
	int score[How_Many_Time_Play_DiffGame] = { 0 };						// ���� ���� �� ����
	int Final_Score = 0;												// ��������
	int Judg_num = 0;													// ���ѽð� �Ѱ��� ��� �������� ����
	int Select_diff_main_menu = 0;										// �޴����� ������ ����
	int Select_diff_ResetMenu = 0;										// �ʱ�ȭ�޴� ������ ����
	int Select_diff_RankingMenu = 0;									// ��ŷȮ�θ޴� ������ ����
	int Rank_num_diff[max_player] = { 0 };								// ��ü��ŷ ���
	int Rank_num_total[max_player] = { 0 };
	int Curent_id_num = 0;												// ���� �α��ε� ���̵��� ��ȣ
	int original_array[Length_of_Array][Height_of_Array] = { 0 };		// �������� ���� ���ڵ��� �����ϴ� �迭
	int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original�� �ٸ� �κ��� ����� ������ �迭
	


		//------------------ ��ŷ�ý��� Ȯ���� ���� �ӽ� ����ü �����Է� -----------------------

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
		start_choice = start(); // ����ȭ�� ���

		if (start_choice == 1) { // �α��� �������� ��
			p = logIn(p, allPlayerList); // �α��� �Լ� ȣ��

			if (loginCheck == 0) continue; // ��ϵ� ���̵� ���� �� ����ȭ������ ���ư���
			else { // �α��� ����, ����ȭ������

				while (1)
				{
					menu_choice = main_menu();

					if (menu_choice == 1) {       // ���ٿ� ���� ����
						//���ٿ� ���� ȣ�� �ۼ��ϱ�
					}
					else if (menu_choice == 2) {  // �ϻ� ���� ����
						//�ϻ� ���� ȣ�� �ۼ��ϱ�
					}
					else if (menu_choice == 3) {  // û���� ���� ����
						//û���� ���� ȣ�� �ۼ��ϱ�
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
	char check_NULL[id_limit + 1] = { NULL, };

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
				if (strcmp(allPlayerList[i].id,check_NULL) == 0) { // ���ڸ� ã�Ƽ�
					strcpy(allPlayerList[i].id, id_temp); // ���ڸ��� ���̵� ����
					printf("��� ������ ���̵��Դϴ�.\n");
					printf("��й�ȣ�� �Է��ϼ���(4�ڸ� ����)\n");
					printf("�Է� : ");
					scanf("%s", allPlayerList[i].pw); // ��й�ȣ ����
					break;
				}
			}

			printf("����� �Ϸ�Ǿ����ϴ�.\n");
			
			break;
		}
	}
}

struct player logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL };
	char pw_temp[pw_limit + 1] = { NULL };
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

	printf("[���� �޴�]\n\n");
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

	printf("[��ŷ ��ȸ]\n\n");
	printf("(1) ���Ӻ� ��ŷ ��ȸ\n");
	printf("(2) ���� ��ŷ ��ȸ\n");
	printf("(3) �ڷΰ���\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

// ------------------------ Ʋ���׸�ã�� �Լ� ----------------------------------------------------------



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