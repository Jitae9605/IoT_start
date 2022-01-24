#include <stdio.h>

/*

문제10. 세 과목의 점수를 입력하여 총점과 평균을 구하고 출력하는 프로그램을 작성하세요.
단, 다음 함수 원형과 기능을 참고하여 작성합니다.

int total(int kor, int eng, int mat); // 세 과목의 점수를 넘겨받아 총점 반환
double average(int tot); // 총점을 넘겨받아 평균 반환
void print_title(void); // 점수를 제외한 나머지 부분 출력



문제10 실행의 예

세 과목의 점수 입력 : 70  80  91

		 ==== < 성적표 >===

-----------------------------------------
   국어    영어   수학   총점   평균
-----------------------------------------
	 70      80      91    241    80.3

*/

int total(int kor, int eng, int mat);		// 세 과목의 점수를 넘겨받아 총점 반환하는 함수
double average(int tot);					// 총점을 넘겨받아 평균 반환하는 함수
void print_title(void);						// 점수를 제외한 나머지 부분 출력하는 함수

int main_q10_1(void)
{
	int kor, eng, mat, tot;
	double avg;
	printf("세 과목의 점수 입력 : ");
	scanf("%d %d %d", &kor, &eng, &mat);
	tot = total(kor, eng, mat);
	avg = average(tot);

	print_title();
	printf("%d \t%d \t%d \t%d \t%.1lf",kor,eng,mat,tot,avg);

	return 0;
}


int total(int kor, int eng, int mat)
{
	int res;
	res = kor + eng + mat;

	return res;
}

double average(int tot)
{
	return (double)tot / 3;
}

void print_title(void)
{
	printf("\t === < 성적표 > === \t\t\n\n");
	printf("-----------------------------------------\n");
	printf("국어 \t영어 \t수학 \t총점 \t평균 \n");
	printf("-----------------------------------------\n");
}