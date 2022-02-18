#include <stdio.h>
#include <windows.h>
#include <process.h>

unsigned _stdcall Thread_ABC(void* arg) //Thread 선언
{
	while (1)
	{
		printf("A"); //1초마다 A를 출력
		Sleep(100);
	}
}

int main(void)
{
	_beginthreadex(NULL, 0, Thread_ABC, 0, 0, NULL); //Thread_ABC 실행
	while (1)
	{
		printf("B"); //2초마다 B를 출력
		Sleep(200);
	}

	int Time_Now = Starttime();
	if()

	return 0;
}
