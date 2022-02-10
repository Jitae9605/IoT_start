#include <stdio.h>
#pragma warning(disable:6031)

struct list					// 자기참조구조체
{
	int num;				// 데이터를 저장하는 멤버
	struct list* next;		// 구조체 자신을 가리키는 포인터멤버
};

#define Num_ary 20

int main(void)
{
	/*
	
	// 1. 자기참조 구조체
	struct list a = { 10,0 }, b = { 20,0 }, c = { 30,0 };	// 구조체변수 초기화
	struct list* head = &a, * current;						// 헤드 포인터 초기화

	a.next = &b;		// a의 포인터 멤버(next)가 b를 가리킴
	b.next = &c;		// b의 포인터 멤버(next)가 c를 가리킴

	printf("head -> num : %d\n", head->num);				// head가 가리키는 a의 num멤버 사용
	printf("head->next->num : %d\n", head->next->num);		// head로 b의 num멤버 사용


	printf("list all : ");
	current = head;						// 최초 temp포인터(current)가 a를 가리킴


	while (current != NULL)				// 마지막 구조체변수까지 출력 후, 종료
	{
		printf("%d  ", current->num);	// temp가 가리키는 구조체변수의 num 출력
		current = current->next;		// temp가 다음 구조체변수를 가리킴
	}

	printf("\n");

	*/


	// 2. 자기참조구조체 배열 

	struct list list_ary[Num_ary] = { {10,0}, };						// 구조체 배열 초기화
	struct list* head_ary = &list_ary[0], * current_ary;
	int i = 0;

	for (int i = 0; i < Num_ary-1; i++)
	{
		list_ary[i+1].num = 10 + ((i + 1) * 10);
		list_ary[i].next = &list_ary[i + 1];
	}


	printf(" head_ary -> num : %d\n", head_ary->num);				
	printf(" head_ary->next->num : %d\n", head_ary->next->num);		


	printf("\n list all : \n\n");
	current_ary = head_ary;						// 최초 temp포인터(current)가 a를 가리킴


	while (current_ary != NULL)				// 마지막 구조체변수까지 출력 후, 종료
	{
		
		printf(" 요소번호: %2d   %5d\n",i, current_ary->num);	// temp가 가리키는 구조체변수의 num 출력
		current_ary = current_ary->next;		// temp가 다음 구조체변수를 가리킴
		++i;
	}

	printf("\n");


	return 0;
}