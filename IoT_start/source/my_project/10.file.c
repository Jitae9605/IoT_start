#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000 // MAX ��� ���ڸ� 10000 ���� �����Ѵ�


int main_file(void)
{
	/* �Ϸ��Ѱ� �ּ�ó���� - �̰� ����� ��
	
	// 1. fputs, fgets �� -> ���ڿ� ����/�ҷ����� �� �ַ� ���

	// 1) ���Ͽ� ����
	// ���Ͽ� � �����͸� ����, �ҷ����� ���

	char line[MAX]; // = char line[10000];
	FILE * file = fopen("D:\\test1.txt", "wb"); // ��������'\'�� ����ϰ� ������ 2�������'\\'

	// ������ �д� ��Ŀ��� r, w, a�� �ִ� r = read(�б�) w = ����, a = ����(������ ����)
	// �д� ��� �ڿ��� t, b�� �ٴµ� �̴� ������ �������� t = text, b = binary�̴�.

	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	fputs("fputs �� �̿��ؼ� ���� ���� ���Կ�\n", file);
	fputs("�� �������� Ȯ���� �ּ���\n", file);

	// ������ ���� ���� ���� ���¿��� � ���α׷����� ������ �߻��ϸ� ������ �ջ�߻�!!!!
	// �׻� ������ �ݾ��ִ� ������ �ʿ���!

	printf("----------------------------------\n");

	fclose(file);



	// 2) ���� �б�
	char line[MAX]; // = char line[10000];
	FILE* file = fopen("D:\\test1.txt", "rb"); // �о���� �Ŵϱ� 'r'

	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}
	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}


	fclose(file);

	printf("----------------------------------\n");
	
	�Ϸ��Ѱ� �ּ�ó���� - �̰� ����� �� */


	// 2. fprintf, fscanf �� -> ����ȭ�� ���信�� �а� ���⿡ ����ȭ
	// printf("%d %d %s ... )
	// scanf("$d %d", &num1 ... ) 

	char line[MAX]; // = char line[10000];
	int num[6] = { 0,0,0,0,0,0 }; // ��÷��ȣ
	int bonus = 0; // ���ʽ� ��ȣ
	char str1[MAX];
	char str2[MAX];

	// ���� ����
	//FILE* file = fopen("d:\\test2.txt", "wb");

	//if (file == NULL)
	//{
	//	printf("���� ���� ����\n");
	//	return 1;
	//}

	//// �ζ� ��÷ ��ȣ ����
	//fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);


	// �����б�
	FILE* file = fopen("d:\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	fscanf(file, "%s %d %d %d %d %d %d %d", str1,
		&num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1,
		num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);


	fclose(file);

	return 0;
}