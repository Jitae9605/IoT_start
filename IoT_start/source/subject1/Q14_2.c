#include<stdio.h>
/*
���� 2) "���� 1"���� ������ "weather.dat" ���Ͽ� ����Ǿ� �ִ� ������
��� �о ����Ϳ� ����ϴ� ���α׷��� �ۼ��ϼ���.

���� ��)
��¥ : 20220201
���� : �λ�
���� / ���� : A
���� : ���� �ʰ� ���� ���� ��
*/
int main(void)
{
	FILE* fp_1;
	char str_6[80];
	int date;

	fp_1 = fopen("source\\subject1\\Temp\\weather.dat", "r");				// �б� ������ �߰������ ����
	if (fp_1 == NULL)
	{
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	
	fseek(fp_1, 0, SEEK_SET);				// fseek�Լ��� �̿��� ��ġ�����ڸ� ������ �Ǿ����� �ű� (*����1 �׸�����)
	while (1)
	{
		//fread ��� - ���ݾ��� �翬�� �ȵ� ���̾ƿ��̶� ���๮��ó�� �������ϱ�
	
		//fread(&date, sizeof(int), 1, fp_1);
		//if (feof(fp_1) != 0)
		//	break;
		//fprintf(stdout, "��¥: %d \n", date);

		fgets(str_6, sizeof(str_6), fp_1);
		printf("��¥ : ");
		printf("%s", str_6);				// ���ϳ��� ���(a+ - �б�)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("���� : ");
		printf("%s", str_6);				// ���ϳ��� ���(a+ - �б�)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("����/���� : ");
		printf("%s", str_6);				// ���ϳ��� ���(a+ - �б�)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("���� : ");
		printf("%s", str_6);				// ���ϳ��� ���(a+ - �б�)
		getchar();

		fgets(str_6, sizeof(str_6), fp_1);
		if (feof(fp_1))						// ������ ������ ���о����� üũ
		{
			break;
		}

		
	}


	

	fclose(fp_1);

	return 0;
}