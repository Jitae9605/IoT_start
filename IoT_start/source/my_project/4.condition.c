#include <stdio.h>
#include <time.h>

int main_condition(void)
{
	/* �Ϸ��Ѱ� �ּ�ó���� - �̰� ����� ��
	���Ǻ� = if, else, else if 
	
	// ������ ź�ٰ� ���� �л�,�Ϲ��� ���� ���� (�Ϲ��� :20��)
	int age = 15;

	if (age >= 20)
		printf("�Ϲ����Դϴ�.\n");
	else
		printf("�л��Դϴ�.\n");


	printf("----------------------------------\n");	



	// �ʵ��л� (8~13) / ���л�(14~16) / ����л� (17~19)
	int age;
	printf("�� ���̽Ű���? : ");
	scanf_s("%d", &age);

	if (age >= 8 && age <= 13)
	{
		printf("�ʵ��л��Դϴ�.\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("���л��Դϴ�.\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("����л��Դϴ�.\n");
	}
	else
		printf("û�ҳ��� �ƴմϴ�.\n");

	printf("----------------------------------\n");

	

	// break
	// 1������ 30������ �ִ� �ݿ��� 1������ 5������ ������ǥ ����
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("������ �л��� ���� ������\n");
			break;
		}
		printf("%d �� �л��� ������ǥ �غ� �ϼ���\n", i);
	}

	printf("----------------------------------\n");

	// continue
	// 1������ 30������ �ִ� �ݿ��� 7�� �л��� �Ἦ
	// 7���� ������ 6������ 10������ �������� ����
	
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d �� �л��� �Ἦ�Դϴ�.\n", i);
				continue;
			}
			printf("%d �� �л��� ���� ��ǥ �غ� �ϼ���\n", i);
		}
	}

	printf("----------------------------------\n");

	// �� ������ &&, ||
	// and = &&  / or = || / == = ��ġ
	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	
	if (a == b || c == d)
	{
		printf("a �� b �� ���ų�, c �� d �� �����ϴ�.\n");
	}
	else
	{
		printf("���� ���� �ٸ��׿�\n");
	}

	printf("----------------------------------\n");


	// ���� 0 ���� 1 �� 2 ���α׷�
	
	// 1. ������ if�� �̿�
	srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 ������ ����
	if (i == 0)
	{
		printf("����\n");
	}
	else if (i == 1)
	{
		printf("����\n");
	}
	else
	{
		printf("��\n");
	}


	// 2. switch�� �̿�
	// switch(���)
	// {
	//	case ����� ��1: ����; break;
	//   ...
	//  case ����� ��n: ����; break;
	//  default:����; break;          // case�� �������� ������ �ٸ� ��� ��
	//	}

	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
	case 0:printf("����\n"); break;
	case 1:printf("����\n"); break;
	case 2:printf("��\n"); break;
	default:printf("��?��\n"); break;
	}
	// switch���� case�� �ϳ� ��ġ�ϸ� �� ���� ��� ���̽��� ������ ���� ���� �����Ѵ�.
	// �̸� �������� break;�� ���� �ƴϸ� ����ȴ�.
	
	// switch�� ��ȭ
	// ���� ������ ���� �з�
	// �ʵ��л�(8~13) / ���л�(14~16) / ����л�(17~19)

	int age;
	printf("�� ���̽Ű���? : ");
	scanf_s("%d", &age);

	switch (age)
	{
	case 8:
	case 9:
	case 10: 
	case 11: 
	case 12:
	case 13:printf("�ʵ��л��Դϴ�.\n"); break;
	case 14:
	case 15:
	case 16:printf("���л��Դϴ�.\n"); break;
	case 17:
	case 18:
	case 19:
	default:printf("�л��� �ƴմϴ�.\n"); break;
	}
	// ���� ������ switch���� �� ������ case�� ��� ����θ� �����Ѵ� 
	// �̸� �̿��� ����� ������ ������� �׿����� ��³���� break;�� ������ �Ἥ
	// �����ϰ� ��������

	printf("----------------------------------\n");
	�Ϸ��Ѱ� �ּ�ó���� - �̰� ����� �� */

	// ������Ʈ
	// Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100 ������ ������ ����
	printf("���� : %d\n", num);
	int answer = 0; // ����
	int chance = 5; // ���� ��ȸ
	while (1) // 0�� ���� 1�� ������ �̷��� �ϸ� while�� ������ ���̴�.
	{
		printf("���� ��ȸ %d �� \n", chance--);
		printf("���ڸ� ���纸���� (1 ~ 100) : ");
		scanf_s("%d", &answer);

		if (answer > num)
		{
			printf("Down ��\n\n");
		}
		else if (answer < num)
		{
			printf("Up ��\n\n");
		}
		else if (answer == num)
		{
			printf("�����Դϴ�! \n\n");
			break;
		}
		else
		{
			printf("�� �� ���� ������ �߻��Ͽ����ϴ�.\n\n");
		}

		if (chance == 0)
		{
			printf("��� ��ȸ�� �� ����Ͽ����ϴ�. �ٽ� ������ ������\n");
				break;
		}

	}
	
	return 0;
}