#include<stdio.h>

// 14_1 main함수의 명령행 인수 사용
// 이해못했음 다시 볼것


int main(int argc, char** argv)			// 명령행 인수를 받을 매개변수
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