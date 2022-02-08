#include <stdio.h>

/*

문제 12. 다음의 각 함수들을 정의하고 이를 활용하는 main 함수를 정의하세요.


문제 12.1 문자열의 길이를 반환하는 함수 stringLength을 구현하세요.
문자열의 주소 값을 인자로 받고, 문자열의 길이를 반환하도록 하세요.

int stringLength(char* str);

문제 12.2 문자열을 복사하는 함수 stringCopy을 구현하세요.
복사 대상의 주소 정보(두 번째 매개변수)와 복사가 이뤄질 주소 정보(첫 번째 전달인자)를 매개변수로 받고,
복사한 문자열의 길이를 반환하도록 하세요.

int stringCopy(char* dest, char* source);

문제 12.3 문자열의 뒤에 문자열을 덧붙이는 함수 stringCat을 구현하세요.
덧붙임에 사용할 대상의 주소 정보(두 번째 매개변수)와 덧붙임 후 결과 문자열의
주소 정보(첫 번째 매개변수)를 인자로 받고, 덧붙여진 문자열의 최종길이를 반환하도록 하세요.

int stringCat(char* dest, char* source);

문제 12.4 두 개의 문자열을 비교하는 함수 stringCompare을 구현하세요.
비교 대상인 두 문자열의 주소 값을 매개변수로 전달하고, 두 문자열이 같으면 1, 다르면 0이 반환되도록 하세요.

int stringCompare(char* str1, char* str2);


========== main 함수에서 사용하세요. ============ =
char a[100] = "hello.";
char b[100] = "nice to meet you.";
char copySt[100];


========== 실행결과 ============ =
length of "hello.": 6
length of "nice to meet you." : 17


copy string : "hello."


concat string : "hello.nice to meet you."


compare a, a : 1
compare b, b : 1
compare a, b : 0
compare b, a : 0

*/

int stringLength(char* str);							// 12.1 문자열을 포인터로 받아 문자열의 길이를 구하는 함수
int stringCopy(char* dest, char* source);				// 12.2 두 문자열을 포인터로 받아 문자열2의 내용을 문자열1번에 복사하는 함수
int stringCat(char* dest, char* source);				// 12.3 두 문자열을 포인터로 받아 문자열1번의 뒤에 문자열2번의 내용을 덧붙이는 함수
int stringCompare(char* str1, char* str2);				// 12.4 두 문자열을 포인터로 받아 문자열1번과 2번을 비교해 같으면 1을, 다르면 0을 반환하는 함수

// ============================== < 메인함수 > =====================================================

int main(void)
{
	// 변수선언
	// 복사 / 붙여너기등으로 인해 반환값 등에 영향을 받아 불가피하게 나눔
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

	printf("\n ======== < 문제 12.1 > ========\n");

	printf("\n Length of \"%s\" : %d\n", a1, stringLength(a1));
	printf("\n Length of \"%s\" : %d\n", b1, stringLength(b1));

	printf("\n ======== < 문제 12.2 > ========\n");

	stringCopy(a2, copySt);
	printf("\n copy string: \"%s\"\n", copySt); 

	printf("\n ======== < 문제 12.3 > ========\n");

	stringCat(a3, b3);
	printf("\nconcat string: \"%s\"\n", a3);

	printf("\n ======== < 문제 12.4 > ========\n");

	printf("\ncompare a, a: %d\n", stringCompare(a4, a4));
	printf("\ncompare b, b: %d\n", stringCompare(b4, b4));
	printf("\ncompare a, b: %d\n", stringCompare(a4, b4));
	printf("\ncompare b, a: %d\n", stringCompare(b4, a4));


	return 0;
}

// ============================== < 함수정의 > =====================================================


// 12.1 문자열을 포인터로 받아 문자열의 길이를 구하는 함수
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

// 12.2 두 문자열을 포인터로 받아 문자열2의 내용을 문자열1번에 복사하는 함수
int stringCopy(char* dest, char* source)
{
	for (int i = 0; i < 100; i++)
	{
		source[i] = dest[i];
		
	}

	return stringLength(source);
}

// 12.3 두 문자열을 포인터로 받아 문자열1번의 뒤에 문자열2번의 내용을 덧붙이는 함수
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


// 12.4 두 문자열을 포인터로 받아 문자열1번과 2번을 비교해 같으면 1을, 다르면 0을 반환하는 함수
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


