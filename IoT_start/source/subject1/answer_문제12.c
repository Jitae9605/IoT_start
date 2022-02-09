#include <stdio.h>

int string_Length(char* str);
int string_Copy(char* copyStr, char* originalStr);
int string_ConCat(char* copyStr, char* originalStr);
int string_Compare(char* str1, char* str2);

int main(void)
{
	/** 원본 문자열 **/
	char a[100] = "hello.";
	char b[100] = "nice to meet you.";

	/** 복사본 문자열 **/
	char copyStr[100];

	/** stringLength ex **/
	printf("length of \"%s\": %d \n", a, string_Length(a));
	printf("length of \"%s\": %d \n", b, string_Length(b));
	printf("\n\n");

	/** stringCopy ex **/
	/** string_Copy(복사본, 원본); **/
	string_Copy(copyStr, a);
	printf("copy string: \"%s\" \n", copyStr);
	printf("\n\n");

	/** string_ConCat ex **/
	/** string_ConCat(복사본, 원본); **/
	string_ConCat(copyStr, b);
	printf("concat string: \"%s\" \n", copyStr);
	printf("\n\n");

	/** stringCompare ex **/
	printf("compare a, a: %d \n", string_Compare(a, a));
	printf("compare b, b: %d \n", string_Compare(b, b));
	printf("compare a, b: %d \n", string_Compare(a, b));
	printf("compare b, a: %d \n", string_Compare(b, a));
	
	return 0;
}


int string_Length(char* str)
{
	int strlength = 0;

	while ((*str) != 0)
	{
		strlength++;
		str++;
	}

	return strlength;
}

/** string_Copy(복사본, 원본) **/
int string_Copy(char* copyStr, char* originalStr)
{
	int copyLength = string_Length(originalStr) + 1; //널(NULL)문자까지 복사!
	int i;

	for (i = 0; i < copyLength; i++)
		copyStr[i] = originalStr[i];

	return copyLength;
}

/** string_ConCat(복사본, 원본) **/
int string_ConCat(char* copyStr, char* originalStr)
{
	int destLength = string_Length(copyStr);
	int src_Length = string_Length(originalStr) + 1;
	int i;

	for (i = 0; i < src_Length; i++)
		copyStr[destLength + i] = originalStr[i];

	return destLength + src_Length;
}


int string_Compare(char* str1, char* str2)
{
	while ((*str1) != 0 || (*str2) != 0)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		else
		{
			str1++;
			str2++;
		}
	}

	return 1;
}