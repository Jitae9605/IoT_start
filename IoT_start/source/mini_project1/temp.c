#include <stdio.h>
#include <windows.h>

void Print_Mainmenu_1(void);

int main(void)
{
	int Select_diff_main_menu = 0;

	while(1)
	{
		Print_Mainmenu_1();
		printf("���ϴ� �޴��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &Select_diff_main_menu);

		if (Select_diff_main_menu == 1)
		{

		}
		else if (Select_diff_main_menu == 2)
		{

		}
		else if (Select_diff_main_menu == 3)
		{

		}
		else if (Select_diff_main_menu == 4)
		{
			system("cls");
			break;
		}
	}

}

void Print_Mainmenu_1(void)
{
	printf("\n===============================================\n");
	printf("\t\t Ʋ�� �׸� ã�� \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. ����\n\n\t\t 2. �ʱ�ȭ\n\n\t\t 3. ��ŷȮ��\n\n\t\t 4. �ڷ�\n\n");
	printf("\n===============================================\n");
}