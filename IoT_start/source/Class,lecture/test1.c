#include<stdio.h>

// 14_1 main�Լ��� ����� �μ� ���
// ���ظ����� �ٽ� ����


int main(int argc, char** argv)			// ����� �μ��� ���� �Ű�����
{
	//	argc = argument count
	//	argv = argument vector

	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return 0;
}