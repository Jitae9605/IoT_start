#define _CRT_SECURE_NO_WARNINGS // c���� fopen�� �ſ� �����ؼ� ������ �̸� ����ϴ� ������ �����ϰ� ���ش�
#include <stdio.h>

// ������Ʈ 
// [����ϱ�]
// ��й�ȣ�� �Է¹޾Ƽ�
// �������, ����ϱ�(txt)�� �о�ͼ� �����ְ� ��� �ۼ� ����
// Ʋ�����, ��� �޼��� ǥ���ϰ� ����

#define MAX 10000
 
int main321(void)
{
	// fgets, fputs Ȱ��
	char line[MAX]; // ���Ͽ��� �ҷ��� ���� ������ ����(����)
	char contexts[MAX]; // �ϱ��忡 �Է��� ����
	char password[20]; // ��й�ȣ �Է�
	char c; // ��й�ȣ �Է��Ҷ� Ű�� Ȯ�ο�(���������� '*'ǥ ���ȿ�� = ����ŷ)

	printf("'����ϱ�'�� ���� ���� ȯ���մϴ�\n");
	printf("��й�ȣ�� �Է��ϼ��� : ");

	int i = 0; // �н����带 �Է¹޴� �Լ�
	while(1)
	{
		// ! getchar() / getch()�� ���� !
		// getchar() = ���͸� �Է¹޾ƾ� ������
		// getch() = Ű �Է� �� �ٷιٷ� ������
		c = getch();

		if (c == 13) // 13�� 'Enter'�� ��Ÿ���� �ƽ�Ű�ڵ�
					 // Enter -> ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}

		else // ��й�ȣ �Է���
		{
			printf("*");
			password[i] = c;
		}
		i++; // Ű�� ������ ���� '*' �� ��µǰ� 
			 // 'c'�� ���� ����Ǿ� 'Enter'�� �Է��� ����
	}

	// ��й�ȣ : �����ڵ� = skehzheld
	printf("\n\n === ��й�ȣ Ȯ�� �� ... === \n\n");

	// srrcmp(A, B) = A�� ���� B�� ���� ��ġ�ϸ� '0'�� ��ȯ
	if (strcmp(password, "skehzheld") == 0) // ��й�ȣ ��ġ �Ǵ�
	{
		printf(" === ��й�ȣ Ȯ�� �Ϸ� ===\n\n");
		char* fileName = "d:\\secretdiaty.txt";
		FILE* file = fopen(fileName, "a+b");
		// = ������ ������ ����, ������ append(�ڿ������� �����߰�)�� �Ѵ�.

		// ���Ͽ��� ������ ��� ���
		if (file == NULL)
		{
			printf("���� ���� ����\n");
			return 1;
		}

		// ���Ͽ��� ������ ��� ������ ���� ������ ������ �������
		// fgets�Լ��� ���� line�� file�� ������ �����´�(���پ�)
		while (fgets(line, MAX, file) != NULL) // ������ ������ ������ ����
		{
			printf("%s", line); // ������ ������ �ݺ����
		}

		// �̾ �ۼ� �� ���������� ���
		printf("\n\n ������ ��� �ۼ��ϼ���! �����Ϸ��� EXIT�� �Է��ϼ���.\n\n");

		while (1)
		{
			scanf("%[^\n]", contexts); // �� ��(= �ٹٲ�)�� ���ö����� �о�鿩��� �ǹ�
			getchar(); // Enter�Է�(\n)��  Flushó��(= ���� or ����)

			// �Էµ� ������ EXIT�������� Ȯ��
			if (strcmp(contexts, "EXIT") == 0)
			{
				printf("����ϱ� �Է��� �����մϴ�\n\n");
				break;
			}
			fputs(contexts, file);
			fputs("\n", file); // getchar()�� ���� �Է¹��� Enter�� �ѹ� ����������
							   //�̸� �����ؾ� �Է��� ��� ����ȴ�
		}
		fclose(file);
	}
	else // ��й�ȣ Ʋ�����
	{
		printf(" === ��й�ȣ Ʋ�� === \n\n");
		printf("���� �ź� ó���Ǿ����ϴ�!\n\n\n");
	}

	return 0;
}