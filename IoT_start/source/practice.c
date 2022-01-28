#include <stdio.h>

int main_practice42154(void)
{

	// 1. 10개의 수를 입력받아 정렬
	
	//int arr[10] = { 0 };
	//int cnt = sizeof(arr) / sizeof(arr[0]);
	//int temp = 0;

	//for (int i = 1; i <= cnt; i++)
	//{
	//	printf("수 입력(%d) : ",i);
	//	scanf("%d", &arr[i - 1]);
	//}

	//printf("입력된 수 배열 : ");
	//for (int i = 0; i < cnt ; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	//for (int i = 0; i < cnt - 1; i++)				// 반복횟수는 n-1번 이면 충분(한번 할때마다 가장 오른쪽에 제일 큰값이 저장되므로(하나씩 채워져 가는 느낌)
	//{
	//	for (int j = 0; j < (cnt - i) - 1; j++)		// (cnt - i) - 1 : 사이클이 돌수록 탐색범위를 줄여도 된다(최적화 - 굳이 안해도 되긴함)(맨 우측에 항상 큰 값이 점점 쌓임)
	//	{
	//		if (arr[j] > arr[j + 1])				// 둘(i,i+1) 사이의 크기비교
	//		{
	//			// 값의 이동은 체스나 턴제게임과 같다. 겹칠수 없고 한번에 한개만 움직일수 있다는 것을 알아야함.
	//			temp = arr[j];						// 왼쪽이 더 크면 그 값을 temp에 저장
	//			arr[j] = arr[j + 1];				// 오른쪽의 값(작은 값 = i+1)을 왼쪽(i)에 저장(덮어씌움 - temp에 저장한 이유)
	//			arr[j + 1] = temp;					// temp에 저장된 큰 값을 오른쪽에 저장(덮어쓰기)
	//		}										// 이렇게 반복하면 크기순으로 정렬됨
	//	}
	//}

	//printf("정렬후 수 배열 : ");
	//for (int i = 0; i < cnt; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	//

	// 2.

	return 0;
}