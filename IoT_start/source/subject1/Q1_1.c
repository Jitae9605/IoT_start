#include <stdio.h>

/*

���� 1-1

�Ǽ�(������ �ƴ� �Ǽ��̴�) �� ���� �Է� �޾Ƽ�, �� �Ǽ��� ��Ģ���� ����� ����ϴ� ���α׷��� �ۼ��ϼ���.

���� 1-1 ������ ��

�� ���� �Ǽ� �Է�: 3.7 2.5
���� ��� : 6.200000
���� ��� : 1.200000
���� ��� : 9. 250000
������ ��� : 1.480000

*/

int main(void)
{
	float a = 0, b = 0;

	printf("�� ���� �Ǽ� �Է�: ");
	scanf("%f %f", &a, &b);

	float sum = a + b;
	float sub = a - b;
	float mul = a * b;
	float div = a / b;

	printf("���� ��� : %f\n", sum);
	printf("���� ��� : %f\n", sub);
	printf("���� ��� : %f\n", mul);
	printf("������ ��� : %f\n", div);

	return 0;
}
