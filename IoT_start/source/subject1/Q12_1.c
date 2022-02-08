#include <stdio.h>

/*

���� 12. ������ �� �Լ����� �����ϰ� �̸� Ȱ���ϴ� main �Լ��� �����ϼ���.


���� 12.1 ���ڿ��� ���̸� ��ȯ�ϴ� �Լ� stringLength�� �����ϼ���.
���ڿ��� �ּ� ���� ���ڷ� �ް�, ���ڿ��� ���̸� ��ȯ�ϵ��� �ϼ���.

int stringLength(char* str);

���� 12.2 ���ڿ��� �����ϴ� �Լ� stringCopy�� �����ϼ���.
���� ����� �ּ� ����(�� ��° �Ű�����)�� ���簡 �̷��� �ּ� ����(ù ��° ��������)�� �Ű������� �ް�,
������ ���ڿ��� ���̸� ��ȯ�ϵ��� �ϼ���.

int stringCopy(char* dest, char* source);

���� 12.3 ���ڿ��� �ڿ� ���ڿ��� �����̴� �Լ� stringCat�� �����ϼ���.
�����ӿ� ����� ����� �ּ� ����(�� ��° �Ű�����)�� ������ �� ��� ���ڿ���
�ּ� ����(ù ��° �Ű�����)�� ���ڷ� �ް�, ���ٿ��� ���ڿ��� �������̸� ��ȯ�ϵ��� �ϼ���.

int stringCat(char* dest, char* source);

���� 12.4 �� ���� ���ڿ��� ���ϴ� �Լ� stringCompare�� �����ϼ���.
�� ����� �� ���ڿ��� �ּ� ���� �Ű������� �����ϰ�, �� ���ڿ��� ������ 1, �ٸ��� 0�� ��ȯ�ǵ��� �ϼ���.

int stringCompare(char* str1, char* str2);


========== main �Լ����� ����ϼ���. ============ =
char a[100] = "hello.";
char b[100] = "nice to meet you.";
char copySt[100];


========== ������ ============ =
length of "hello.": 6
length of "nice to meet you." : 17


copy string : "hello."


concat string : "hello.nice to meet you."


compare a, a : 1
compare b, b : 1
compare a, b : 0
compare b, a : 0

*/

int stringLength(char* str);							// 12.1 ���ڿ��� �����ͷ� �޾� ���ڿ��� ���̸� ���ϴ� �Լ�
int stringCopy(char* dest, char* source);				// 12.2 �� ���ڿ��� �����ͷ� �޾� ���ڿ�2�� ������ ���ڿ�1���� �����ϴ� �Լ�
int stringCat(char* dest, char* source);				// 12.3 �� ���ڿ��� �����ͷ� �޾� ���ڿ�1���� �ڿ� ���ڿ�2���� ������ �����̴� �Լ�
int stringCompare(char* str1, char* str2);				// 12.4 �� ���ڿ��� �����ͷ� �޾� ���ڿ�1���� 2���� ���� ������ 1��, �ٸ��� 0�� ��ȯ�ϴ� �Լ�

// ============================== < �����Լ� > =====================================================

int main(void)
{
	// ��������
	// ���� / �ٿ��ʱ������ ���� ��ȯ�� � ������ �޾� �Ұ����ϰ� ����
	char a1[100] = "hello.";
	char b1[100] = "nice to meet you.";
	char a2[100] = "hello.";
	char b2[100] = "nice to meet you.";
	char a3[100] = "hello.";
	char b3[100] = "nice to meet you.";
	char a4[100] = "hello.";
	char b4[100] = "nice to meet you.";
	char copySt[100];
	int For_Check_return[5] = { 0 };

	printf("\n ======== < ���� 12.1 > ========\n");

	printf("\n Length of \"%s\" : %d\n", a1, stringLength(a1));
	printf("\n Length of \"%s\" : %d\n", b1, stringLength(b1));

	printf("\n ======== < ���� 12.2 > ========\n");

	stringCopy(a2, copySt);
	printf("\n copy string: \"%s\"\n", copySt); 

	printf("\n ======== < ���� 12.3 > ========\n");

	stringCat(a3, b3);
	printf("\nconcat string: \"%s\"\n", a3);

	printf("\n ======== < ���� 12.4 > ========\n");

	printf("\ncompare a, a: %d\n", stringCompare(a4, a4));
	printf("\ncompare b, b: %d\n", stringCompare(b4, b4));
	printf("\ncompare a, b: %d\n", stringCompare(a4, b4));
	printf("\ncompare b, a: %d\n", stringCompare(b4, a4));


	return 0;
}

// ============================== < �Լ����� > =====================================================


// 12.1 ���ڿ��� �����ͷ� �޾� ���ڿ��� ���̸� ���ϴ� �Լ�
int stringLength(char* str)
{
	int Length_of_str = 0;
	for (int i = 0; i < 100; i++)
	{
		if (str[i] != '\0')
		{
			Length_of_str++;
		}
	}
	
	return Length_of_str;
}

// 12.2 �� ���ڿ��� �����ͷ� �޾� ���ڿ�2�� ������ ���ڿ�1���� �����ϴ� �Լ�
int stringCopy(char* dest, char* source)
{
	for (int i = 0; i < 100; i++)
	{
		source[i] = dest[i];
		
	}

	return stringLength(source);
}

// 12.3 �� ���ڿ��� �����ͷ� �޾� ���ڿ�1���� �ڿ� ���ڿ�2���� ������ �����̴� �Լ�
int stringCat(char* dest, char* source)
{
	int Length1 = stringLength(dest);
	int Length2 = stringLength(source);
	int Length3 = Length1 + Length2;

	for (int i = 0; i < 100 - Length1; i++)
	{
		dest[Length1 + i] = source[i];
	}

	return Length3;
}


// 12.4 �� ���ڿ��� �����ͷ� �޾� ���ڿ�1���� 2���� ���� ������ 1��, �ٸ��� 0�� ��ȯ�ϴ� �Լ�
int stringCompare(char* str1, char* str2)
{
	int Check_Same = 0;
	for (int i = 0; i < 100; i++)
	{
		if (str1[i] == str2[i])
		{
			Check_Same++;
		}
	}

	if (Check_Same == 100)
	{
		return 1;
	}

	else
	{
		return 0;
	}

}


