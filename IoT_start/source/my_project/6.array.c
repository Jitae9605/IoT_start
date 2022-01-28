#include <stdio.h>

int main_array(void)
{
	// 배열

	/* 완료한거 주석처리용 - 이거 지우면 됨
		
	int subway_1 = 30; // 지하철 1호선에 30명이 타고있다
	int subway_2 = 40; 
	int subway_3 = 50;

	printf("지하철 1호선에 %d 명이 타고있다\n", subway_1);
	printf("지하철 2호선에 %d 명이 타고있다\n", subway_2);
	printf("지하철 3호선에 %d 명이 타고있다\n", subway_3);

	// 호차가 많아지면 각각 적기 번거롭다
	
	printf("----------------------------------\n");


	// 배열의 사용 
	// 자료형 배열이름[배열수]; 
	int subway_array[3];  // [0] ~ [2] 로 3개의 공간을 가진 배열
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("지하철 %d호차에 %d 명이 타고 있습니다\n", i + 1, subway_array[i]);
	}

	printf("----------------------------------\n");

	// 값 설정 방법
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // 값 선언 안하면 더미 데이터가 들어감(무의미한 아무 숫자)

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	// 배열 크기는 항상 상수로 선언 해야함
	int size = 10;
	int arr[10]; // 가능
	// int arr[size]; // 불가능

	int arr[10] = { 1, 2 }; // 지정되지 않은 다른 값들은 전부 0의 값이 자동 배정됨
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	// 크기 선언 안해도 값을 넣으면 크기는 자동으로 그 값의 갯수에 맞게 설정이 된다.
	// int arr[] = { 1, 2 }; // arr[2] 가 된다.




	float arr_f[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f\n", arr_f[i]);
	}

	printf("----------------------------------\n");

	// 문자 VS 문자열
	char c = 'A';
	printf("%c\n", c);


	// 문자열의 끝에는 문자열이 끌났음을 표시하는 NULL문자 '\0' 이 포함되어야 함
	char str[6] = "coding"; // = [c] [o] [d] [i] [n] [g]
	printf("%s\n", str); // 이렇게 하면 뒤에 이상한 게 들어감

	char str1[7] = "coding"; // = [c] [o] [d] [i] [n] [g] [\0]
	printf("%s\n", str1); // 이렇게 해야 제대로 출력됨 - 맨끝의 한칸 비울 것
	
	char str2[] = "coding";
	printf("%s\n", str2); // 크기를 지정하지 않으면 자동으로 NULL문자까지 계산해서 크기 지정해줌
	printf("%d\n", sizeof(str2)); // sizeof 는 뒤의 NULL문자 까지 갯수를 센다

	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%c\n", str2[i]); // 직접 출력해보면 NULL문자(공백) 까지 출력된다.
	}


	// 영어와 한글의 크기차이
	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor)); // 한글 4글자(8 byte) + Null문자(1 byte) = 9 byte 
	// 영어는 1글자 : 1 byte
	// 한글은 1글자 : 2 byte

	// 실제로는 이렇게 되는건데 자동으로 해주는 것
	char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g', '\0' };
	printf("%s\n", c_array);

	char c_array1[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
	printf("%s\n", c_array);

	for (int i = 0; i < 10; i++) // 문자로 출력
	{
		printf("%c\n", c_array1[i]); // 남은 공간이 모두 NULL문자(공백)가 된다.
	}

	printf("----------------------------------\n");

	 완료한거 주석처리용 - 이거 지우면 됨 */

	// 번외 : ASCII 코드
	// 1) ASCII 코드 의 개념
	
	// ASCII 코드 : ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7 bit, 총 128개의 코드 ( 0 ~ 127 ) 
	// a = 97 (문자 a의 아스키 코드 정수값)
	// A = 65
	// b = 98
	// B = 66
	// 0 = 48

	printf("%c\n", 'a'); // 출력값 : a
	printf("%d\n\n", 'a'); // 출력값 : 97

	printf("%c\n", 'A'); // 출력값 : A
	printf("%d\n\n", 'A'); // 출력값 : 65

	printf("%c\n", 'b'); // 출력값 : b
	printf("%d\n\n", 'b'); // 출력값 : 98

	printf("%c\n", 'B'); // 출력값 : B
	printf("%d\n\n", 'B'); // 출력값 : 66

	printf("%c\n", '\0'); // 출력값 :  (공백)
	printf("%d\n\n", '\0'); // 출력값 : 0

	printf("%c\n", '0'); // 출력값 : 0
	printf("%d\n\n", '0'); // 출력값 : 48

	printf("%c\n", '1'); // 출력값 : 1
	printf("%d\n\n", '1'); // 출력값 : 49

	char c_array1[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
	for (int i = 0; i < 10; i++) // 숫자로 출력
	{
		printf("%d\n", c_array1[i]); // ASCII 코드 값 출력 (NULL문자는 0으로 출력)
	}

	printf("----------------------------------\n");

	// 2) 0 ~ 127 사이의 아스키코드 정수값에 해당하는 문자 확인
	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i); // 코드중에는 컴퓨터에 소리를 내라고 하는 명령이 있어서 소리가 난다
	 }

	
	

	return 0;
}