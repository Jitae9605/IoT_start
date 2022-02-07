#include <stdio.h>

// 11. 배열과 포인터

int main(void)
{

	int arr[3] = { 0 };
	int i;

	*(arr + 0) = 10;					// arr[0] = 10
	*(arr + 1) = *(arr + 0) + 10;		// arr[1] = arr[0] + 10;

	printf("%d", arr + 2);				// arr - &arr[0] 이므로 arr + 2 = &arr[2] 이다
	
	for (i = 0; i < 3; i++)
	{
		printf("%5d", *(arr + i));		// arr[i]
	}
 

	return 0;
}