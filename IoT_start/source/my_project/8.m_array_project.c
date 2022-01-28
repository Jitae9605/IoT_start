#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// ������Ʈ
// ���� �ٸ� 10������ ���� (�� ������ 2����ī�� = 20���� ī��)
// ����ڷ� ���� 2���� �Է°��� ���� -> �ش� ī�� ������ -> ���� ī��� ������
//��� ������ ã���� ��������
// ������ ���� Ƚ�� �˷��ֱ�

// �Լ� ����
void initAnimalArray(); // ������ �� ����(�迭)����� (= �ʵ����)
int arrayAnimal[4][5]; // ������ ��(�迭)
void initAnimalName(); // ������ �̸�
char* strAnimal[10]; // ������ �̸� �迭(������)
void shufflAnimal(); // �������� ��ġ�� �迭�� ���´�
int getEmptyPosition(); // ������� ��ǥ�� ã�� �Լ�
int checkAnimal[4][5]; // ī�尡 ���������� ���� Ȯ��
void printAnimals();
void printQuestion();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main_m_array_project(void)
{
	srand(time(NULL));

	initAnimalArray(); // ������ġ
	initAnimalName(); //���� ����Ʈ�� �̸��� ��ȣ ���̱�

	shufflAnimal(); // �������� ��ġ�� �迭�� ���´�

	int failCount = 0; // ����Ƚ��

	while (1)
	{
		int select1 = 0; // ����ڰ� ������ ù��° ��(ī��)
		int select2 = 0; // ����ڰ� ������ �ι�° ��(ī��)

		printAnimals(); //���� ��ġ ���
		printQuestion(); // �������(����ī������ �� �������)
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) // ���� ī�� ������ ��ȿ�� �ٽ� ����
			continue;

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �Ȱ����� Ȯ��

		// ������ǥ�� (x,y) �� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// ī�尡 �̹� �������� ī������Ȯ���ϰ� ���� �������� Ȯ��
		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
				&& checkAnimal[secondSelect_x][secondSelect_y] == 0
			&&
			arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[secondSelect_x][secondSelect_y])
		{
			// ������ �� ī�尡 ��ġ�� ���
			printf("\n\n����! : %s �߰�!\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		else // ������ ī�尡 �̹� ������ ī�� or �� ī�尡 ��ġX
		{
			printf("\n\n ��!! Ʋ�Ȱų� �̹� ������ ī���Դϴ�.\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++; // �Ǽ�/�õ� Ƚ�� ī����
		}

		// ��� ������ ã�����(��� ī�� ������ ���)
		if (foundAllAnimals() == 1)
		{
			printf("\n\n �����մϴ�! ��� ã�ҽ��ϴ�\n");
			printf("�� %d ���� �Ǽ� ���� ��� ã�ҽ��ϴ�\n", failCount);
			break;
		}
	}


	return 0;
}

void initAnimalArray() // ������ �� ����(�迭)����� (= �ʵ����)
{
	for (int i = 0; i < 4; i++ )
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
}

void initAnimalName() // �迭�� ������ ����ְ� �� ������ �� ����(�̸�)���̱�
{
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	strAnimal[5] = "�⸰"; 
	strAnimal[6] = "��Ÿ";
	strAnimal[7] = "Ÿ��";
	strAnimal[8] = "ȣ����";
	strAnimal[9] = "�ڳ���";
}

void shufflAnimal() // �������� ��ġ�� �迭�� ���´�
{
	// ����������
	// ����������
	// ����������
	// ����������
	// �̷� ������� �������� ������ ���� ���� ī�带 ��ġ�ϴ� �Լ�(= ��� �ʵ忡 ��ġ)
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++) // ī��� 2�徿�̹Ƿ� �� ������ 2���� ����
		{
			int pos = getEmptyPosition(); // ������� ��ǥ�� �޴´�
			int x = conv_pos_x(pos); // ���� ��ǥ���� x���� ����x�� ����
			int y = conv_pos_y(pos); // ���� ��ǥ���� x���� ����x�� ����

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition() // ����� ã�Ƽ� ��ǥ�� ���� �Լ�
{
	// ����������   0  1  2  3  4
	// ����������   5  6  7  8  9
	// ����������  10 11 12 13 14  
	// ����������  15 16 17 18 19  
	while (1)
	{
		int randPos = rand() % 20; // 0~ 19 ������ ���� ��ȯ(�̰� ��ǥ�� �ٱž��Ѵ�)
		// ex) 19 = (3,4) �� ���� ��ǥ��ȯ�� �ʿ�
		int x = conv_pos_x(randPos); // ���� ��ǥ���� x���� ����x�� ����
		int y = conv_pos_y(randPos); // ���� ��ǥ���� y���� ����y�� ���� 

		if (arrayAnimal[x][y] == -1) // ���ڸ�(= -1)�ϰ�� �װ��� ��ǥ�� ��ȯ
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x) // ���� ��ǥ���� x���� ����x�� ����
{
	// ����������   0  1  2  3  4   (������ 5) ->  0 0 0 0 0 
	// ����������   5  6  7  8  9   (������ 5) ->  1 1 1 1 1
	// ����������  10 11 12 13 14   (������ 5) ->  2 2 2 2 2
	// ����������  15 16 17 18 19   (������ 5) ->  3 3 3 3 3
	// int ���̹Ƿ� 0 ~ 19�� 5�� ���������� x ���� ���´�
	return x / 5;
}

int conv_pos_y(int y) // ���� ��ǥ���� y���� ����y�� ����
{
	// ����������   0  1  2  3  4   (������ 5�� ������) ->  0 1 2 3 4 
	// ����������   5  6  7  8  9   (������ 5�� ������) ->  0 1 2 3 4
	// ����������  10 11 12 13 14   (������ 5�� ������) ->  0 1 2 3 4
	// ����������  15 16 17 18 19   (������ 5�� ������) ->  0 1 2 3 4
	// int ���̹Ƿ� 0 ~ 19�� 5�� ���� �������� y���̴�
	return y % 5;
}

void printAnimals() //���� ��ġ ���
{
	// ����������   0  1  2  3  4
	// ����������   5  6  7  8  9
	// ����������  10 11 12 13 14  
	// ����������  15 16 17 18 19 

	printf("\n============= ���� ���赿���� ���� ������� ===============\n\n"); // ���м�
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]); // %8s = 8ĭ�� ����(= ������ �̸��� �뷮(8byte))
		}
		printf("\n"); // �������� ���� �ݺ������� �ٳѱ�
	 }
	printf("\n===================================\n\n"); // ���м�
}

void printQuestion() // �������(����ī������ �� �������)
{
	printf("\n\n(����)\n");
	int seq = 0; // seq = ��ǥ�� �ƴ� ���� ī�� ������ ��ġ (0 ~ 19)

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// ī�带 ����� �����̸� '�����̸�'(�ո�)
			if (checkAnimal[i][j] != 0)  // ī�尡 ���������� ���� Ȯ��
			{
				// �̹� ���������� �����̸��� ���
				printf("%8s", strAnimal[arrayAnimal[i][j]]); // 8s�� �ٸ����� ���� �������
			}

			// ���������� ī����ġ����(�޸�)
			else
			{
				// �ȵ��������� �������
				printf("%8d", seq); // ���⿡ seq++ �ϸ� ��ȣ���� �ٲ�
			}
			seq++;  // ī���ǿ� ���ڷ� ��� ������� �˼��ְ� ��ȣ�Ἥ ��ȣ�� ���
		}
		printf("\n");
	}
}

int foundAllAnimals() // ��� ������ ã���� ��� ����(=1)�� ��ȯ�ϴ� �Լ�
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0) // 
			{
				return 0;
			}
		}
	}
	return 1;
}