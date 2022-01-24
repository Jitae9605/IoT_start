#include <stdio.h>

int main_q8_2(void)
{				
	int arr[5] = { 0 };						// 5개의 공간을 가진 정수 배열
	int temp = 0;
	int cnt;
	cnt = sizeof(arr) / sizeof(arr[0]);		// 정렬할 자료의 수(입력할 자료의 수)

	// 배열의 각 요소에 키보드로 값을 입력받아 넣어준다(5개)
	for (int i = 0; i < 10; i++)
	{
		printf("숫자 %d 입력: ",i + 1);
		scanf("%d", &arr[i]);
	}


	// 정렬부분 (거품정렬)
	for (int i = 0; i < cnt - 1; i++)			// 반복횟수는 n-1번 이면 충분(한번 할때마다 가장 오른쪽에 제일 큰값이 저장되므로(하나씩 채워져 가는 느낌)
	{
		for (int j = 0; j < cnt - 1; j++)		// 0 1 2 3 4 이고 arr[i + 1]이 있으므로
		{
			if (arr[j] > arr[j + 1])			// 둘(i,i+1) 사이의 크기비교
			{
				temp = arr[j];					// 왼쪽이 더 크면 그 값을 temp에 저장
				arr[j] = arr[j + 1];			// 오른쪽의 값(작은 값 = i+1)을 왼쪽(i)에 저장(덮어씌움 - temp에 저장한 이유)
				arr[j + 1] = temp;				// temp에 저장된 큰 값을 오른쪽에 저장(덮어쓰기)
			}									// 이렇게 반복하면 크기순으로 정렬됨
		}										
	}
	
	printf("정렬된 출력:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}