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
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	printf("파일이 열렸습니다.\n");


	int i = 0;

	
	while (1)
	{
		printf("\n=== 날씨 데이터 입력 ===\n\n");

		printf("날짜 : ");
		date_1 = scanf("%d", &date);
		if (date_1 == EOF) break;
		/*fprintf(fp_1, "%d\n", date);
		getchar();*/
		// 이렇게 하면 나중에 읽어올때 fscanf빼고는 무조건 문자열로 입력값을 가져와야함
		// fwrite를 쓰고 fread로 읽어야한다
		 fwrite(&date, sizeof(int), 1, fp_1);
		 getchar();
		 fputs("\n", fp_1);


		printf("지역 : ");
		fgets(region, sizeof(region), stdin);
		fputs(region, fp_1);


		printf("오전/오후 : ");
		scanf("%c", &AM_PM);
		fputc(AM_PM, fp_1);
		fputc('\n', fp_1);
		getchar();

		printf("날씨 : ");
		fgets(weather,sizeof(weather),stdin);
		fputs(weather, fp_1);

		fputs("\n", fp_1);
	
	}
	
	fclose(fp_1);



	return 0;
}

