#include <stdio.h>
#include <string.h>

void print_init_title(void);																								// �ʱ� ���θ޴��� ���̾ƿ� ����Լ�
void print_serch_title(void);																								// ��ȸ�޴��� ���̾ƿ� ����Լ�
void print_list(void);																										// �л��� ��ȣ�� ���� ����� ����ϴ� �Լ�
void print_list_all(void);																									// �������� �л����� �������� ���,������������ �������� ������ ����ϴ� �Լ�

char student_name[10][80] = { "�л�1","�л�2","�л�3","�л�4","�л�5","�л�6","�л�7","�л�8","�л�9","�л�10" };				// �ʱ� ��ϵǾ��ִ� �л��� �̸�
int student_grade[4][10] = {																								// �ʱ� ��ϵǾ��ִ� �л����� ���� ����
	{15,12,13,14,23,16,17,18,15,20},		// ����	
	{21,61,23,24,25,26,27,25,29,31},		// ����
	{61,37,55,34,35,41,37,38,86,60},		// ����
	{81,72,43,94,41,46,47,48,79,57}			// ����
};
int student_rank[10] = { 0 };																								// �л� ������ ������ũ �ʱⰪ
int select_menu_num = 0;																									// �޴����� �Է°� ���� �ӽ� ����
int select_student_name_for_revice = 0;																						// �̸��� ������ �л��� ��ȣ�� �Է¹��� ����
int select_student_grade_for_revice = 0;																					// ������ ������ �л��� ��ȣ�� �Է¹��� ����

char student_name_change[80];																								// ������ �̸��� �Է¹޴� ����												
int student_grade_change[4] = { 0 };																						// ������ ������ �Է¹޴� ����
char serch_student_name[80];																								// ��ȸ�� �л��� �̸��� �Է¹޴� ����
int check_for_same = 0;																										// ��ȸ�ϰ��� �ϴ� �л��� �̸��� �ִ��� ���� ���ϴ� �Լ�
int total_grade[10] = { 0 };																								// �л��� ����
double avg_grade[10] = { 0 };																								// �л��� ���																			
int temp = 0;																												// �ӽ�����(�ϰų� ���δ�) ����																		



int main(void)
{
	// ���� ���� C����� ��� ���������� �����Ͻø� �˴ϴ�.

	//	- ������ �л� ��
	//	10��

	//	- ������ �л��� ������
	//	�̸�(����), 4 ����(����, ����, ����, ����)�� ���� ����(����)

	//	- ���
	//	�л� ��� �� ����,
	//	���� ��� �� ����,
	//	�л� �̸����� ���� ��ȸ �� ���,
	//	��ü �л��� ������(����)���� ���,
	//	���� ��½� �������� �̸�, �����, ����, ���, ���� �� ���� ����� ��,
	//	�л� �� ���� ����� ����� �ǵ��� �� ��.

	//	- ������ ����� ��.
	//	���� �� ���������� ����ؼ� ������ ��.
	//	�̴�������Ʈ �ÿ� �������� ������ ��. (���忡 ������ ���� ����)

	// 0. �������
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			total_grade[i] = total_grade[i] + student_grade[j][i];			// ���� ���ϱ�
		}
		avg_grade[i] = total_grade[i] / 4;									// ��� ���ϱ�
	}

	for (int i = 0; i < 10; i++)											// ���� ���ϱ�
	{
		student_rank[i] = 11;												// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� - =�� ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� )
		for (int j = 0; j < 10; j++)										
		{
			if (total_grade[i] >= total_grade[j])							// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
				student_rank[i]--;											
		}
	}

	while (1)
	{
		print_init_title();
		printf("\n���ϴ� �޴��� �����Ͻʽÿ�. : ");
		scanf("%d", &select_menu_num);

		if (select_menu_num == 1)
		{
			// 1. �л� ��� �� ����
			// 1.1 ����Ʈ ��� �� ����Է¹ޱ�
			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
			while (1)
			{
				printf("\n��� �� ������ �л��� ��ȣ�� �Է��Ͽ� �ּ��� : ");
				scanf("%d", &select_student_name_for_revice);
				if (select_student_name_for_revice > 10 || select_student_name_for_revice < 0)
				{
					printf("�߸��� ���Դϴ�. �ٽ��Է��� �ּ���.");
				}
				else
				{
					printf("������ �̸��� �������ּ��� :");
					scanf("%s", student_name_change);
					break;
				}
			}

			// 1.2 ������ �̸� �Է¹ޱ�
			for (int i = 0; i < 80; i++)
			{
				student_name[select_student_name_for_revice-1][i] = student_name_change[i];
			}

			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
		} 

		else if (select_menu_num == 2)
		{
			// 2. ���� ��� �� ����
			// 2.1 ����Ʈ ��� �� ����Է¹ޱ�
			printf("\n������ ����Ʈ�Դϴ�.\n");
			print_list();
			while (1)
			{
				printf("\n��� �� ������ �л��� ��ȣ�� �Է��Ͽ� �ּ��� : ");
				scanf("%d", &select_student_grade_for_revice);
				if (select_student_grade_for_revice > 10 || select_student_grade_for_revice < 0)
				{
					printf("�߸��� ���Դϴ�. �ٽ��Է��� �ּ���.");
				}
				else
				{
					printf("\n������ �Է����ּ��� :");
					scanf("%d %d %d %d", &student_grade_change[0], &student_grade_change[1], &student_grade_change[2], &student_grade_change[3]);
					break;
				}
			}

			// 2.2 �Է¹��� ���� �����ϱ�
			for (int i = 0; i < 4; i++)
			{
				student_grade[i][select_student_grade_for_revice - 1] = student_grade_change[i];
			}

			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
		}

		else if (select_menu_num == 3)
		{
			// 3. ��ȸ

			while (1)
			{
				print_serch_title();
				printf("\n���ϴ� �޴��� �����Ͻʽÿ�. : ");
				scanf("%d", &select_menu_num);

				if (select_menu_num == 1)
				{
					// 3.1 �л��̸����� ��ȸ
					printf("��ȸ�ϰ��� �ϴ� �л��� �̸��� �Է��ϼ��� : ");
					scanf("%s", serch_student_name);

					// �̸� ���ڿ� ��
					while (1)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 80; j++)
							{
								if (serch_student_name[j] == student_name[i][j])
								{
									check_for_same++;
								}
							}
							if (check_for_same == 80)
							{
								printf("\n----------------------------------------------------------\n\n");
								printf("\t �̸�\t ����\t ����\t ����\t ����\n\n");
								printf(" %d��\t %s\t %d\t %d\t %d\t %d\t\n", i + 1, student_name[i], student_grade[0][i], student_grade[1][i], student_grade[2][i], student_grade[3][i]);
								printf("\n----------------------------------------------------------\n\n");
								break;
							}
							else
							{
								check_for_same = 0;
							}
						}
						break;
					}
				}

				else if (select_menu_num == 2)
				{
					// 3.2 ��ü�л����� ��ȸ
					print_list_all();
				}

				else if (select_menu_num == -1)
				{
					break;
				}
				else
				{
					printf("\n�߸��� ���� �Է��Ͽ����ϴ�. �ٽ��Է��ϼ���.\n");
				}
			}

			
		}


		else if (select_menu_num == -1)
		{
			// 4. ���α׷� ����
			break;
		}

		else
		{
			// 5. �߸��� �Է� ó��
			printf("\n�߸��� ���� �Է��Ͽ����ϴ�. �ٽ��Է��ϼ���.\n");
			select_menu_num = 0;
		}
	}
	




	return 0;
}

void print_init_title(void)
{
	// ���α׷� �ʱ�ȭ��( �޴� 0 )
	printf("\n\t === < �л����� �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n\n");
	printf(" 1)�л���� �� ���� \t2)������� �� ���� \t3)��ȸ \n");
	printf(" \n*�����Ͻ÷��� -1�� �Է����ּ���\n");
	printf("----------------------------------------------------------\n\n");


}

void print_serch_title(void)
{
	printf("\n\t === < �л����� �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n\n");
	printf(" 1)�л��̸����� ��ȸ \t2)��ü�л������ȸ \n");
	printf(" \n*���θ޴��� ���ư��÷��� -1�� �Է����ּ���\n");
	printf("----------------------------------------------------------\n\n");

}

void print_list(void)
{
	printf("\n----------------------------------------------------------\n\n");
	printf("\t �̸�\t ����\t ����\t ����\t ����\n\n");

	for (int j = 0; j < 10; j++)
	{
		printf(" %d��\t %s\t %d\t %d\t %d\t %d\t\n", j+1, student_name[j], student_grade[0][j], student_grade[1][j], student_grade[2][j], student_grade[3][j]);
	}
	printf("\n----------------------------------------------------------\n\n");
	
}

void print_list_all(void)
{
	// ���������� �������� ���(�� ���������� ����ϸ� ��)
	printf("\n----------------------------------------------------------\n\n");
	printf("\t �̸�\t ����\t ����\t ����\t ����\t ����\t ���\t ����\n\n");


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (student_rank[j] == i + 1)
				printf(" %d��\t %s\t %d\t %d\t %d\t %d\t %d\t %lf\t %d\t\n", j + 1, student_name[j], student_grade[0][j], student_grade[1][j], student_grade[2][j], student_grade[3][j], total_grade[j], avg_grade[j], student_rank[j]);

		}
	}
	printf("\n----------------------------------------------------------\n\n");

}