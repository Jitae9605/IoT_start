#include <stdio.h>
#include <string.h>

void print_init_title(void);						// ���۸޴� ����ϴ� �Լ�
void print_reg_title(void);							// ��������� ����ϴ� �Լ�

int ans = 0;												// ����ȭ�� ������ �Է»��� �������
char user_name[20] = { 0 };									// ���� �α��ε� ���̵� �̸�_
int user_num = 0;											// ���� �α��ε� ���̵� ���
int jugnum_reg = 0;											// �Ǵ� �Ű�����(0 = ����ġ, 1 = ��ġ)
char car_state[255] = { 0 };								// ���� ��Ʈ���� ( 0 = ����, 1 = ��Ʈ��)
char car_name[][80] = { "��1","��2","��3","��4","��5" };		// �ʱ��ϵ� ���� ����Ʈ
int car_select = 0;											// ��Ʈ �޴����� ������ ������ ��ȣ
char user_name_check[20] = { 0 };							// ��ϵ� ȸ������ �Ǵ��ϴ� temp (���̵�)
int user_num_check = 0;										// ��ϵ� ȸ������ �Ǵ��ϴ� temp (���)
int cnt = sizeof(car_name) / sizeof(car_name[0]);			// ���� ���� ����ϴ� ����
char car_current_owner[20][20] = { 0 };						// �� ��ȣ�� ���� �� ������ �̸�
char user_reg_name[20][20] = { 0 };							// ��ϵ� ����� �̸�
int user_reg_num[20] = { -1 };								// ��ϵ� ����� �̸�
char user_name_reg[20] = { 0 };								// ����Ϸ��� ����� temp
int user_num_reg = 0;										// ����Ϸ��� ����� temp

int main_mini_project1(void)
{


	while (ans != 3)
	{
		print_init_title();
		printf("���ϴ� �޴��� ��ȣ�� �Է��� �ּ��� : ");
		scanf("%d", &ans);
		
		if (ans == 1)
		{
			// ��Ʈ
			// ���� ȸ�� �̸�, ����ó�� �Է¹޾� user_name�� user_num�� ����ִ´�.
			// ���� �ִ� ������ ����� ���� ���ϴ� ������ ��ȣ(car_num)�� �Է��϶�� �ȳ� �޼����� �Է�â�� ����
			// ��Ʈ�Ϸ� �޼����� ����ϰ� ������ ���¸� ��Ʈ������ �ٲ۴� ( �ٽ� ��ȸ�ϸ� �ش� ���� ���� )
			// ��Ʈ�Ϸ��� ������������

			printf("\n�̸��� �Է����ּ��� : ");
			scanf("%s", user_name);

			printf("\n��й�ȣ�� �Է����ּ���[0~9999]  : ");
			scanf("%d", &user_num);


			// ��й�ȣ ���� Ȯ��
			if (user_num < 0 || user_num > 9999)
			{
				while (jugnum_reg == 0)
				{
					printf("\n�ٽ� �Է����ּ��� : ");
					scanf("%s", user_name);
					if (user_num >= 0 && user_num <= 9999)
					{
						jugnum_reg++;
					}
				}

			}

			// ���� ����Ʈ ���
			else
			{
				print_reg_title();
				for (int i = 0; i < cnt;i++ )
				{
					printf("%d �� ����: %s\t���� : ", i+1, car_name[i] );
					// ���� ��Ʈ����(0), �Ұ���(1)
					if (car_state[i] == 0)
					{
						printf("��Ʈ����\n");
					}
					else 
					{
						printf("��Ʈ��\n");
					}
				}

				printf("\n��Ʈ�� ���ϴ� ������ ��ȣ�� �Է��� �ּ���(-1�� �Է��ϸ� ����˴ϴ�.) : ");
				scanf("%d", &car_select);							// ���� ����

				while (1)
				{
					if (car_state[car_select-1] == 0 && (car_select < cnt)	)							// ��Ʈ������ ���� ����
					{
						printf("\n%d �� ������ ��Ʈ�ϼ̽��ϴ�. ��ſ� ����ǽʽÿ�.\n", car_select);
						car_state[car_select - 1] = 1;								// �������� ��Ʈ������ �ٲ�
						strcpy(car_current_owner[car_select - 1], user_name);		// �ش� ������ȣ�� �ش��ϴ� ���ڿ��� �����̸��� �������
						break;
					}
					else if (car_state[car_select-1] == 1)
					{
						printf("�̹� ��Ʈ�� �����Դϴ�. �ٽ� ������ �ּ���.\n");
					}
					else if (car_select == -1)
					{
						printf("��Ʈ�޴��� �����մϴ�.\n");
						break;
					}
					else
					{
						printf("�߸��� �Է°��Դϴ�. �ٽ� �Է����ּ���\n");
					}

				}
			

			}
		}

		else if (ans == 2)
		{
			// �ݳ�(�ݳ� = �����ݳ�)
			print_reg_title();
			printf("\n�̸��� �Է����ּ��� : ");
			scanf("%s", user_name_check);

			printf("\n��й�ȣ�� �Է����ּ���[4�ڸ�]  : ");
			scanf("%d", &user_num_check);

			// �̸��� ��й�ȣ�� ���� ������ ��ȸ
			if (user_name == user_name_check && user_num == user_num_check)
			{
				print_reg_title();
				printf("%s�Բ��� ��Ʈ�Ͻ� ������ %d�� �Դϴ�.", user_name_check, car_select);
			}
			

		}

		else if (ans == 3)
		{
			// ȸ�����
			while (1)
			{
				printf("\n�̸��� �Է����ּ��� : ");
				scanf("%s", user_name_reg);

				for (int i = 0; i < 20; i++)
				{
					if (user_name_reg == user_reg_name[i])
					{
						printf("�̹� �ִ� �̸��Դϴ�. �ٽ� �Է����ּ���.");
						break;
					}

				}

				printf("\n��й�ȣ�� �Է����ּ���[4�ڸ�]  : ");
				scanf("%d", &user_num_reg);


				// ��й�ȣ ���� Ȯ��
				if (user_num_reg < 0 || user_num_reg > 9999)
				{
					while (jugnum_reg == 0)
					{
						printf("\n�ٽ� �Է����ּ��� : ");
						scanf("%s", user_num_reg);
						if (user_num_reg >= 0 && user_num_reg <= 9999)
						{
							jugnum_reg++;
						}
					}
					jugnum_reg = 0;
				}

					for(int i = 0; i < 20; i++)
					{
						// ����� ã��
						if (user_reg_num[i] == -1)			// �ʱⰪ�� -1�� ã�´�.
						{
							// ��� �Է¹��� ���̵�� ��ȣ�� ���� �� ������ �־��ش�.
							strcpy(user_reg_name[i], user_name_reg);
							user_reg_num[i] = user_num_reg;
						}
						else
						{
							printf("�� ������ �����ϴ�. ������ �ҷ��ּ���.");
							break;
						}
						
					}
					
				
				


				break;
			}
		}

		else if (ans == 4)
		{
		// ���۸޴����� 4�� �Է¹����� ���α׷� ����.
		break;

		}
		else
		{
			printf("�߸��� ���� �ԷµǾ����ϴ�. �ٽ� �Է��� �ֽʽÿ�.\n");
		}

	}

	printf("���α׷��� �����մϴ�.\n");

	return 0;
}


void print_init_title(void)
{
	// ���α׷� �ʱ�ȭ��( �޴� 0 )
	printf("\t === < ����ī �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n");
	printf("\t1)��Ʈ \t2)�ݳ� \t3)��� \t4)������ \n");
	printf("----------------------------------------------------------\n");

	// ��Ʈ = ��Ʈ
	// �ݳ� = �����ݳ�
	// ������ = q�Է½� ���α׷� ����
}

void print_reg_title(void)
{
	printf("\n\t === < ����ī �������α׷� > === \t\t\n\n");
	printf("----------------------------------------------------------\n");

}

