#include<stdio.h>
/*
문제 2) "문제 1"에서 저장한 "weather.dat" 파일에 저장되어 있는 내용을
모두 읽어서 모니터에 출력하는 프로그램을 작성하세요.

실행 예)
날짜 : 20220201
지역 : 부산
오전 / 오후 : A
날씨 : 오후 늦게 곳에 따라 비
*/
int main(void)
{
	FILE* fp_1;
	char str_6[80];
	int date;

	fp_1 = fopen("source\\subject1\\Temp\\weather.dat", "r");				// 읽기 가능한 추가보드로 개방
	if (fp_1 == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	
	fseek(fp_1, 0, SEEK_SET);				// fseek함수를 이용해 위치지시자를 문서의 맨앞으로 옮김 (*참고1 항목참고)
	while (1)
	{
		//fread 사용 - 지금쓰면 당연히 안됨 레이아웃이랑 개행문자처리 안했으니까
	
		//fread(&date, sizeof(int), 1, fp_1);
		//if (feof(fp_1) != 0)
		//	break;
		//fprintf(stdout, "날짜: %d \n", date);

		fgets(str_6, sizeof(str_6), fp_1);
		printf("날짜 : ");
		printf("%s", str_6);				// 파일내용 출력(a+ - 읽기)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("지역 : ");
		printf("%s", str_6);				// 파일내용 출력(a+ - 읽기)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("오전/오후 : ");
		printf("%s", str_6);				// 파일내용 출력(a+ - 읽기)

		fgets(str_6, sizeof(str_6), fp_1);
		printf("날씨 : ");
		printf("%s", str_6);				// 파일내용 출력(a+ - 읽기)
		getchar();

		fgets(str_6, sizeof(str_6), fp_1);
		if (feof(fp_1))						// 파일을 끝까지 다읽었는지 체크
		{
			break;
		}

		
	}


	

	fclose(fp_1);

	return 0;
}