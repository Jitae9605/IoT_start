#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// ������Ʈ
// <����� ��������>
// 5������ ����̰� �������� ����ִ� ����
// ���ڸ� �������� ������ Ȯ���� 5������ ������� �Ѹ����� ����(�ߺ�����)
// 5������ ��� ������ �¸�

// �����
// �̸�, ����, ����, Ű��� ���̵�(����)

// ����ü(�����)
typedef struct {
	char* name; // �̸�
	int age; // ����
	char* character; // ����
	int level; // Ű��� ���̵� (1 ~> 5)
} CAT;

// ������� ������ �����
int collection[5] = { 0,0,0,0,0 }; // 0 = ���� ���� �� / 1 = ���� ��

// ��ü ����� ����Ʈ
CAT cats[5];

// �Լ�����
void initCats(); //����� ���� �ʱ�ȭ
void printCat(int selected); // ���� ������� ������� �Լ�
int checkCollection();

int main_struct_project(void)
{
	srand(time(NULL));

	// �ʱ�ȭ �Լ�
	initCats();

	// �� ������ ���� �ݺ�
	while (1)
	{
		printf("�αٵα� ��� ������� ���簡 �ɱ��? \n�ƹ�Ű�� ������ Ȯ���ϼ���!");
		getchar(); // �ƹ�Ű�� �Էµɶ����� ����ϴ� �Լ�
		
		int selected = rand() % 5; // 0 ~ 4 ������ ���� ��ȯ = ����� �̱�
		printCat(selected); // ���� ������� ������ ����ϴ� �Լ�
		
		// ���� ����̴� �̾Ҵٰ� ó��
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1)
		{
			break;
		}

	}

	return 0;
}

void initCats() // ����� ���� �ʱ�ȭ �� �Է�
{
	// 1�� ������� ����
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼���";
	cats[0].level = 1;

	// 2�� ������� ����
	cats[1].name = "�Ϳ��";
	cats[1].age = 3;
	cats[1].character = "��ī�ο�";
	cats[1].level = 2;

	// 3�� ������� ����
	cats[2].name = "������";
	cats[2].age = 7;
	cats[2].character = "�� �Ḹ ��";
	cats[2].level = 3;

	// 4�� ������� ����
	cats[3].name = "�����";
	cats[3].age = 2;
	cats[3].character = "�� ����";
	cats[3].level = 4;

	// 5�� ������� ����
	cats[4].name = "�ų���";
	cats[4].age = 1;
	cats[4].character = "�׻� �������";
	cats[4].level = 5;
}

void printCat(int selected) // ���� ������� ������ ����ϴ� �Լ�
{
	printf("\n\n=== ����� �� ������� ��簡 �Ǿ����! ===\n\n");
	printf("�̸�			: %s\n", cats[selected].name);
	printf("����			: %d\n", cats[selected].age);
	printf("Ư¡(����)		: %s\n", cats[selected].character);
	printf("����			: "); // ������ �� ������ ǥ���Ѵ�
	
	// level �� ���� ������ '��'�� ���
	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "��");
	}
	printf("\n\n"); // ������ ���� �ٳѱ�
}

int checkCollection() // �̱����� ���� ���
{
	// 1. ���� ������ ����� ������ 
	// 2. ��� ��Ҵ��� ���� Ȯ��
	int collectAll = 1;

	printf("\n\n ===== ������ ����� ����̿��� ===== \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) // �ش� ����� �̺��� ����(0)
		{
			printf("%10s", " (�� �ڽ�) ");
			collectAll = 0; // ���� �Ȼ��� ����̰� �ִ�!
		}
		else // �ش� ����� ������(���� �� ����)
		{
			printf(" [%s] ", cats[i].name);
		}
	}
	printf("\n\n=========================================\n\n");

	if (collectAll) // ��� ����̸� �� ���� ���
	{
		printf("\n\n �����մϴ�! ��� ����̸� �� ��ҽ��ϴ�! ������ Ű���ּ���\n\n");
	}

	return collectAll;
}