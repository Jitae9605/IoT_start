#include <stdio.h>

/*

����9. ���ڿ��� �Է� ��������. �׸��� �Է� ���� ���ڿ� �߿��� ���ĺ� �빮�ڴ� �ҹ��ڷ�,
�ҹ��ڴ� �빮�ڷ� ���� �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� ���ĺ� �̿��� ���ڰ� �����ϸ� Ư���� ���� ���� ����ϴ� ������ �մϴ�.



����9 ������ ��

���ڿ� �Է� : What Is Your Name?
wHAT iS yOUR nAME?

*/

int main_q9_1(void)
{
	char str[80];
	int cnt;

	char a = 'Z';
	printf("%d", a);

	printf("���ڿ� �Է� : ");
	gets(str);
	cnt = sizeof(str) / sizeof(str[0]);

	for (int i = 0; i < cnt; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')			// 'A'�� �ƽ�Ű�ڵ� = 65 ~ 'Z'�� �ƽ�Ű�ڵ� = 90
		{
			str[i] += 32;
		}

		else if (str[i] >= 'a' && str[i] <= 'z')	// 'a'�� �ƽ�Ű�ڵ� = 97 ~ 'z'�� �ƽ�Ű�ڵ� = 122
		{
			str[i] -= 32;
		}
	}

	puts(str);

	return 0;
	
	
}