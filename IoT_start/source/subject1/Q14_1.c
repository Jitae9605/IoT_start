#include <stdio.h>
#include <string.h>


int main(void)
{
	FILE* fp_1;
	int date = 0;
	char region[20];
	char AM_PM;
	char weather[80];
	char date_1;


	fp_1 = fopen("source\\subject1\\Temp\\weather.dat", "w");
	if (fp_1 == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}

	printf("������ ���Ƚ��ϴ�.\n");


	int i = 0;

	
	while (1)
	{
		printf("\n=== ���� ������ �Է� ===\n\n");

		printf("��¥ : ");
		date_1 = scanf("%d", &date);
		if (date_1 == EOF) break;
		/*fprintf(fp_1, "%d\n", date);
		getchar();*/
		// �̷��� �ϸ� ���߿� �о�ö� fscanf����� ������ ���ڿ��� �Է°��� �����;���
		// fwrite�� ���� fread�� �о���Ѵ�
		 fwrite(&date, sizeof(int), 1, fp_1);
		 getchar();
		 fputs("\n", fp_1);


		printf("���� : ");
		fgets(region, sizeof(region), stdin);
		fputs(region, fp_1);


		printf("����/���� : ");
		scanf("%c", &AM_PM);
		fputc(AM_PM, fp_1);
		fputc('\n', fp_1);
		getchar();

		printf("���� : ");
		fgets(weather,sizeof(weather),stdin);
		fputs(weather, fp_1);

		fputs("\n", fp_1);
	
	}
	
	fclose(fp_1);



	return 0;
}

