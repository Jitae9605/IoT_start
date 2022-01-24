#include <stdio.h>

// !!! 중요한 부분 pdf 참고 하면서 공부하기 !!!
// 7. 함수(매우중요!!!!)
// 함수는 선언, 정의, 호출의 상태로 사용한다
// 목정 : 재사용성, 유지보수성, 가독성을 높이는 목적

int main_function(void)
{
	// 1. 함수의 작성과 사용

	// 1) 선언 : 함수명, 반환값자료형을 알리고 받는 매개변수를 지정
	// main의 위에서 선언

	/*
	int add(int a, int b);
	*/

	// 2) 정의: 반환값의 자료형, 이름, 매개변수지정하고 블록내에 기능을 구현
	// main 함수 아래에서 정의

	/*
	int add(int a, int b)
	{
		return a + b;
	}
	*/

	// 3) 호출: 함수를 사용하고 함수의 동작에 필요한 인수를 준다
	// main 함수 안에서 사용하거나 다른 함수 내부에서 사용(상속)한다
	// 인수는 상수,변수,수식등 모두 받을수 있지만 자료형만은 반드시 맞아야한다.

	/*
	add(10, 20);
	*/

	// 2. 주의사항
	// 사용될때 입력된 인수가 정의/선언때의 매개변수 위치에 값이 복사되어 입력되는 것
	// 그후, 함수의 수행부의 결과값이 함수 호출위치에 복사/대입되는 원리

	// 3. 다양한 함수 형태

	// 1) 매개변수 없는 경우
	// 선언 : int add(void);또는 int add();
	// 특징 : 호출할때 인수없이 괄호만 사용

	// 2) 반환형이 없는 경우
	// 선언 : void add(char ch, int a);
	// 특징 : 반환할때 return문을 쓰지 않거나 return문만 사용 - 즉시 종료됨
	//		  호출문장을 수식의 일부로 쓸수 없다

	// 3) 매개변수와 반환형 모두 없는 경우
	// 선언 : void add(void);
	// 특징 : 위의 두가지 특성을 동시에 가짐

	// 4) 재귀호출 함수
	// 선언 : void add() {... add(); ...}
	// 특징 : 함수 안에 재귀호출을 멈추는 조건이 있어야한다 (아님 무한 반복함)

	return 0;
}

