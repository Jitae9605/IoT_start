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
	//	< 함수에서 포인터를 사용하고 매인에서 &를 이용해 주소값을 넘겨는 이유 >
	
	// 괄호를 통해 나누어진경우 같은 이름이라도 사실 뒤에 보이지 않는 함수이름의 꼬리표가 붙어있고 다른 메모리주소에 저장된다.
	// ex) size(_main) , size(_input_arr)
	//	그래서 각각을 따로 선언해야하고 같은 size여도 값이 공유되지 않고 따로 관리된다.
	//	그래서 함수에 값을 받아와서 처리후 같은 변수공간의 값을 변화시키려면 해당 변수의 주소값을 받아와 해당주소에 저장된 값에 접근해야하고
	//	이를위해 포인터를 통한 주소값 넘겨주기를 사용한다.

	// < 참고 >
	// input_arr(double *pa,int size)라는 함수가 정의되어있을때
	// main에서 input_arr(ary2,size)로 호출하면 실제 처리과정에서 자동으로 
	
	// ----------------------------
	// double *pa;
	// int size;
	
	// pa = ary2;						// ary2는 배열 이므로 이는 실제로는 pa = &ary2[0]이다.
	// size = size
	// ----------------------------

	// 가 추가되어(안보임/생략된 상태) 처리가 일어나는 것!

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