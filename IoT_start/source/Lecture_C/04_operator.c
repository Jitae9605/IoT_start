#include <stdio.h>

// 4. 연산자
// &&, ||, ==, !=, ++, --, %, *, /, = 등등의 연산자

int main(void)
{
	
	// 1. 산술연산자
	int a, b;
	int sum, sub, mul, inv,div, rest;

	a = 10;						// 대입 연산(=)
	b = 20;						// 대입 연산(=)
	sum = a + b;				// 덧셈연산(+) 후 대입연산(=)
	sub = a - b;				// 뺄셈연산(-) 후 대입연산(=)
	mul = a * b;				// 곱셈연산(*) 후 대입연산(=)
	inv = - a;
	div = b / a;				// 나눗셈연산(/) 후 대입연산(=)
	rest = b % a;				// 나머지연산(%) 후 대입연산(=)

	printf("a의 값 : %d, b의 값 : %d\n", a, b);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a의 음수연산 : %d\n", inv);
	printf("나눗셈 : %d\n", div);
	printf("나머지구하기 : %d\n", rest);


	// 2. 증감연산자
	// a++, a-- : 후위형 = 다른 연산자와 함꼐 사용되면 제일 나중 순위로 증감 수행
	// ++a, --a : 전위형 = 증감후 연산
	// 
	
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;			// 전위형 증감 연산자
	post = (b++) * 3;			// 후위형 증감 연산자
	
	printf("초깃값:  a = %d, b = %d\n", a, b);
	printf("전위형: (++a ** 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);

	
	// 3. 관계연산자
	// <, >, >=, <=, ==(일치시 true), !=(불일치시 true)
	int a = 10, b = 20, c = 10;
	int res;							// 결과값을 저잘항 변수 (result)

	res = (a > b);						// a가 b보다 크지 않으므로 결과값은 0
	printf("a > b : %d\n", res);

	res = (a >= b);						// a가 b보다 크거나 같지 않으므로 결과값은 0
	printf("a >= b : %d\n", res);

	res = (a < b);						// a가 b보다 작으므로 결과값은 1
	printf("a < b : %d\n", res);

	res = (a <= b);						// a가 b보다 같진않지만 작으므로 결과값은 1
	printf("a <= b : %d\n", res);

	res = (a <= c);						// a가 c보다 작진않지만 같으므로 결과값은 1
	printf("a <= c : %d\n", res);

	res = (a == b);						// a가 b와 같지않으므로 결과값은 0
	printf("a == b : %d\n", res);

	res = (a != c);						// a가 c와 같으므로 결과값은 0
	printf("a != c : %d\n", res);

	
	// 4. 논리연산자
	// &&(and), ||(or), !(not)

	int a = 30;
	int res;

	printf("a의 값은 : %d\n", a);
	res = (a > 10) && (a < 20);						// 좌우 두항이 모두 참이면 참
	printf("(a > 10) && (a < 20) : %d\n", res);

	res = (a < 10) || (a > 20);						// 좌우 두항중 하나라도 참이면 참
	printf("(a < 10) || (a > 20) : %d\n", res);

	res =  !(a >= 30);						// 거짓이면 참, 참이면 거짓
	printf("!(a >= 30 ):  %d\n", res);

	
	// 5. 기타연산자
	// 형변환, sizeof, 복합대입(+=, -=, *= ... ), 콤마, 조건(? :),
	// 비트(&, ^, :, ~, <<, >>) = 중요X

	// 1) 형변환 연산자
	// 실제 값을 바꾸는게 아니라 현재의 줄에서의 피연산자의 형을 변환

	printf("형변환 연산자\n");
	int a = 20, b = 3;
	double res;

	res = ((double)a / (double)b);				// a와 b 자료형을 실수형으로 바꿈
	printf("a = %d, b = %d\n", a, b);			// 실제 a와 b는 여전히 정수형
	printf("a / b의 결과 %.1lf\n", res);

	a = (int)res;								// res의 값에서 정수 부분만 a에 저장 
	printf("(int)%.1lf의 결과 %d\n\n", res, a);

	// 2) sizeof 연산자
	// 데이터 크기확인, 메모리 동적 할당 작업에 사용
	printf("sizeof 연산자\n");
	int a1 = 10;
	double b1 = 3.4;

	printf("int형의 변수의 크기 : %d\n", sizeof(a1));
	printf("double형의 변수의 크기 : %d\n", sizeof(b1));
	printf("정수형 상수의 크기 : %d\n", sizeof(10));
	printf("수식의 결과값의 크기 : %d\n", sizeof(1.5 + 3.4));
	printf("char 자료형의 크기 : %d\n\n", sizeof(char));

	// 3) 콤마 연산자
	// 왼쪽부터 차례로 연산수행하고 가장 우측의 피연산자가 최종 결과값

	printf("콤마 연산자\n");

	int a2 = 10, b2 = 20;
	int res2;

	res2 = (++a2, ++b2);			// 차례대로 연산이 수행되어 결과적으로 
									// res2에 저장되는 값은 증가된 b의 값이다.

	printf("a:%d, b:%d\n", a2, b2);
	printf("res:%d\n", res2);

	// 4) 조건 연산자
	// ?와 : 기호 함께 사용
	// (피연산자1) ? (피연산자2) : (피연산자3)꼴로 피연산자1은 주로 조건식이다.
	// 피연산자1이 참이면,   피연산자2가 결과값 
	//			   거짓이면, 피연산자3이 결과값
	
	printf("조건 연산자\n");
	int a3 = 10, b3 = 20, res3;
	
	res3 = (a3 > b3) ? a3 : b3;			// a3와 b3중에서 큰 값이 res3에 저장됨
	printf("큰 값 : %d\n", res3);

	// 피연산자2, 3 을 문장으로 사용 가능
	// (a > b) ? (res1 = a) : (res2 = b) 와 같이 사용
	// 참/거짓 에따라 값을 다른곳에 적용해야 할경우 사용


	// 5) 복합대입연산자
	// +=, -=, *=, /= 등
	int a = 10, b = 20;
	int res = 2;

	a += 20;				// a와 20을 더한 결과를 다시 a에 저장 (= a = a + 20)
	res *= b + 10;			// b 에 10을 더한 결과값에 res를 곱한 뒤 res에 저장
							//		== res = res * (b + 10)

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);




	return 0;
}