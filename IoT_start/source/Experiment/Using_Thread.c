#include <stdio.h>
#include <windows.h>
#include <process.h>

unsigned _stdcall Thread_ABC(void* arg) //Thread ����
{
	while (1)
	{
		printf("A"); //1�ʸ��� A�� ���
		Sleep(100);
	}
}

int main(void)
{
	_beginthreadex(NULL, 0, Thread_ABC, 0, 0, NULL); //Thread_ABC ����
	while (1)
	{
		printf("B"); //2�ʸ��� B�� ���
		Sleep(200);
	}

	int Time_Now = Starttime();
	if()

	return 0;
}
