#include <stdio.h>
#pragma warning(disable:6031)

struct address									// 주소록 구조체선언
{
	char name[20];								// 이름
	int age;									// 나이
	char tel[20];								// 전화번호
	char addr[80];								// 주소
};

void print_list(struct addrss* lp);

int main(void)
{
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "을릉도 독도"},
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};

	print_list(list);


	return 0;
}

void print_list(struct address* lp)			// 매개변수 : 구조체 포인터
{
	int i;									// 반복 횟수

	for (i = 0; i < 5; i++)					// 배열 요소 수 만큼 반복
	{
		printf("%10s%5d%15s%20s\n",			// 배열요소 출력[ (lp+i) -> 멤버이름 ]
			(lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
	}

}