#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define How_Many_Time_Play_Game 1									// ���� �ݺ� Ƚ��
#define Length_of_Array 5											// �迭 ����(x)
#define Height_of_Array 5											// �迭 ����(y)
#define Over_the_Time_limit -1										// �ð������� �Ѱ����� ����� ��
#define Succes_to_Login 1											// �α��� ����

#define id_limit 12													// id�� �����Ѱ�
#define pw_limit 4													// pw�� �����Ѱ�
#define game 4														// 1.up/down 2.�ϻ� 3.û���� 4.Ʋ���׸�ã��
#define max_player 10												// �ִ� �÷��̾� ���

void Print_diff_Mainmenu(void);										// ���θ޴� ��� �Լ�
int Cal_Score(int Set_endTime);										// ���ھ� ��� �Լ�
int Make_Random_Num(int Random_Num_Range);							// ������� �Լ�
int Make_Random_Num_Range(int from, int end);						// Ư�������� ���� ����Լ�
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// Ʋ���׸�ã�� �� ���
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// ���� �Է¹޾� Ȯ��
int Print_Final_Score(int Score[How_Many_Time_Play_Game]);			// �������� ��� �Լ�



// -------------------------------------- ����ü -----------------------------------


struct score	// [���� ���� ����ü]
{   
	int upDown;  // ���ٿ� ����
	int cal;     // �ϻ� ����
	int BW;      // û���� ����
	int spot;    // Ʋ���׸� ã��
	int total;   // ���� ����
};

struct player				 // [�÷��̾� ���� ���� ����ü]
{
	struct score sc;		 // score ����ü�� ����� ���
	char id[id_limit + 1];   // ���̵�
	char pw[pw_limit + 1];   // ��й�ȣ
	int rank;                // ��ŷ
	int join;                // ��� ����
};


// -------------------------------------- ���� ---------------------------------------

int main(void)
{
	// ����ü ���
	struct player p[max_player] = { 0, };

	// ���� �ʱ�ȭ
	srand(time(NULL));

	// ��������
	char Check_id[id_limit + 1] = { 0 };
	char Check_pw[pw_limit + 1] = { 0 };
	int check_for_same = 0;
	int check_for_success_to_login = 0;
	int score[How_Many_Time_Play_Game] = { 0 };		// ���� ���� �� ����
	int Final_Score = 0;							// ��������
	int Judg_num = 0;								// ���ѽð� �Ѱ��� ��� �������� ����
	int Select_diff_main_menu = 0;					// �޴����� ������ ����
	int Select_diff_ResetMenu = 0;					// �ʱ�ȭ�޴� ������ ����
	int Select_diff_RankingMenu = 0;				// ��ŷȮ�θ޴� ������ ����
	int Rank_num_diff[max_player] = { 0 };			// ��ü��ŷ ���
	int Curent_id_num = 0;							// ���� �α��ε� ���̵��� ��ȣ
	int original_array[Length_of_Array][Height_of_Array] = { 0 };		// �������� ���� ���ڵ��� �����ϴ� �迭
	int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original�� �ٸ� �κ��� ����� ������ �迭


	//------------------ ��ŷ�ý��� Ȯ���� ���� �ӽ� ����ü �����Է� -----------------------

	for (int i = 0; i < max_player; i++)
	{
		strcpy(p[i].pw, "0000");
		p[i].sc.spot = (rand() % 10000);
		p[i].sc.total += p[i].sc.spot;
	}

	strcpy(p[0].id, "���̵�0");
	strcpy(p[1].id, "���̵�1");
	strcpy(p[2].id, "���̵�2");
	strcpy(p[3].id, "���̵�3");
	strcpy(p[4].id, "���̵�4");
	strcpy(p[5].id, "���̵�5");
	strcpy(p[6].id, "���̵�6");
	strcpy(p[7].id, "���̵�7");
	strcpy(p[8].id, "���̵�8");
	strcpy(p[9].id, "���̵�9");

	// -------------------------------------------------------------------------------


	//------------------------- �α��� --------------------------------------------------

	while (1)
	{
		// �α���
		printf("���̵� �Է� : ");
		scanf("%s", Check_id);

		printf("��� �Է� : ");
		scanf("%s", Check_pw);

		// �Է¹��� id �� pw�� ��ġ�ϴ��� Ȯ��
		for (int i = 0; i < id_limit; i++)
		{
			if (strcmp(Check_id, p[i].id) == 0 && strcmp(Check_pw, p[i].pw) == 0)
			{
				system("cls");
				Curent_id_num = i;
				printf("\n\t === ȯ���մϴ�. %s�� === \t\t\n", p[i].id);
				check_for_success_to_login = Succes_to_Login;
				break;
			}
		}

		// �α��� �����ϸ� �ݺ���(while)Ż��
		if (check_for_success_to_login == Succes_to_Login) break;

		printf("�Է��Ͻ� ������ ��ġ�ϴ� id�� pw�� �߰����� ���߽��ϴ�. �ٽ� Ȯ�����ּ���.\n");
	}
	// ------------------------------------------------------------------------------------------------------

	// ------------------------------ �α��� ������ ���α׷� �۵��� --------------------------------------------
		while (1)
		{
			Print_diff_Mainmenu();										// �޴� ���̾ƿ� ���
			printf(" ���ϴ� �޴��� ��ȣ�� �Է��ϼ���\n");					// �޴� ����
			scanf("%d", &Select_diff_main_menu);						// ��������� �޴� �Է¹���

			if (Select_diff_main_menu == 1)
			{
				// 1. ���� �����
				system("cls");

				for (int q = 0; q < How_Many_Time_Play_Game; q++)			// Ʋ���׸�ã����� �ݺ�Ƚ��
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


					// different_array�迭�߿� Ʋ�� �κ��� ���� �ֱ�
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
					Final_Score = Print_Final_Score(score);
					p[Curent_id_num].sc.spot = Final_Score;											// �÷��̾� ��Ͽ� ���ھ� �߰�
					printf("\n=========================================\n");
					printf("\n %s���� ���� ������ < %d > ���Դϴ�\n", p[Curent_id_num].id, Final_Score);
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
						p[Curent_id_num].sc.spot = 0;
						printf(" �ʱ�ȭ �Ǿ����ϴ�.");
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
						printf("\n %s ���� Ʋ���׸�ã�� ����� < %d > ���Դϴ�.\n\n", p[Curent_id_num].id, p[Curent_id_num].sc.spot);
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
							Rank_num_diff[i] = 11;											// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
							for (int j = 0; j < max_player; j++)
							{
								if (p[i].sc.spot >= p[j].sc.spot)							// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
									Rank_num_diff[i]--;
							}
						}

						for (int i = 0; i < max_player; i++)
						{
							for (int j = 0; j < max_player; j++)
							{

								if (Rank_num_diff[j] == i + 1)
									printf(" %2d��\t %s\t %5d\n", Rank_num_diff[j], p[j].id, p[j].sc.spot);

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

		return 0;
}



// ------------------------ �Լ� ----------------------------------------------------------



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

// ���� ���ھ� ���
int Print_Final_Score(int Score[How_Many_Time_Play_Game])
{
	int final_score = 0;
	for (int i = 0; i < How_Many_Time_Play_Game; i++)
	{
		final_score = final_score + Score[i];
	}
	return final_score;
}

// ���θ޴� ���
void Print_diff_Mainmenu(void)
{
	printf("\n===============================================\n");
	printf("\t\t Ʋ�� �׸� ã�� \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. ����\n\n\t\t 2. �ʱ�ȭ\n\n\t\t 3. ��ŷȮ��\n\n\t\t 4. �ڷ�\n\n");
	printf("\n===============================================\n");
}