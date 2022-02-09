#include <stdio.h>
#pragma warning(disable:6031)

struct list					// �ڱ���������ü
{
	int num;				// �����͸� �����ϴ� ���
	struct list* next;		// ����ü �ڽ��� ����Ű�� �����͸��
};

#define Num_ary 20

int main(void)
{
	// 1. �ڱ����� ����ü
	struct list a = { 10,0 }, b = { 20,0 }, c = { 30,0 };	// ����ü���� �ʱ�ȭ
	struct list* head = &a, * current;						// ��� ������ �ʱ�ȭ

	a.next = &b;		// a�� ������ ���(next)�� b�� ����Ŵ
	b.next = &c;		// b�� ������ ���(next)�� c�� ����Ŵ

	printf("head -> num : %d\n", head->num);				// head�� ����Ű�� a�� num��� ���
	printf("head->next->num : %d\n", head->next->num);		// head�� b�� num��� ���


	printf("list all : ");
	current = head;						// ���� temp������(current)�� a�� ����Ŵ


	while (current != NULL)				// ������ ����ü�������� ��� ��, ����
	{
		printf("%d  ", current->num);	// temp�� ����Ű�� ����ü������ num ���
		current = current->next;		// temp�� ���� ����ü������ ����Ŵ
	}

	printf("\n");


	// 2. �ڱ���������ü �迭 

	struct list list_ary[Num_ary] = { {10,0}, };						// ����ü �迭 �ʱ�ȭ
	struct list* head_ary = &list_ary[0], * current_ary;

	for (int i = 0; i < Num_ary-1; i++)
	{
		list_ary[i].next = &list_ary[i + 1];
	}
	current_ary = head_ary;



	return 0;
}