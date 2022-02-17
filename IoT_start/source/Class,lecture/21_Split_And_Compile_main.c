#include<stdio.h>

void input_data(int*, int*);
double average(int, int);

int main(void)
{
	int a_1, b_1;
	double avg_1;

	input_data(&a_1, &b_1);
	avg_1 = average(a_1, b_1);
	printf("%d¿Í %dÀÇ Æò±Õ : %.1lf\n", a_1, b_1, avg_1);
}