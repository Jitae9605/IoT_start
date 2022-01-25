#include <stdio.h>
#include <string.h>

void print_init_title(void);
void print_reg_title(void);
void print_list(void);

char student_name[10][80] = { "�л�1","�л�2","�л�3","�л�4","�л�5","�л�6","�л�7","�л�8","�л�9","�л�10" };
int student_grade[4][10] = {
	{11,12,13,14,15,16,17,18,19,20},		// ����
	{21,22,23,24,25,26,27,28,29,30},		// ����
	{31,32,33,34,35,36,37,38,39,40},		// ����
	{41,42,43,44,45,46,47,48,49,50}		// ����
};
int select_menu_num = 0;
int select_student_name_for_revice = 0;
int select_student_grade_for_revice = 0;

char student_name_change[80];
int cnt = sizeof(student_name) / sizeof(student_name[0]);
int student_grade_change[4] = { 0 };


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
	//	��ü �л��� ���������� ���,
	//	���� ��½� �������� �̸�, �����, ����, ���, ���� �� ���� ����� ��,
	//	�л� �� ���� ����� ����� �ǵ��� �� ��.

	//	- ������ ����� ��.
	//	���� �� ���������� ����ؼ� ������ ��.
	//	�̴�������Ʈ �ÿ� �������� ������ ��. (���忡 ������ ���� ����)


	while (1)
	{
		print_init_title();
		printf("���ϴ� �޴��� �����Ͻʽÿ�. : ");
		scanf("%d", &select_menu_num);

		if (select_menu_num == 1)
		{
			// �л� ��� �� ����
			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
			printf("\n��� �� ������ �л��� ��ȣ�� �Է��Ͽ� �ּ��� : ");
			scanf("%d", &select_student_name_for_revice);
			printf("������ �̸��� �������ּ��� :");
			scanf("%s", student_name_change);
			
			// �̸� ����
			for (int i = 0; i < 80; i++)
			{
				student_name[select_student_name_for_revice-1][i] = student_name_change[i];
			}

			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
		} 

		else if (select_menu_num == 2)
		{
			// ���� ��� �� ����
			printf("\n������ ����Ʈ�Դϴ�.\n");
			print_list();
			printf("\n��� �� ������ �л��� ��ȣ�� �Է��Ͽ� �ּ��� : ");
			scanf("%d", &select_student_grade_for_revice);
			printf("\n������ �Է��� �������ּ��� :");
			scanf("%d %d %d %d", &student_grade_change[0], &student_grade_change[1], &student_grade_change[2], &student_grade_change[3]);

			// ��������
			for (int i = 0; i < 4; i++)
			{
				student_grade[i][select_student_grade_for_revice - 1] = student_grade_change[i];
			}

			printf("������ ����Ʈ�Դϴ�.\n");
			print_list();
		}

		else if (select_menu_num == 2)
		{
			// ��ȸ
		}

		else
		{
			printf("�߸��� ���� �Է��Ͽ����ϴ�. �ٽ��Է��ϼ���.\n");
			select_menu_num = 0;
		}
	}
	




	return 0;
}

void print_init_title(void)
{
	// ���α׷� �ʱ�ȭ��( �޴� 0 )
	printf("\t === < �л����� �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n");
	printf(" 1)�л���� �� ���� \t2)������� �� ���� \t3)��ȸ \n");
	printf("----------------------------------------------------------\n");


}

void print_reg_title(void)
{
	printf("\n\t === < �л����� �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n");

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