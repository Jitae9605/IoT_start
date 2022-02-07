#include <stdio.h>
#pragma warning(disable:6031)

// 11. 배열과 포인터


// 11-2 함수
void input_arr(double* pa, int size);	// 배열에 값 입력
double find_max(double* pa, int size);	// 배열의 최댓값 반환

int main(void)
{
	// 1.배열의 포인터는 배열의 첫 요소를 의미하고 이는 반대도 성립한다.

	/*

	int arr[3] = { 0 };
	int j = 0;
	int a = 0;
	int* pa = arr;

	*(arr + 0) = 10;					// arr[0] = 10
	*(arr + 1) = *(arr + 0) + 10;		// arr[1] = arr[0] + 10;

	printf("세번째 배열요소에 키보드 입력 : ");
	scanf("%d", arr + 2);				// arr - &arr[0] 이므로 arr + 2 = &arr[2] 이다

	for (int i = 0; i < 3; i++)
	{
		printf("%5d", *(arr + i));		// arr[i]
	}

	printf("\n");

	while (j < 3)
	{
		printf("%5d", *pa);
		pa++;
		j++;
	}

	

	printf("===============================================================================================");

	*/

	//	2. 포인트배열 추력 및 함수에서의 사용
	double  ary2[5];
	double max;										// 최대값 저장 변수
	int size = sizeof(ary2) / sizeof(ary2[0]);		// 배열요소갯수 계산

	input_arr(ary2, size);
	max = find_max(ary2, size);
	printf("배열의 최대값 : %.1lf\n", max);


	printf("===============================================================================================");

	return 0;
}




// 11-2 함수 정의
void input_arr(double* pa, int size)
{
	int i;

	printf("%d개의 실수값 입력 : ", size);
	for (i = 0; i < size; i++)						// size 값만큼 반복
	{	
		scanf("%lf", pa + i);						//pa[i] 도 가능
	}

}

double find_max(double* pa, int size)
{

	double max;
	int i;

	max = pa[0];								// 첫번째 배열요소를 최댓값으로 설정
	for (i = 1; i < size; i++)					// 2번째 ~ size - 1 번째 까지 반복 
	{
		if (pa[i] > max) max = pa[i];			// 새로운 배열요소가 더 크면 max값 교체 -> 제일 큰 값을 찾을 수 있다.
	}

	return max;
}