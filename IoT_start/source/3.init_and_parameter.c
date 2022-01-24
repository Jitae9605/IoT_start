#include <stdio.h>
#include <string.h>

// 3.변수와 데이터입력
// 변수선언, 쓰레기값 초기화

int main_parameter(void)
{
	/* 

	// 1. 쓰레기값 출력
	int a;					 // printf 문에서 초기화 
	int b;					 // 초기화 x
	int c = 20;				 // 초기화 o

	a = 10;
	printf("a: %d\n", a);	
	printf("b: %d\n", b);	// 초기화 안했다는 에러발생! 
	printf("c: %d\n", c);

	*/

	/*
	
	// 2. 아스키코드
	// char을 이용하면 아스키코드를 이용할수 있다.

	char ch1 = 'A';		 // 문자로 초기화
	char ch2 = 65;		 // 문자 'A'의 아스키 코드값으로 초기화

	printf("문자 %c의 아스키 코드값 : %d\n", ch1, ch2);
	printf("아스키 코드값이 %d인 문자 : %c\n", ch1, ch2);

	// 아스키코드는 표를 보면 된다.
	
	*/

	/*
	
	// 3. 다양한 정수형 데이터 타입

	short sh = 32767;				 // short형의 최대값 (초기화역할)
	int in = -2147483648;		     // int형의 최솟값 (초기화역할)
	long ln = 2147483647;			 // long형의 최댓값 초기화
	long long lln = 123451234512345; // 아주 큰 값 초기화

	printf("short형 변수 출력 : %d\n", sh);			   // short 형 = %d
	printf("int형 변수 출력 : %d\n", in); 
	printf("long형 변수 출력 : %ld\n", ln);			  // long 형 = %ld
	printf("long long형 변수 출력 : %lld\n", lln);    // long long 형 = %lld
	
	// int = 연산빠름
	// short = 메모리적게사용, 연산느림
	// long = 불필요
	// long long = 메모리 매우 낭비, 매우 큰 값 저장가능
	*/

	/*

	// 4. unsigned

	// 본래 [ -(n+1) ~ +n ] 범위인 것을 음수를 사용하지 않는다고 선언(unsigned)하여 
	// 범위를 2배( [ 0 ~ +2n ] 로 늘린 것

	// unsigned int = %u
	// unsigned short = %u
	// unsigned char = %u
	// unsigned long = %lu
	// unsigned long long = %llu

	*/

	/*

	// 5. 다양한 실수형 데이터 타입

	float ft = 1.234567890123456789;			 // 유효숫자 많은것으로 초기화
	double db = 1.234567890123456789;

	printf("float형 변수 값 : %.20f\n", ft);
	printf("double형 변수 값 : %.20lf\n", db);

	// float의 유효숫자 한계는 7
	// double은 15개의 유효숫자를 가진다.
	// 둘사이의 차이는 별로 없으니 유효숫자많은 doiuble사용을 기본으로 할것

	*/


	/*

	// 6. 문자열의 이해

	// char은 본래 하나씩을 저장하나 이를 배열로서 저장이 가능하다.
	// 대괄호([])안의 숫자는 바이트(byte)이고 숫자와 영어는 글자당 1byte, 한글은 2byte다
	// 즉, a[6]은 끝의 널문자를 빼서 5byte의 영어/숫자 5개 나 한글 2개 + 영어/숫자 1개

	char fruit1[6] = "apple";	 // apple = 5개 이지만, 배열의 끝은 알리기 위해 
								 // 항상 끝에 널문자인 '\0' 이 삽입되므로 [6]을 선언

	// * 부가설명 * 
	// char A[7]; = ㅁㅁㅁㅁㅁㅁㅁ 이고

	// char A[7] = "apple"; = 'a' 'p' 'p' 'l' 'e' ㅁ '\0' 이다.
							   1   2   3   4   5   6   7

	// char B[7] = "홍길동"; = '홍' '길' '동' '\0' 이다
							 	2	 4	  6     7		


	// * 문자열 예제 *
	char fruit[20] = "strawberry"; // char 벼열 선언과 초기화

	printf("딸기 : %s\n", fruit);				// 배열명으로 strawberry 출력
	printf("딸기쨈 : %s %s\n", fruit, "jam");   // 문자열은 %s로 출력
	printf("좋아하는 과일 : %s\n", fruit);

	// * 주의사항 * 
	// 이미 선언되 함수를 덮어쓰는건 불가능 (반복문 등으로 한글자씩 공간에 다시 넣어줘야함)

	char fruit[20] = "strawberry";
	fruit = "banana";
	// 이건 불가능 하다는 의미

	// 대신, <string.h> 헤더를 선언하고 'strcpy'함수를 이용해 가능

	char fruit[20] = "strawberry";	  // fruit 선언 및 "strawberry"로 초기화
	printf("%s\n", fruit);			  // fruit 출력 ( = strawberry)

	strcpy(fruit, "banana");		  // strcpy함수를 이용해 fruit 내용을 모두 지우고
									  // "banana"를 내부에 입력
	printf("%s\n", fruit);			  // fruit 출력 ( = banana)
	

	*/

	/*

	// 7. 상수선언(const)
	// 원주율(3.14)와 같이 절대 변경될 이유와 필요가 없고 중요한 숫자 관리 가능

	*/

	/*

	// 8. 예약어와 식별자
	// 예약어 = 이미 시스템/컴파일러에서 정의한 이름(int, float, const ... )
	// 식별자 = 사용자가 선언하는 이름 (a, b, fruit, ... )

	// * 식별자 규칙 * 
	// 식별자는 예약어를 제외하고 사용이 가능하며 
	// 알파벳 대/소문자, 숫자, 밑줄로 구성되고 숫자로 시작할수 없다.

	*/

	/*

	// 9. scanf 함수
	// 키보드로부터 데이터를 입력받는 함수
	// scanf함수 = 키보드로 부터 값(%d/s/c..)을 받아 변수(&변수명)에 값을 넣어준다
	// scnaf("%d", &변수명1); = 키보드로 부터 정수형데이터(%d)를 받아서 
	//							변수명1의 값이 저장된 공간에 받은 데이터를 넣음
	
	// Ex)
	int a;						// a라는 이름의 변수 선언
	scanf("%d", &a);			// 정수형 데이터를 입력받아서 a라는 변수에 값을 입력
	printf("a: %d\n", a);		// 변수 a의 값 출력 
	
	int i, j;							// 변수 동시선언
	scanf("%d %c", &i, &j);				// 두개이상의 값 한번에 입력받기
	printf("i: %d\nj: %c\n", i, j);		
	
	// * 예제 *
	int age;
	double height;

	printf("나이와 키를 입력하세요: ");						// 입력안내메세지 출력
	scanf("%d %lf", &age, &height);							// 나이와 키 입력
	printf("나이는 %d살, 키는 %.1lf cm입니다.\n", age, height);	// 입력한 값 출력
	
	*/

	/*

	// 10. 문자와 문자열 입력

	// * 주의사항 *
	// 1) char형 입력받을경우, 스페이스/엔터도 하나의 문자로 입력을 받는다
	// 2) 문자열은 char배열에 %s변환문자 사용해 입력
	// 3) 문자열 입력할때는 배열명에 &기호 사용X 
	//							-> 배열은 배열명 자체가 하나의 주소
	// 4) 문자열 중간에 빈칸이 있으면 그 전까지만 입력받음
	//							-> 공백을 포함해서 입력받는 함수는 따로있다(gets())

	// * 예제 *
	char grade;							// 학점을 입력할 변수(문자)
	char name[20];						// 이름을 입력한 배열(문자열)

	printf("학점입력 : ");
	scanf("%c", &grade);				// grade 변수에 학점 문자 입력

	printf("이름 입력 : ");
	scanf("%s", name);					// name 배열에 이름 문자열 입력(&기호 사용X)

	printf("%s의 학점은 %c입니다. \n", name, grade);

	*/

	
	return 0;
}