#include <stdio.h>

// 함수선언 - 매인함수 밖에서 선언하고 정의해야함
// 반환형 함수이름(자료형 전달값)
// 반환형 = 함수선언후 수행하고 반환할 값을 선택 (void = 반환 없음)
// p라는 이름의 함수를 생성하고 만드는 것으로 p함수가 받을 값을 선언하는 것

void p(int i); // 함수선언 1
void fuction_without_return(); // 함수선언 2 - 반환값이 없는 함수
int function_with_return(); // 함수선언 3 - 반환값이 있는 함수
void function_without_parameters(); // 함수선언 4 - 파라미터가 없는 함수
void function_with_parameters(int num1, int num2, int num3); // 함수선언 5 - 파라미터가 있는 함수
int apple(int total, int eat); // 함수선언 6 - 파라미터도 있고 전달값도 있는 함수

// 프로젝트 사용 함수선언
void project_p(int num); // 1 - 값을 출력하는 함수(=)
int add(int num1, int num2); // 2 - 덧셈계산 함수(+)
int sub(int num1, int num2); // 3 - 뺄셈계산 함수(-)
int mul(int num1, int num2); // 4 - 곱셈계산 함수(*)
int div(int num1, int num2); // 5 - 나눗셈계산 함수 (/)

int main_function(void)
{
	/* 완료한거 주석처리용 - 이거 지우면 됨
	
	// function
	// 계산기

	// 함수를 사용한 계산기
	int num = 2;
	// printf("num은 %d 입니다.\n", num); // 2
	p(num); // p라고 정의된 함수를 호출하고 받는 값에 num 값을 입력

	// 2 + 3 = ?
	num = num + 3; // num += 3;
	// printf("num은 %d 입니다.\n", num); // 5
	p(num);

	// 5 - 1 = ?
	num = num - 1;  // num -= 1;
	// printf("num은 %d 입니다.\n", num); // 4
	p(num);

	// 4 * 3 = ?
	num = num * 3; // num *= 3;
	// print("num은 %d 입니다.\n", num); // 12
	p(num);

	// 12 / 6 = ?
	num = num / 6; // num /= 6;
	// printf("num은 %d 입니다.\n", num); // 2
	p(num);

	printf("----------------------------------\n");


	// 함수 종류
	// 반환값이 없는 함수(void 함수) - 함수 정의/선언 4
	fuction_without_return();


	// 반환값이 있는 함수(void 제외) - 함수 정의/선언 5
	int ret = function_with_return();
	p(ret);


	// 파라미터(전달값)가 없는 함수
	function_without_parameters();


	// 파라미터가 있는 함수
	function_with_parameters(1, 2, 3);
	function_with_parameters(35, 17, 25);

	// 파라미터도 받고 반환값도 있는 함수
	int ret = apple(5, 2); // 5개의 사과중에서 2개를 먹었음을 의미
	printf("남은 사과의 갯수는 %d 입니다.\n", ret);

	// 또는 이렇게도 가능함
	printf("총 %d 개 중에 %d 개를 먹어 %d 개 남음.\n", 10, 4, apple (10, 4));
	
	완료한거 주석처리용 - 이거 지우면 됨 */

	// 프로젝트
	// 계산기 함수 작성

	int num = 2; // 초기값

	num = add(num, 3); // num = num + 3  = 5
	project_p(num);

	num = sub(num, 1); // num = num - 1  = 4
	p(num);

	num = mul(num, 3); // num = num * 3  = 12
	p(num);

	num = div(num, 6); //num = num / 6   = 2
	p(num);


	return 0;
}

// 정의 - 매인함수 밖에서 앞서 선언한것을 정의해야함
// 앞서 선언한 p라는 함수의 수행내용

// 함수정의 1
void p(int i)
{
	printf("num은 %d 입니다.\n", i);
}


// 함수정의 2 - 반환값이 없는 함수
void fuction_without_return()
{
	printf("반환값이 없는 함수 입니다.\n");
}

// 함수정의 3 - 반환값이 있는 함수
int function_with_return()
{
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

// 함수정의 4 - 파라미터가 없는 함수
void function_without_parameters()
{
	printf("전달값이 없는 함수입니다.\n");
}

// 함수정의 5 - 파라미터가 있는 함수
void function_with_parameters(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수입니다\n");
	printf("전달받은 값은 %d, %d, %d 입니다.\n\n", num1, num2, num3);
}

// 함수정의 6 - 파라미터도 있고 전달값도 있는 함수
int apple(int total, int eat) // 전체(total)개에서 먹고(eat) 남은 갯수(return) 계산
{
	printf("파라미터와 전달값이 모두 있는 함수입니다.\n");
	printf("총 갯수는 %d 개이고 먹은 건 %d 개입니다\n\n", total, eat);
	return total - eat;
}

// 프로젝트 사용 함수 정의
void project_p(int num) // 1 - 출력
{
	printf("num은 %d 입니다.\n", num);
}

int add(int num1, int num2) // 2 - 덧셈
{
	return num1 + num2;
}

int sub(int num1, int num2) // 3 - 뺄셈
{
	return num1 - num2;
}

int mul(int num1, int num2) // 4 - 곱셈
{
	return num1 * num2;
}

int div(int num1, int num2) // 5 - 나눗셈
{
	return num1 / num2;
}