#include <stdio.h>



// ========================================= main 함수 ====================================================================


int main(void)
{
	// 18. 문자열에 대한 이해


	printf("\n------------------- < 1) 문자열 상수는 주소다! > ---------------------------------------------\n\n");

	printf("apple이 저장된 시작 주소 값 : \t%p\n", "apple");						// 주소값 출력
	printf("두 번째 문자의 주소 값 : \t%p\n", "apple" + 1);						// 주소값 출력 (위와 딱 1 차이난다)

	printf("첫번째 문자 : \t\t\t\t%c\n", *"apple");								// 간접 참조 연산
	printf("두번째 문자 : \t\t\t\t%c\n", *("apple" + 1));						// 포인터 연산식
	printf("배열로 표현한 세 번째 문자 : \t%c\n", "apple"[2]);					// 배열 표현식
	
	// !!! 주소로 접근해서 문자열을 바꾸면 안됨 !!!
	// Ex) *"apple" = 't'
	// 와 같은 주소의 첫 문자를 't'로 바꾸는 시도는 실행은 되지만 운영체제가 강제종료할수도, 버전에 따라 실행되지만 시스템의 손상/오류를 일으킬수 있다
	// 호환성/안전성 등을 모두 헤치는 행위!

	printf("\n------------------- < 2) char 포인터로 문자열 사용 > ---------------------------------------------\n\n");

	char* dessert_2 = "apple";

	printf("오늘 후식은 %s 입니다.\n", dessert_2);
	dessert_2 = "banana";
	printf("내일 후식은 %s 입니다.\n", dessert_2);

	// 포인터 dessert에 저장된것은 문자열이 아니다.
	// 문자열 "apple" 과  "banana"는 상수로 메모리상수공간속 어딘가에 지정되었고
	// dessert에는 그 공간(배열)의 첫 시작좌표가 저장되어 있는 것!

	printf("\n------------------- < 3) scanf와 문자열 사용 및 심화 > ---------------------------------------------\n\n");

	char str_3[80];

	printf("문자열 입력 : ");
	scanf("%s", str_3);
	printf("첫 번째 단어 : %s \n", str_3);
	scanf("%s", str_3);
	printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str_3);


	//	실행후 "apple jam"을 입력하고 ENTER를 누르면 버퍼에는 'a' 'p' 'p' 'l' 'e' '(공백)' 'j' 'a' 'm' 'ENTER' 가 저장된다.
	//	scanf에 의해 공백(스페이스)전까지의 내용인 "apple"이 str_3에 저장되고 뒤에 널문자를 추가 저장한다. (첫 번째 단어)
	//	그런데 다음 scanf는 버퍼에 내용이 있기때문에 키보드입력을 생략하고 공백,탭,개행문자를 제외한 버퍼내용을 그대로 str_3에 넘겨줍니다.(두번째 단어)
	//	그 결과 str_3은 "apple000...000"에서 덮어씌워져 "jam0e000...000" 이 저장되어 있고 e가 중간에 끼어있지만 printf 등의 함수사용 출력에서 분자열 끝의 판단은
	//	처음 만나는 널문자이므로 배열/주소 등을 이용해 억지로 출력하지 않는 한 jam까지 출력된다.


	printf("\n------------------- < 4) gets함수의 이해 > ---------------------------------------------\n\n");

	//	gets함수는 개행문자 입력전까지의 모든 것을 입력받아 넘기는 함수로 마지막에 입력되는 개행문자까지 모두 들고와서 변수에 저장
	//	대신, 마지막에 가지고온 개행문자를 널문자로 변환!
	//	즉, 버퍼에 개행문자가 남지 않는다는 장점!

	fgetc(stdin);				// 버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림 ( !!! fgets가 아니라 fgetc임을 주의 !!!! )

	char str_4[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str_4);									// gets 함수 사용 (입력받은 문자열을 저장할 공간지정)
	printf("입력한 문자열은  %s 입니다.", str_4);

	printf("\n------------------- < 5) fgets함수의 이해 > ---------------------------------------------\n\n");
	// scanf와 gets는 지정된 배열 넘어서는 범위까지 입력받은 문자등을 그대로 메모리에 저장하는 메모리 침범의 우려가 있다!!!
	// 이를 방지하기 위해 미리 최대배열크기를 계산해서 집어넣는 fgets함수를 사용하면 안정성을 높일수 있다.
	// fgets는 또한 개행문자까지 모두 변수에 넘기기때문에 출력하면 자동으로 개행된다!

	char str_5[80];

	printf("공백이 포함된 문자열 입력 : ");
	fgets(str_5,sizeof(str_5),stdin);			// fgets(입력받은 문자열을 저장할 공간의 주소(&+변수명 or 배열명), 배열의 크기(보통 sizeof로 사용), stdin(표준입력을 의미))
	printf("입력한 문자열은  %s 입니다.", str_5);

	// * 키보드로 입력받을때는 항상 stdin을 적어야한다
	// ** fgets는 버퍼의 개행문자도 모두 지정한 변수공간에 집어넣고 그 끝에 널문자를 붙인다
	//		(scanf = 개행문자 버퍼에 그대로둠, 변수에 입력X)
	//		(gets  = 개행문자까지 버퍼에서 빼서 변수에 저장, 저장후 입력된 개행문자를 널문자로 교체)
	//		(fgets = 개행문자까지 버퍼에서 빼서 변수에 저장, 저장후 지정된 배열의 크기 + 1 위치에 널문자 삽입 (그냥 배열크기 넣으면 개행문자뒤에 널문자가 추가되는 것)


	printf("\n------------------- < 6) 버퍼 비우는 방법 > ---------------------------------------------\n\n");
	// 버퍼를 비우지 않으면 입력받아야할때 문제가 생긴다.

	getchar();					// 버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림
	scanf("%*c");				// 버퍼에서 하나의 문자를 읽어서 버림, 변수는 필요없음 (scnaf("%*c") 는 버퍼를 비우는 약속(일종의 아스키코드종류)이다) 
	fgetc(stdin);				// 버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림 ( !!! fgets가 아니라 fgetc임을 주의 !!!! )

	// 주의할점은 버퍼가 원래 비어있을경우 커서만 깜빡여서 ENTER를 눌러줘야 넘어간다

	// Ex)
	printf(" < 버퍼비우기 수행 안하고 값 입/출력 수행 > \n\n");
	int age_6_1;
	char name_6_1[20];

	printf("나이입력 : ");
	scanf("%d", &age_6_1);

	printf("이름 입력 : ");
	gets(name_6_1);
	printf("나이 : %d, 이름 : %s\n", age_6_1, name_6_1);

	printf("\n\n < 버퍼비우기 수행 안하고 값 입/출력 수행 > \n\n");
	int age_6_2;
	char name_6_2[20];

	printf("나이입력 : ");
	scanf("%d", &age_6_2);
	fgetc(stdin);				// 버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림 ( !!! fgets가 아니라 fgetc임을 주의 !!!! )

	printf("이름 입력 : ");
	gets(name_6_2);
	printf("나이 : %d, 이름 : %s\n", age_6_2, name_6_2);


	 
	printf("\n------------------- < 7) puts와 fputs함수의 이해 > ---------------------------------------------\n\n");
	// puts 와 fputs 모두 문자열을 출력하는 함수이지만 puts는 출력하고난뒤 맨끝에 자동으로 개행문자를 통해 줄바꿈을 수행한다.



	char str_7[80] = "apple juice";
	char* ps_7 = "banana";

	puts(str_7);
	fputs(ps_7, stdout);		// stdout = 표준출력버퍼 (현시점에서 신경X)
	puts("milk");


	return 0;
}
