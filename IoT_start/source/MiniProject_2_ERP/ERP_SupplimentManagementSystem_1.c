#include <stdio.h>
#include<conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// ERP 시스템 입고처리에 사용될 구조체와 입고구조 원리

struct In_WareHouse					// 입고구조체
{
	char name_warehouse[20];		// 창고이름
	int num_warehouse;				// 창고번호
	char name_item[20];				// 품목이름
	int num_item;					// 품목번호
	int date;						// 입고날짜
	char name_responsible[20];		// 담당자이름
	int num_responsible;			// 담당자번호
	int num_in;						// 입고수량
	int bill;						// 단가
	int pay_in;						// 공급가액 = 입고수량 * 단가
	int tax;						// 부가세 = 공급가액 * 0.1
	int pay_sum;					// 합계액 = 공급가액 + 부가세;
};

struct Buy_item						// 발주 구조체
{
	char name_item[20];				// 발주품명
	int num_item;					// 발주품번
	int date;						// 발주날짜
	char name_responsible[20];		// 담당자이름
	int num_responsible;			// 담당자번호
	int num_buy;					// 발주수량
	int bill;						// 단가
	int pay_in;						// 공급가액 = 발주수량 * 단가
	int tax;						// 부가세 = 공급가액 * 0.1
	int pay_sum;					// 합계액 = 공급가액 + 부가세;
	int rest_num_in;				// 남은발주수량(분할 입고될시 남은 입고수량계산을 위함)
};

struct Buy_company					// 거래처구조체
{
	char name_buy_company[20];		// 거래처 이름
	int num_buy_company;			// 거래처 번호
};

struct Person_responsibe			// 담당자구조체
{
	char name_responsible[20];		// 담당자이름
	int num_responsible;			// 담당자번호
};

struct item							// 품목구조체
{
	char name_item[20];				// 품목 품명
	int num_item;					// 품목 품번
};

int main()
{
	// < 입고처리 >
		/*
		
		선택 - 1. 예외입고 2. 발주입고

		1. 예외입고
		(예외입고는 전화발주등으로 발주한 품목의 입고를 입력하는 것)

		입고일자(입력)
		거래처(선택 - 서버로부터 거래처구조체리스트를 받아옴)
		담당자(선택 - 서버로부터 담당자 구조체리스트 받아옴)
		품목(선택 - 서버로부터 품목구조체리스트 받아옴)
		발주수량(입력)
		단가(입력)

		------------까지 입력받고,

		공급가액(자동계산 : 발주수량 * 단가)
		부가세(자동계산 : 공급가 * 0.1)
		합계액(자동계산 : 부가세 + 공급가액)

		------------을 계산해서 여기까지의 입력 / 계산 내용을 양식에 맞게 출력후
		사용자로부터 입력내용이 맞으면 입력(1), 틀리면(2)입력받음

		맞다(1)->입고구조체에 이 내용을 삽입(서버)

		2. 발주입고

		1) 발주현황을 출력(서버로부터 발주구조체를 받아옴)하고 여기서 어떤 발주사항에 대해서 입고할지 선택
		2) 선택한 발주사항중 어떤 품목을 입고할지 입력
		3) 입고수량을 입력(이때, 입고수량이 남은발주수량을 넘는지 확인)
		4) 여기까지 내용을 출력후 맞는지 사용자확인후 발주구조체(서버)의 남은발주수량을계산(초기값은 발주수량, 입고될때마다 입고수량을 뺀다)
		5) 입고구조체에 내용삽입(서버)

		*/





	return 0;
}