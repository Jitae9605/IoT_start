#include <stdio.h>
#pragma warning(disable:6031)

// 11. �迭�� ������


// 11-2 �Լ�
void input_arr(double* pa, int size);	// �迭�� �� �Է�
double find_max(double* pa, int size);	// �迭�� �ִ� ��ȯ

int main(void)
{
	// 1.�迭�� �����ʹ� �迭�� ù ��Ҹ� �ǹ��ϰ� �̴� �ݴ뵵 �����Ѵ�.

	/*

	int arr[3] = { 0 };
	int j = 0;
	int a = 0;
	int* pa = arr;

	*(arr + 0) = 10;					// arr[0] = 10
	*(arr + 1) = *(arr + 0) + 10;		// arr[1] = arr[0] + 10;

	printf("����° �迭��ҿ� Ű���� �Է� : ");
	scanf("%d", arr + 2);				// arr - &arr[0] �̹Ƿ� arr + 2 = &arr[2] �̴�

	for (int i = 0; i < 3; i++)
	{
		printf("%5d", *(arr + i));		// arr[i]
	}

	printf("\n");

	while (j < 3)
	{
		printf("%5d", *pa);
		pa++;
		j++;
	}

	

	printf("===============================================================================================");

	*/

	//	2. ����Ʈ�迭 �߷� �� �Լ������� ���
	double  ary2[5];
	double max;										// �ִ밪 ���� ����
	int size = sizeof(ary2) / sizeof(ary2[0]);		// �迭��Ұ��� ���

	input_arr(ary2, size);
	max = find_max(ary2, size);
	printf("�迭�� �ִ밪 : %.1lf\n", max);


	printf("===============================================================================================");

	return 0;
}




// 11-2 �Լ� ����
void input_arr(double* pa, int size)
{
	int i;

	printf("%d���� �Ǽ��� �Է� : ", size);
	for (i = 0; i < size; i++)						// size ����ŭ �ݺ�
	{	
		scanf("%lf", pa + i);						//pa[i] �� ����
	}

}

double find_max(double* pa, int size)
{

	double max;
	int i;

	max = pa[0];								// ù��° �迭��Ҹ� �ִ����� ����
	for (i = 1; i < size; i++)					// 2��° ~ size - 1 ��° ���� �ݺ� 
	{
		if (pa[i] > max) max = pa[i];			// ���ο� �迭��Ұ� �� ũ�� max�� ��ü -> ���� ū ���� ã�� �� �ִ�.
	}

	return max;
}