#include <stdio.h>
#pragma warning(disable:6031)

struct address									// �ּҷ� ����ü����
{
	char name[20];								// �̸�
	int age;									// ����
	char tel[20];								// ��ȭ��ȣ
	char addr[80];								// �ּ�
};

void print_list(struct addrss* lp);

int main(void)
{
	struct address list[5] = {
		{"ȫ�浿", 23, "111-1111", "������ ����"},
		{"�̼���", 35, "222-2222", "���� ��õ��"},
		{"�庸��", 19, "333-3333", "�ϵ� û����"},
		{"������", 15, "444-4444", "�泲 õ��"},
		{"���߱�", 45, "555-5555", "Ȳ�ص� ����"}
	};

	print_list(list);


	return 0;
}

void print_list(struct address* lp)			// �Ű����� : ����ü ������
{
	int i;									// �ݺ� Ƚ��

	for (i = 0; i < 5; i++)					// �迭 ��� �� ��ŭ �ݺ�
	{
		printf("%10s%5d%15s%20s\n",			// �迭��� ���[ (lp+i) -> ����̸� ]
			(lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
	}

}