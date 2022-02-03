#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)

#define id_limit 12
#define pw_limit 4
#define game 4
#define max_player 10

int loginCheck = 1; // �α��� ����=1, ���� �Ǵ� �α׾ƿ�=0

struct score {   // [���� ���� ����ü]
	int upDown;  // ���ٿ� ����
	int cal;     // �ϻ� ����
	int BW;      // û���� ����
	int spot;    // Ʋ���׸� ã��
	int total;   // ���� ����
};

struct player {              // [�÷��̾� ���� ���� ����ü]
	struct score sc;		 // score ����ü�� ����� ���
	char id[id_limit + 1];   // ���̵�
	char pw[pw_limit + 1];   // ��й�ȣ
	int rank;                // ��ŷ
	int join;                // ��� ����
};

int start();
void join(struct player allPlayerList[]); // �÷��̾� ��� �Լ�
struct player logIn(struct player p, struct player allPlayerList[]);
int main_menu();
int rank();

int main123() {
	int start_choice = 0, menu_choice = 0, rank_choice = 0;
	struct player p; // �÷��̾� ����ü ���� ����
	struct player allPlayerList[max_player]; // ��� �÷��̾� ���� ������ ����ü �迭 ����
	
	for (int i = 0; i < max_player; i++) {
		for (int j = 0; j <= id_limit; j++) {
			allPlayerList[i].id[j] = '\0';
		}
	} //�÷��̾� ���̵� �迭 null�� �ʱ�ȭ

	while (1) {
		start_choice = start(); // ����ȭ�� ���

		if (start_choice == 1) { // �α��� �������� ��
			p = logIn(p, allPlayerList); // �α��� �Լ� ȣ��

			if (loginCheck == 0)continue; // ��ϵ� ���̵� ���� �� ����ȭ������ ���ư���
			else { // �α��� ����, ����ȭ������
				menu_choice = main_menu();

				if (menu_choice == 1) {       // ���ٿ� ���� ����
					//���ٿ� ���� ȣ�� �ۼ��ϱ�
				}
				else if (menu_choice == 2) {  // �ϻ� ���� ����
					//�ϻ� ���� ȣ�� �ۼ��ϱ�
				}
				else if (menu_choice == 3) {  // û���� ���� ����
					//û���� ���� ȣ�� �ۼ��ϱ�
				}
				else if (menu_choice == 4) {  // Ʋ���׸�ã�� ���� ����
					//Ʋ���׸�ã�� ���� ȣ�� �ۼ��ϱ�
				}
				else if (menu_choice == 5) {  // ��ŷ ��ȸ
					rank_choice = rank();

					if (rank_choice == 1) {   // ���Ӻ� ��ŷ ��ȸ

					}
					else if (rank_choice == 2) {  // ���� ��ŷ ��ȸ
					
					}
					else if (rank_choice == 3) {  // �ٽ� ����ȭ������

					}
					else { // �̻��� �� ������ ��
					
					}
				}
				else if (menu_choice == 6) {  // �α׾ƿ�
					printf("�α׾ƿ��Ǿ����ϴ�.\n");
					loginCheck = 0;
				}
				else if (menu_choice == 7) {  // ���α׷� ����
					printf("���α׷��� �����մϴ�.\n");
					break;
				}
				else { // �߸��� ����
					printf("�߸��� �Է��Դϴ�.\n");
				}
			}
		}

		else if (start_choice == 2) { // �÷��̾� ��� �������� ��
			join(allPlayerList);
		}

		else if (start_choice == 3) { // ���� �������� ��
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		else printf("�߸��� �Է��Դϴ�.\n"); // 1,2,3 �ƴ� �� �Է����� ��
	}

	return 0;
}

int start() {
	int choice;

	printf("\n[�̴ϰ���õ��]\n\n"); 
	printf("(1) �α���\n");
	printf("(2) �÷��̾� ���\n");
	printf("(3) ����\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

void join(struct player allPlayerList[]) {
	int id_check = -1;
	char id_temp[id_limit + 1] = { NULL };

	printf("[�÷��̾� ���]\n\n");
	while (1) {
		printf("����� ���̵� �Է��ϼ���(�ִ� ����12����, �ѱ�6����)\n");
		printf("�Է� : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // �����ϴ� ���̵����� ��
			if (id_check == 0) { // �����ϴ� ���̵��� ��
				printf("�̹� �����ϴ� ���̵��Դϴ�.\n");
				break;
			}
		}

		if (id_check != 0) { // ���� ������ ���̵��� ��
			for (int i = 0; i < max_player; i++) {
				if (allPlayerList[i].id != NULL) { // ���ڸ� ã�Ƽ�
					strcpy(allPlayerList[i].id, id_temp); // ���ڸ��� ���̵� ����
					printf("��� ������ ���̵��Դϴ�.\n");
					printf("��й�ȣ�� �Է��ϼ���(4�ڸ� ����)\n");
					printf("�Է� : ");
					scanf("%s", allPlayerList[i].pw); // ��й�ȣ ����
					break;
				}
			}
			printf("����� �Ϸ�Ǿ����ϴ�.\n");
			break;
		}
	}
}

struct player logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL };
	char pw_temp[pw_limit + 1] = { NULL };
	int id_check = -1, pw_check = -1;

	printf("[�α���]\n\n");
	while (1) {
		printf("���̵� : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // �����ϴ� ���̵����� ��
			if (id_check == 0) { // �����ϴ� ���̵��� ��
				printf("��й�ȣ :");
				scanf("%s", pw_temp);
				pw_check = strcmp(allPlayerList[i].pw, pw_temp); // ��� �´��� Ȯ��
			}
		}

		if (id_check != 0) { // �����ϴ� ���̵� �ƴ� ��,
			printf("�������� �ʴ� ���̵��Դϴ�.\n");
			loginCheck = 0;
			break;
		}

		if (id_check == 0 && pw_check == 0) { // �α��� ����
			printf("�α��εǾ����ϴ�.\n");
			loginCheck = 1;
			strcpy(p.id, id_temp);
			strcpy(p.pw, pw_temp); // ����ü ������ �Ƶ�, ��� ��� ����
			//  ���θ޴� ȭ������ �����ֱ�
			break;
		}
		else if (id_check == 0 && pw_check != 0) { // ���̵� �ִµ� ��� Ʋ�� ��
			printf("�߸��� ��й�ȣ �Դϴ�.\n");
		}
	}

	return p;
}

int main_menu() {
	int choice = 0;

	printf("[���� �޴�]\n\n");
	printf("(1) ���ٿ�\n");
	printf("(2) �ϻ�\n");
	printf("(3) û����\n");
	printf("(4) Ʋ���׸�ã��\n");
	printf("(5) ��ŷ ��ȸ\n");
	printf("(6) �α׾ƿ�\n");
	printf("(7) ���α׷� ����\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}

int rank() {
	int choice = 0;

	printf("[��ŷ ��ȸ]\n\n");
	printf("(1) ���Ӻ� ��ŷ ��ȸ\n");
	printf("(2) ���� ��ŷ ��ȸ\n");
	printf("(3) �ڷΰ���\n");
	printf("�Է� : ");
	scanf("%d", &choice);

	return choice;
}