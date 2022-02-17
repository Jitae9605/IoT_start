#include<stdio.h>
#include"20_1_student.h"		// 현재디렉토리경로내에 저장된 사용자 정의 헤더파일 포함		(상대경로)
// #include"D:\1_IoT\IoT_start\IoT_start\source\Class,lecture\20_1_student.h"			(절대경로)
//		!!! 역슬래시는 한번만 !!!

// ========================================= 매크로 선언부 ====================================================================

// 2) 매크로
#define PI 3.14159										// 상수 매크로로 정의
#define LIMIT 100.0										// 상수 매크로로 정의
#define MSG "passed!"									// 문자열 매크로로 정의
#define ERR_PRN printf("허용 범위를 벗어났습니다.\n")		// 출력문 매크로로 정의

// 3) 매크로
#define SUM(a,b) ((a) + (b))
#define MUL(a,b) ((a) * (b))

// 4) 매크로

//	시스템 기본 제공 헤더파일은 <> 을 이용하고 사용자 정의헤더파일의 경우 ""를 이용한다 ( 경로의 차이 )

// ========================================= 함수 선언부 ====================================================================

// 4)이미 정의된 매크로 사용 함수선언
void func_4(void);


// ========================================= main 함수 ====================================================================

int main(void)
{
	// 20. 전처리

	printf("\n------------------- < 1) 사용자 정의 헤더파일 포함(include) > ---------------------------------------------\n\n");

	Student a = { 315, "홍길동" };							// 구조체변수선언 및 멤버입력

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);			// 멤버 출력

	printf("\n------------------- < 2) 다양한 매크로 사용(define) > ---------------------------------------------\n\n");

	double radious_2, area_2;								// 변수(반지름, 넓이)선언

	printf("반지름을 입력하세요(10 이하) : ");			
	scanf("%lf", &radious_2);								// 반지름 입력받음
	area_2 = PI * radious_2 * radious_2;					// 넓이 계산
	if (area_2 > LIMIT) ERR_PRN;							// 면적이 100을 초과하면 오류코드 출력
	else printf("원의 면적 : %.2lf (%s)\n", area_2, MSG);	// 결과출력

	printf("\n------------------- < 3) 매크로함수 사용 > ---------------------------------------------\n\n");

	int a_3 = 10, b_3 = 20;
	int x_3 = 30, y_3 = 40;
	int res_3;

	printf("a + b = %d\n", SUM(a_3, b_3));
	printf("x + y = %d\n", SUM(x_3, y_3));

	res_3 = 30 / MUL(2, 5);
	printf("res_3 : %d\n", res_3);

	printf("\n------------------- < 4)이미 정의된 매크로 사용 > ---------------------------------------------\n\n");

	// __DATE__			= 컴파일을 시작한 날짜
	// __TIME__			= 컴파일을 시작한 시간
	// __FILE__			= 전체디렉토리 경로를 포함한 파일명
	// __FUNCTION__		= 매크로명이 사용된 함수의 이름
	// __LINE__			= 매크로명이 사용된 행번호
	
	printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"				// 행 번호를 100부터 시작, 파일명은 macro.c로 표시한다는 의미
	func_4();					// 여기서부터 행번호 100번임
	// #line은 __LINE__ 또는 __LINE__과 __FILE__ 의 출력값을 조절한다.

	return 0;
}

// ========================================= 함수 정의부 ====================================================================

//	4)이미 정의된 매크로 사용 함수정의
void func_4(void)
{
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);
}