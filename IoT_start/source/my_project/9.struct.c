#include <stdio.h>

// 구조체 선언
struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관업체 게임(friendGame = 포인터)
};

// 매번 struct쓰기 귀찮을때 쓰는 방법 2번째
// 첫 선언에서 부터 typedef 박기
typedef struct GameInformation { // 이 경우에는 이름인 GameInformation 없어도 됨
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관업체 게임(friendGame = 포인터)
} GAME_INFO; // = typedef struct GameInformation { ~ } GAME_INFO;
			 //  꼴 : 'typedef 대상(struct ~ {~} 별명

int main_struct(void)
{


	// [게임출시 가정]
	// 이름 : 나도게임
	// 발매년도 : 2017 년
	// 가격 : 50원
	// 제작사 : 나도회사

	//char* name = "나도게임";
	//int year = 2017;
	//int price = 50;
	//char* company = "나도회사";

	// [또다른 게임출시 가정]
	// 이름 : 너도게임
	// 발매년도 : 2017 년
	// 가격 : 100원
	// 제작사 : 너도회사

	//char* name2 = "너도게임";
	//int year2 = 2017;
	//int price2 = 100;
	//char* company2 = "너도회사";

	// 이런게 만약 100개가 넘어간다면 알아보기 힘들고 정신이 없다
	// 이를정리하기 위해 '구조체'를 사용한다

	printf("----------------------------------\n");

	// 구조체 사용(단순사용)
	struct GameInfo gameinfo1;
	// struct GameInfo gameinfo2; // 이렇게 2번째도 한번에 선언 해서 가능
	gameinfo1.name = "나도게임";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";
	
	printf("-- 게임 출시 정보(구조체 단순출력) --\n");
	printf("   게임명     : %s\n", gameinfo1.name);
	printf("   발매년도   : %d\n", gameinfo1.year);
	printf("   가격       : %d\n", gameinfo1.price);
	printf("   제작사     : %s\n\n", gameinfo1.company);

	printf("----------------------------------\n");

	// 구조체를 배열처럼사용 (배열)
	struct GameInfo gameinfo2 = { "너도게임", 2017, 100, "너도회사" };
	printf("-- 또다른 게임 출시 정보(구조체 한줄 배열사용) --\n");
	printf("   게임명     : %s\n", gameinfo2.name);
	printf("   발매년도   : %d\n", gameinfo2.year);
	printf("   가격       : %d\n", gameinfo2.price);
	printf("   제작사     : %s\n\n", gameinfo2.company);


	printf("----------------------------------\n");


	// 구조체 배열(다중사용)
	struct GameInfo gameArray[2] = {
		{"나도게임", 2017, 50, "나도회사"},
		{"너도게임", 2017, 100, "너도회사"}
	};

	printf("-- 게임 출시 정보(구조체 다중배열사용) --\n");
	printf("   게임명     : %s\n", gameArray[0].name);
	printf("   발매년도   : %d\n", gameArray[0].year);
	printf("   가격       : %d\n", gameArray[0].price);
	printf("   제작사     : %s\n\n", gameArray[0].company);

	printf("-- 또다른 게임 출시 정보 --\n");
	printf("   게임명     : %s\n", gameArray[1].name);
	printf("   발매년도   : %d\n", gameArray[1].year);
	printf("   가격       : %d\n", gameArray[1].price);
	printf("   제작사     : %s\n\n", gameArray[1].company);

	printf("----------------------------------\n\n");

	// 구조체 포인터
	struct GameInfo* gamePtr; // 수행자(gamePtr이라는 포인터를 만듬)
	gamePtr = &gameinfo1; // 포인터 gamePtr은 gameinfo1의 주소에 대한 바로가기임
	printf("-- 수행자의 게임 출시 정보(구조체 포인터 사용법 - 1) --\n\n");

	// gamePtr = gamePtr이라는 바로가기가 가르키는 주소
	// *gamePtr = gamePtr이라는 바로가기가 가르키는 파일(폴더)내부의 값(더블클릭)
	printf("   게임명     : %s\n", (*gamePtr).name); // 괄호 안치면 (*gamePtr.name)으로 인식
	printf("   발매년도   : %d\n", (*gamePtr).year);
	printf("   가격       : %d\n", (*gamePtr).price);
	printf("   제작사     : %s\n\n", (*gamePtr).company);

	// 또는 

	// '->' 를 사용
	// 'gamePtr->name' = gamePtr이 가르키는 값 내부의 name항목의 값이라는 의미
	printf("-- 수행자의 게임 출시 정보(구조체 포인터 사용법 - 1) --\n");
	printf("   게임명     : %s\n", gamePtr->name); // -> = 내부의 값에서 name에 해당하는 값 호출
	printf("   발매년도   : %d\n", gamePtr->year);
	printf("   가격       : %d\n", gamePtr->price);
	printf("   제작사     : %s\n\n", gamePtr->company);

	printf("----------------------------------\n");

	// 연관업체 게임 소개 (구조체 내에 또다른 구조체를 만들어 사용)
	gameinfo1.friendGame = &gameinfo2;
	printf("\n\n-- 연관업체의 게임 출시 정보(구조체 포인터 사용법 - 1) --\n");
	printf("   게임명     : %s\n", gameinfo1.friendGame->name); // -> = 내부의 값에서 name에 해당하는 값 호출
	printf("   발매년도   : %d\n", gameinfo1.friendGame->year);
	printf("   가격       : %d\n", gameinfo1.friendGame->price);
	printf("   제작사     : %s\n\n", gameinfo1.friendGame->company);

	printf("----------------------------------\n");

	// 매번 struct쓰기 귀찮을때 ㅈ가지 방법
	
	// 1. typedef (= 자료형에 별명지정 하는 함수)
	int i = 1;
	typedef int 정수; // 'int'라는 자료형 대신 '정수'라는 글자로 int자료형 표현가능
	typedef float 실수;
	정수 정수변수 = 3; //  = int i = 3;
	실수 실수변수 = 3.23f; //  = float f = 3.23f;
	printf("\n\n정수변수 : %d, 실수변수 : %.2f\n\n", 정수변수, 실수변수);

	// 구조체에 적용
	typedef struct GameInfo 게임정보; // 'struct GameInfo' = '게임정보'
	게임정보 game1; // = struct GameInfo game1;
	game1.name = "한글 게임";
	game1.year = 2015;

	// 2. struct 선언에서 부터 typedef를 통해 별명을 달아준다
	// 'struct GameInformation' 을 'GAME_INFO' 로 만듬
	
	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2015;

	// 단, 별명일뿐 이름이나 구조체는 그대로 있어서 본래의 것도 사용가능
	// 아예 struct만 주고 이름 없이 선언해서 별명만 주어도 사용은 가능하다.
	struct GameInformation game3;
	game3.name = "한글 게임3";
	game3.year = 2016;



	return 0;
}