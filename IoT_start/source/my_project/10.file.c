#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000 // MAX 라는 글자를 10000 으로 정의한다


int main_file(void)
{
	/* 완료한거 주석처리용 - 이거 지우면 됨
	
	// 1. fputs, fgets 쌍 -> 문자열 저장/불러오기 에 주로 사용

	// 1) 파일에 쓰기
	// 파일에 어떤 데이터를 저장, 불러오는 방법

	char line[MAX]; // = char line[10000];
	FILE * file = fopen("D:\\test1.txt", "wb"); // 역슬래시'\'를 사용하고 싶으면 2개써야함'\\'

	// 파일을 읽는 방식에는 r, w, a가 있다 r = read(읽기) w = 쓰기, a = 수정(없으면 만듬)
	// 읽는 방식 뒤에는 t, b가 붙는데 이는 파일의 형식으로 t = text, b = binary이다.

	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fputs("fputs 를 이용해서 글을 적어 볼게요\n", file);
	fputs("잘 적히는지 확인해 주세요\n", file);

	// 파일을 열고 닫지 않은 상태에서 어떤 프로그램에서 문제가 발생하면 데이터 손상발생!!!!
	// 항상 파일을 닫아주는 습관이 필요함!

	printf("----------------------------------\n");

	fclose(file);



	// 2) 파일 읽기
	char line[MAX]; // = char line[10000];
	FILE* file = fopen("D:\\test1.txt", "rb"); // 읽어오는 거니까 'r'

	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}


	fclose(file);

	printf("----------------------------------\n");
	
	완료한거 주석처리용 - 이거 지우면 됨 */


	// 2. fprintf, fscanf 쌍 -> 정형화된 포멧에서 읽고 쓰기에 최적화
	// printf("%d %d %s ... )
	// scanf("$d %d", &num1 ... ) 

	char line[MAX]; // = char line[10000];
	int num[6] = { 0,0,0,0,0,0 }; // 추첨번호
	int bonus = 0; // 보너스 번호
	char str1[MAX];
	char str2[MAX];

	// 파일 쓰기
	//FILE* file = fopen("d:\\test2.txt", "wb");

	//if (file == NULL)
	//{
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}

	//// 로또 추첨 번호 저장
	//fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "보너스번호", 7);


	// 파일읽기
	FILE* file = fopen("d:\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("파일 열기 실패\n");
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