#include<stdio.h>

// 3) 사용자정의헤더 포함
#include "21_sub_3_point.h"
#include "21_sub_3_line.h"


// ========================================= 매크로 선언부 ====================================================================



// ========================================= 전역변수 선언부 ====================================================================

// 2) extern과 static 분할컴파일 
int count_2 = 0;
static int total_2 = 0;


// ========================================= 함수 선언부 ====================================================================

// 1) fgets와 fputs로 한줄씩 입출력 함수선언 
void input_data_1(int*, int*);
double average_1(int, int);

// 2) extern과 static 분할컴파일 함수선언

int input_data_2(void);
double average_2(void);
void print_data_2(double avg);

// ========================================= main 함수 ====================================================================
int main(void)
{
	// 21. 분할컴파일

	printf("\n------------------- < 1) 분할컴파일 사용하기 > ---------------------------------------------\n\n");

	int a_1, b_1;
	double avg_1;

	input_data_1(&a_1, &b_1);
	avg_1 = average_1(a_1, b_1);
	printf("%d와 %d의 평균 : %.1lf\n", a_1, b_1, avg_1);

	printf("\n------------------- < 2) extern과 static을 이용한 분할컴파일  > ---------------------------------------------\n\n");

	double avg_2;

	total_2 = input_data_2();
	avg_2 = average_2();
	print_data_2(avg_2);

	printf("\n------------------- < 3) 헤더파일화 및 중복 피하기  > ---------------------------------------------\n\n");

	Line a = { {1,2},{5,6} };				// Line 구조체 변수 초기화
	Point b;								// 가운데점 좌표저장

	b.x = (a.first.x + a.second.x) / 2;						// 가운데점 x좌표 계산
	b.y = (a.first.y + a.second.y) / 2;						// 가운데점 y좌표 계산
	printf("선의 가운데 점의 좌표 : (%d, %d)\n",b.x, b.y);

	return 0;

}

// ========================================= 함수 정의부 ====================================================================

//	2) extern과 static을 이용한 분할컴파일
void print_data_2(double avg)
{
	printf("입력한 양수의 개수 : %d\n", count_2);
	printf("전체 합과 평균 : %d, %.1lf\n", total_2, avg);
}