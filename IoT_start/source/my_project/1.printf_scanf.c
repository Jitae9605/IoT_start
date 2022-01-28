#include <stdio.h>
int mainPrintfScanf(void)
{
	/* 완료한거 주석처리용 - 이거 지우면 됨
	 
	//정수형 변수 예제
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);
	printf("----------------------------------\n");

	// 실수형 변수 예제
	float f = 46.5f; //float를 쓸때 숫자 맨뒤에는 항상"f"를 붙일 것
	printf("%.2f\n", f); //%f 대신 %.2f 를 쓴 이유는 출력을 소수 2째자리까지 출력하라는 표시 없으면 길게 출력된다 ex) 46.500000
	double d = 4.428; 
	printf("%.2lf\n", d); // float는 %f double은 %lf 이다
	const int YEAR = 2000; //const = 상수로 지정 = 이 값은 이후로 절대 바뀌지 않음 (이 줄 제외)
	printf("태어난 년도 : %d\n", YEAR);
	printf("----------------------------------\n");

	// printf
	//연산
	int add = 3 + 7; // 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d + %d = %d\n", 30, 79, 30 + 79);
	printf("%d * %d = %d\n", 30, 79, 30 * 79);
	printf("----------------------------------\n");

	//scanf
	//키보드 입력을 받아서 저장
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input); // "받는 값선언"(%d = 정수형을 받겠다), &input(= 받은 값을 input이라는 변수에 입력)
	printf("입력값 : %d\n", input);
	printf("\n");

	// 여러개 받아서 각각을 따로 저장하는 법
	int one, two, three;
	printf("3개의 정수를 입력하세요. : ");
	scanf_s("%d %d %d", &one, &two, &three); // 입력할때 각 값은 띄어쓰기를 통해 구분
	printf("첫 번째 값: %d\n", one);
	printf("두 번째 값: %d\n", two);
	printf("세 번째 값: %d\n", three);

	// 문자(한 글자), 문자열(여러 글자)
	char c = 'A'; // 문자 = char
	printf("%c\n", c); // 문자 = %c
	
	char str[256]; // 문자열 = char str[열 갯수]
	scanf_s("%s", str, sizeof(str)); //문자열 = %s, 문자열을 받으면 '&'는 생략 대신 크기를 명시해야함(sizeof(문자열 이름))
	printf("%s\n", str);
	// 의문 : sizeof(s
	tr)은 크기가 4개인데 저사람은 어떻게?
	printf("----------------------------------\n");

	완료한거 주석처리용 - 이거 지우면 됨 */ 
	
	//프로젝트
	// 경찰관이 범죄자의 정보를 입수(조서 작성)
	// 이름? 나이? 몸무게? 키? 범죄명?
	char name[256];
	printf("이름이 뭐에요? ");
	scanf_s("%s", name, sizeof(name));
	
	int age = 0;
	printf("몇살이에요? ");
	scanf_s("%d", &age);

	float weight = 0;
	printf("몸무게는 몇 kg이에요? ");
	scanf_s("%f", &weight);

	double height = 0;
	printf("키는 몇 cm 에요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀어요? ");
	scanf_s("%s", what, sizeof(what));

	// 조서내용출력
	printf("\n\n--- 범죄자정보 ---\n\n");
	printf("이름    : %s\n", name);
	printf("나이    : %d\n", age);
	printf("몸무게  : %.2f\n", weight);
	printf("키      : %.2lf\n", height);
	printf("범죄    : %s\n", what);





	return 0;
}