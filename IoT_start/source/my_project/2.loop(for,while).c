#include <stdio.h>

int main_loop(void)
{
	/* �Ϸ��Ѱ� �ּ�ó���� - �̰� ����� ��
	
	// ++
	int a = 10;
	printf("a�� %d\n", a);
	a++;
	printf("a�� %d\n", a);
	a++;
	printf("a�� %d\n", a);
	a++;

	int b = 20;
	printf("b�� %d\n", ++b); // �տ� ++�� ������ ���� +1�� �����ϰ� ���� ����
	printf("b�� %d\n", b++); // �ڿ� ++�� ������ ���� ���� �����ϰ� +1�� ����
	printf("b�� %d\n", b);


	printf("----------------------------------\n");
	// �ݺ���
	// for, while, do while

	// for(����; ����; ����) {�����} ��
	// ������ ���̸� ����� �����ϰ� �����θ� �����Ѵ�
	for (int i = 1; i <= 10; i++)
	{
		printf("Hello World %d\n", i);
	}

	// while (����) {�����}
	// ����ΰ� ������ �̸� �μ��� �����ؾ��� + ������ ���̸� ����� ����
	int i = 1;
	while (i <= 10)
	{
		printf("Hello World %d\n", i++);
	}

	// do {�����} while (����)
	int j = 1;
	do {
		printf("Hello World %c\n", j++);
	} while (j <= 10);
	printf("----------------------------------\n");

	// ���� �ݺ���
	for (int i = 1; i <= 3; i++)
	{
		printf("ù��° �ݺ���  : %d\n", i);
		 
		for (int j = 1; j <= 5; j++)
		{
			printf("   �ι�° �ݺ��� : %d\n", j);
		}
	}

	// ������
	for (int i = 1; i <= 9; i++)
	{
		printf("%d��\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

	// �����ﰢ�� �����
	int length = 8; // �����ﰢ�� �غ�ũ�� (�����δ� �̵ �ﰢ�������� ���â���� ������ ���ΰ� ��)
	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	// �����ﰢ��(�¿����)
	int length = 5;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");

	}
		printf("----------------------------------\n");

		�Ϸ��Ѱ� �ּ�ó���� - �̰� ����� �� */

	// ������Ʈ
	// �Ƕ�̵� �ױ� ������Ʈ �ۼ�
	int floor;
	printf("�� ������ �װڴ���? : ");
	scanf_s("%d", & floor);
	for (int i = 0; i < floor; i++) 
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;

}