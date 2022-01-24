#include <stdio.h>

/*

문제9. 문자열을 입력 받으세요. 그리고 입력 받은 문자열 중에서 알파벳 대문자는 소문자로,
소문자는 대문자로 각각 변경하여 출력하는 프로그램을 작성하세요.
단 알파벳 이외의 문자가 존재하면 특별한 변경 없이 출력하는 것으로 합니다.



문제9 실행의 예

문자열 입력 : What Is Your Name?
wHAT iS yOUR nAME?

*/

int main_q9_1(void)
{
	char str[80];
	int cnt;

	char a = 'Z';
	printf("%d", a);

	printf("문자열 입력 : ");
	gets(str);
	cnt = sizeof(str) / sizeof(str[0]);

	for (int i = 0; i < cnt; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')			// 'A'의 아스키코드 = 65 ~ 'Z'의 아스키코드 = 90
		{
			str[i] += 32;
		}

		else if (str[i] >= 'a' && str[i] <= 'z')	// 'a'의 아스키코드 = 97 ~ 'z'의 아스키코드 = 122
		{
			str[i] -= 32;
		}
	}

	puts(str);

	return 0;
	
	
}