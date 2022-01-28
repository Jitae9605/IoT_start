#include <stdio.h>
#include <windows.h>

void Print_Mainmenu_1(void);

int main(void)
{
	int Select_diff_main_menu = 0;

	while(1)
	{
		Print_Mainmenu_1();
		printf("원하는 메뉴의 번호를 입력하세요 : ");
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
	printf("\t\t 틀린 그림 찾기 \t\t");
	printf("\n===============================================\n");
	printf("\n\t\t 1. 도전\n\n\t\t 2. 초기화\n\n\t\t 3. 랭킹확인\n\n\t\t 4. 뒤로\n\n");
	printf("\n===============================================\n");
}