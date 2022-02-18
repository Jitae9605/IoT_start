#include <stdio.h>
#include<conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
	//배경색인 background를 4비트 앞으로 보내고, text와 더하여 적용.
}

int main()
{
	int i;
	srand(time(0));

	for (i = 0; i < 16; i++)
	{
		unsigned short text = rand() % 16;
		unsigned short back = rand() % 16;

		SetColor(text, back);
		printf("SetTextColor(%d,%d)\n", text, back);
	}

	return 0;
}