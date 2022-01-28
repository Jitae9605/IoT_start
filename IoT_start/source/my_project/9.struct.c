#include <stdio.h>

// ����ü ����
struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ������ü ����(friendGame = ������)
};

// �Ź� struct���� �������� ���� ��� 2��°
// ù ���𿡼� ���� typedef �ڱ�
typedef struct GameInformation { // �� ��쿡�� �̸��� GameInformation ��� ��
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ������ü ����(friendGame = ������)
} GAME_INFO; // = typedef struct GameInformation { ~ } GAME_INFO;
			 //  �� : 'typedef ���(struct ~ {~} ����

int main_struct(void)
{


	// [������� ����]
	// �̸� : ��������
	// �߸ų⵵ : 2017 ��
	// ���� : 50��
	// ���ۻ� : ����ȸ��

	//char* name = "��������";
	//int year = 2017;
	//int price = 50;
	//char* company = "����ȸ��";

	// [�Ǵٸ� ������� ����]
	// �̸� : �ʵ�����
	// �߸ų⵵ : 2017 ��
	// ���� : 100��
	// ���ۻ� : �ʵ�ȸ��

	//char* name2 = "�ʵ�����";
	//int year2 = 2017;
	//int price2 = 100;
	//char* company2 = "�ʵ�ȸ��";

	// �̷��� ���� 100���� �Ѿ�ٸ� �˾ƺ��� ����� ������ ����
	// �̸������ϱ� ���� '����ü'�� ����Ѵ�

	printf("----------------------------------\n");

	// ����ü ���(�ܼ����)
	struct GameInfo gameinfo1;
	// struct GameInfo gameinfo2; // �̷��� 2��°�� �ѹ��� ���� �ؼ� ����
	gameinfo1.name = "��������";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "����ȸ��";
	
	printf("-- ���� ��� ����(����ü �ܼ����) --\n");
	printf("   ���Ӹ�     : %s\n", gameinfo1.name);
	printf("   �߸ų⵵   : %d\n", gameinfo1.year);
	printf("   ����       : %d\n", gameinfo1.price);
	printf("   ���ۻ�     : %s\n\n", gameinfo1.company);

	printf("----------------------------------\n");

	// ����ü�� �迭ó����� (�迭)
	struct GameInfo gameinfo2 = { "�ʵ�����", 2017, 100, "�ʵ�ȸ��" };
	printf("-- �Ǵٸ� ���� ��� ����(����ü ���� �迭���) --\n");
	printf("   ���Ӹ�     : %s\n", gameinfo2.name);
	printf("   �߸ų⵵   : %d\n", gameinfo2.year);
	printf("   ����       : %d\n", gameinfo2.price);
	printf("   ���ۻ�     : %s\n\n", gameinfo2.company);


	printf("----------------------------------\n");


	// ����ü �迭(���߻��)
	struct GameInfo gameArray[2] = {
		{"��������", 2017, 50, "����ȸ��"},
		{"�ʵ�����", 2017, 100, "�ʵ�ȸ��"}
	};

	printf("-- ���� ��� ����(����ü ���߹迭���) --\n");
	printf("   ���Ӹ�     : %s\n", gameArray[0].name);
	printf("   �߸ų⵵   : %d\n", gameArray[0].year);
	printf("   ����       : %d\n", gameArray[0].price);
	printf("   ���ۻ�     : %s\n\n", gameArray[0].company);

	printf("-- �Ǵٸ� ���� ��� ���� --\n");
	printf("   ���Ӹ�     : %s\n", gameArray[1].name);
	printf("   �߸ų⵵   : %d\n", gameArray[1].year);
	printf("   ����       : %d\n", gameArray[1].price);
	printf("   ���ۻ�     : %s\n\n", gameArray[1].company);

	printf("----------------------------------\n\n");

	// ����ü ������
	struct GameInfo* gamePtr; // ������(gamePtr�̶�� �����͸� ����)
	gamePtr = &gameinfo1; // ������ gamePtr�� gameinfo1�� �ּҿ� ���� �ٷΰ�����
	printf("-- �������� ���� ��� ����(����ü ������ ���� - 1) --\n\n");

	// gamePtr = gamePtr�̶�� �ٷΰ��Ⱑ ����Ű�� �ּ�
	// *gamePtr = gamePtr�̶�� �ٷΰ��Ⱑ ����Ű�� ����(����)������ ��(����Ŭ��)
	printf("   ���Ӹ�     : %s\n", (*gamePtr).name); // ��ȣ ��ġ�� (*gamePtr.name)���� �ν�
	printf("   �߸ų⵵   : %d\n", (*gamePtr).year);
	printf("   ����       : %d\n", (*gamePtr).price);
	printf("   ���ۻ�     : %s\n\n", (*gamePtr).company);

	// �Ǵ� 

	// '->' �� ���
	// 'gamePtr->name' = gamePtr�� ����Ű�� �� ������ name�׸��� ���̶�� �ǹ�
	printf("-- �������� ���� ��� ����(����ü ������ ���� - 1) --\n");
	printf("   ���Ӹ�     : %s\n", gamePtr->name); // -> = ������ ������ name�� �ش��ϴ� �� ȣ��
	printf("   �߸ų⵵   : %d\n", gamePtr->year);
	printf("   ����       : %d\n", gamePtr->price);
	printf("   ���ۻ�     : %s\n\n", gamePtr->company);

	printf("----------------------------------\n");

	// ������ü ���� �Ұ� (����ü ���� �Ǵٸ� ����ü�� ����� ���)
	gameinfo1.friendGame = &gameinfo2;
	printf("\n\n-- ������ü�� ���� ��� ����(����ü ������ ���� - 1) --\n");
	printf("   ���Ӹ�     : %s\n", gameinfo1.friendGame->name); // -> = ������ ������ name�� �ش��ϴ� �� ȣ��
	printf("   �߸ų⵵   : %d\n", gameinfo1.friendGame->year);
	printf("   ����       : %d\n", gameinfo1.friendGame->price);
	printf("   ���ۻ�     : %s\n\n", gameinfo1.friendGame->company);

	printf("----------------------------------\n");

	// �Ź� struct���� �������� ������ ���
	
	// 1. typedef (= �ڷ����� �������� �ϴ� �Լ�)
	int i = 1;
	typedef int ����; // 'int'��� �ڷ��� ��� '����'��� ���ڷ� int�ڷ��� ǥ������
	typedef float �Ǽ�;
	���� �������� = 3; //  = int i = 3;
	�Ǽ� �Ǽ����� = 3.23f; //  = float f = 3.23f;
	printf("\n\n�������� : %d, �Ǽ����� : %.2f\n\n", ��������, �Ǽ�����);

	// ����ü�� ����
	typedef struct GameInfo ��������; // 'struct GameInfo' = '��������'
	�������� game1; // = struct GameInfo game1;
	game1.name = "�ѱ� ����";
	game1.year = 2015;

	// 2. struct ���𿡼� ���� typedef�� ���� ������ �޾��ش�
	// 'struct GameInformation' �� 'GAME_INFO' �� ����
	
	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2015;

	// ��, �����ϻ� �̸��̳� ����ü�� �״�� �־ ������ �͵� ��밡��
	// �ƿ� struct�� �ְ� �̸� ���� �����ؼ� ���� �־ ����� �����ϴ�.
	struct GameInformation game3;
	game3.name = "�ѱ� ����3";
	game3.year = 2016;



	return 0;
}