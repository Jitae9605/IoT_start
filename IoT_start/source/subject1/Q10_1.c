#include <stdio.h>

/*

����10. �� ������ ������ �Է��Ͽ� ������ ����� ���ϰ� ����ϴ� ���α׷��� �ۼ��ϼ���.
��, ���� �Լ� ������ ����� �����Ͽ� �ۼ��մϴ�.

int total(int kor, int eng, int mat); // �� ������ ������ �Ѱܹ޾� ���� ��ȯ
double average(int tot); // ������ �Ѱܹ޾� ��� ��ȯ
void print_title(void); // ������ ������ ������ �κ� ���



����10 ������ ��

�� ������ ���� �Է� : 70  80  91

		 ==== < ����ǥ >===

-----------------------------------------
   ����    ����   ����   ����   ���
-----------------------------------------
	 70      80      91    241    80.3

*/

int total(int kor, int eng, int mat);		// �� ������ ������ �Ѱܹ޾� ���� ��ȯ�ϴ� �Լ�
double average(int tot);					// ������ �Ѱܹ޾� ��� ��ȯ�ϴ� �Լ�
void print_title(void);						// ������ ������ ������ �κ� ����ϴ� �Լ�

int main_q10_1(void)
{
	int kor, eng, mat, tot;
	double avg;
	printf("�� ������ ���� �Է� : ");
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
	printf("\t === < ����ǥ > === \t\t\n\n");
	printf("-----------------------------------------\n");
	printf("���� \t���� \t���� \t���� \t��� \n");
	printf("-----------------------------------------\n");
}