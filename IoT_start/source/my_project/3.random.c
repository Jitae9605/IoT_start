#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_rand(void)
{
	// rand()
	// ������ ������ ���� =  �����Ҷ����� ���� �ٸ�
	// <time.h> �� <stdlib.h> �� �߰��ؾ��Ѵ�.
	
	// �� : int �̸� = rand() % ������ ����
	int num = rand() % 3; // 0 ~ 2 ������ �� �߿��� ������ ���õȴ�.
	int num1 = rand() % 3 + 1; // 1 ~ 3 ������ ������ �ϳ��� �������� ���´�.


	// ���� �ʱ�ȭ �� �ʿ��� = srand(time(NULL))
	
	printf("���� �ʱ�ȭ ����.. \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9 ������ ������ ���� 10�� �̴´�
	}
	// ���� �ʱ�ȭ ���ϸ� �Ź� �����Ҷ� ���� ���� ��µȴ�.

	printf("\n\n���� �ʱ�ȭ ����..\n");
	srand(time(NULL)); // ���� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", rand() % 10); // 0 ~ 9 ������ ������ ���� 10�� �̴´�
	}

	

	return 0;
}