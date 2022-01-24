#include <stdio.h>

/*

문제 2

7개의 숫자를 정수 형태로(반드시 정수 형태로 입력 받는다) 입력 받아서
입력 받은 수들의 최대값, 최소값, 전체 합, 그리고 평균을 구하는 프로그램을 작성하세요.
단 평균은 정확히 계산하여 소수점 이하까지 출력합니다.


문제 2 실행의 예

정수형 데이터 입력: 3
정수형 데이터 입력: 4
정수형 데이터 입력: 2
정수형 데이터 입력 : 3
정수형 데이터 입력: 5
정수형 데이터 입력: 7
정수형 데이터 입력 : -12

최대값 : 7
최소값: -12
전체합 : 12
평 균 : 1.714286

*/

int main_q2_1(void)
{
	int arr[7] = { 0 };
	int sum = 0;
	int temp = 0;
	int min = 0;
	int max = 0;
	float avg = 0;
	int temp_max = 0;
	int temp_min = 0;


	for (int i = 0; i < 7; i++)
	{
		printf("정수형 데이터 입력: ");	
		scanf("%d", &arr[i]);			// 7번의 반복 입력
		sum = sum + arr[i];				// 총합 구하기

		// 모든 값이 양수거나 음수일때 max와min이 0이 되는것 방지
		temp = arr[0];
		max = arr[0];
		min = arr[0];

		// 비교 하는 부분
		if (i > 0)						// arr[0]는 이전의 것이 없어 비교가 안되므로
		{
			// 배열의 arr[i]이 arr[i-1]보다 크다면 tmep_max에 넣고 이를 i가 7이 될때까지 반복해 temp_max가 가장 큰 값을 가지게 함
			if (arr[i - 1] < arr[i])	
			{
				temp_max = arr[i];
				if (temp_max > max)		// 입력된 temp_max와 지금의 man값과 비교
				{						
					max = temp_max;		// 비교해 더 큰 걸 temp_min에 저장
				}
			}

			// 배열의 arr[i] 가 arr[i-1]보다 작다면 tmep_min에 넣고 이를 i가 7이 될때까지 반복해 temp_min이 가장 작은 값을 가지게 함
			else
			{
				temp_min = arr[i];
				if (temp_min < min)		// 입력된 temp_min과 지금의 min값과 비교
				{
					min = temp_min;		// 비교해 더 작은걸 temp_min에 저장
				}						// 그리고 min에 저장
			}
		}
	}

	avg = (float)sum / 7;				// 평균구하기

	printf("최댓값 : %d\n", max);
	printf("최솟값 : %d\n", min);
	printf("전체합 : %d\n", sum);
	printf("평균 : %f\n", avg);

	return 0;

}