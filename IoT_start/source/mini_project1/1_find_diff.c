#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define How_Many_Time_Play_Game 5									// ���� �ݺ� Ƚ��
#define Length_of_Array 5											// �迭 ����(x)
#define Height_of_Array 5											// �迭 ����(y)
#define Over_the_Time_limit -1										// �ð������� �Ѱ����� ����� ��

int Cal_Score(int Set_endTime);										// ���ھ� ���
int Make_Random_Num(int Random_Num_Range);							// ��������Լ�
int Make_Random_Num_Range(int from, int end);						//Ư�������� ���� ����Լ�
void Print_Bingo(int original_array[Length_of_Array][Height_of_Array], int different_array[Length_of_Array][Height_of_Array]);	// Ʋ���׸�ã�� �� ���
void Check_Answer(int Where_is_diff_x, int Where_is_diff_y);		// ���� �Է¹޾� Ȯ��
int Print_Final_Score(int Score[How_Many_Time_Play_Game]);

// -------------------------------------- ���� ----------------------------------

int main(void)
{
	// ���� �ʱ�ȭ
	srand(time(NULL));
	
	// ���� ����
	int score[How_Many_Time_Play_Game] = { 0 };
	int Final_Score = 0;
	
	// ���� �����
	for (int q = 0; q < How_Many_Time_Play_Game; q++)
	{

		// �ɸ� �ð� ���
		long StartTime = 0; // ���ӽ��� �ð� ����
		long totlaElapsedTime = 0; // �� ����ð� ����
		StartTime = clock(); // ���ӽ��� �ð��� 
	
		// �迭 ����
		int original_array[Length_of_Array][Height_of_Array] = { 0 };		// �������� ���� ���ڵ��� �����ϴ� �迭
		int different_array[Length_of_Array][Height_of_Array] = { 0 };		// original�� �ٸ� �κ��� ����� ������ �迭



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
		int Whats_diffent = 0;												// Ʋ�� �� ����
		int Where_is_diff_x = Make_Random_Num(Length_of_Array);							// Ʋ���κ� x��ǥ
		int Where_is_diff_y = Make_Random_Num(Height_of_Array);							// Ʋ���κ� y��ǥ

		Whats_diffent = Make_Random_Num_Range(33, 126);						// Ʋ�� ���� ������ �޾Ƽ� ����
		while (different_array[Where_is_diff_x][Where_is_diff_y] == Whats_diffent)		// ������ ������ ���� Ȥ�� Ʋ���κ��� ��ǥ�� �ش��ϴ� �迭�κа� ���� �ʴ��� Ȯ��
		{
			Whats_diffent = Make_Random_Num_Range(33, 126);								// ���� ������ ���� �ݺ�
		}
	
		different_array[Where_is_diff_x][Where_is_diff_y] = Whats_diffent;				// ���� �����ϱ� ���Կ���


		// ȭ�鿡 Ʋ���׸� ã�� ���� ���
		Print_Bingo(original_array, different_array);									// Ʋ���׸�ã���� ���
		Check_Answer(Where_is_diff_x, Where_is_diff_y);									// �����Է¹޾� �������� Ȯ���ϰ� �ȳ��� ���


		score[q] = Cal_Score(StartTime);												// ���� ���
		if (score[q] == Over_the_Time_limit)
		{
			break;
		}
		system("PAUSE");
		system("cls");
	}
	
	// �������ھ� �ջ�
	Final_Score = Print_Final_Score(score);
	printf("\n=========================================\n");
	printf("\n(�÷��̾� �̸�)���� ���� ������ %d �Դϴ�\n", Final_Score);
	printf("\n=========================================\n");




	return 0;
}

// ------------------------ �Լ� ----------------------------------------------------------



// �ɸ� �ð��� ���� ���� ����
// �⺻�� 100���� �Ͽ� (�ɸ��ð�*2)��ŭ�� 100���� ����
int Cal_Score(int StartTime)
{
	int Score = 100;
	int totalElapsedTime = (clock() - StartTime) / CLOCKS_PER_SEC; // ������ �ð�
	printf("\n�ɸ� �ð��� %d �� �Դϴ�.\n ", totalElapsedTime);

	Score = Score - (totalElapsedTime * 2);

	if (Score < 0)
	{
		printf("��! ���ѽð��� �Ѱ���ϴ�. ������ �ٽ� �������ּ���!");
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

