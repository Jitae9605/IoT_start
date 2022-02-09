#include <stdio.h>
#include <windows.h>
#include <string.h>

/*

���� 13. �Ʒ��� �䱸������ Ȯ���Ͽ� ���α׷��� �ۼ��ϼ���.

1. ���������� ������ �� �ִ� ����ü�� �����մϴ�.
struct bookInfo{
    char bookTitle[];
    char bookPub[];
    int bookPrice;
};

2. ���������� ������ �� �ֵ��� ����ü �迭�� �����մϴ�.

3. ���� Ÿ��Ʋ�� ���ǻ���� �ִ� ���� 50���� �����մϴ�.

4. ���� ���� ��ü�� ����ϴ� �Լ��� �����ϼ���.
void PrintSortList(void);

5. ���� ������ ������ �� ��, ���� �̸��� ������������ �����Ͽ� ������ �ǵ��� �մϴ�.
int InsertList(bookInfo* bookPtr);

6. ���õ� �������� ���������� ������ �ǵ��� �����մϴ�.
   ���� ���� : ���� Ÿ��Ʋ, ���ǻ��, ��������
void SortByTitle(void);
void SortByPubName(void);
void SortByPrice(void);

7. ������, ���뼺, ����������, Ȯ�强�� ����ؼ� �ۼ��ϼ���.

*/

#define Max_List 50
#define Max_STR 50
#define Full 1
#define Empty 0
enum { Main_Print_TITLE = 1, Main_Registe, Main_Set_SortStandard, Main_EXIT };
enum { SORT_TITLE = 1, SORT_PUB, SORT_PRICE, Sort_EXIT };

struct bookInfo 
{
    char bookTitle[Max_STR];
    char bookPub[Max_STR];
    int bookPrice;
    int check_blank;                                // ���������� Full(= 1) ���� �����(�迭���)�̸� Empty(= 0) 
};

struct bookInfo* sort_book_list[Max_List];          // ���İ� �ּ� ����

int PrintSortMenu(void);
int Length_of_List(struct bookInfo* bookPtr);
int PrintMainMennu();
void SortByTitle(struct bookInfo* bookPtr);
void SortByPubName(struct bookInfo* bookPtr);
void SortByPrice(struct bookInfo* bookPtr);
void InsertList(struct bookInfo* bookPtr);
void initsortList(struct bookInfo* bookPtr);

// ============================== < ���� �Լ� > =====================================================

int main(void)
{
    
    struct bookInfo list[Max_List] = { //NULL,       // ���� ����
        { "��å", "�����ǻ�", 800, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 300, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 500, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 100, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 700, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 900, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 110, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 20, Full},                 // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 400, Full },                // ���� ���Ȯ���� ���� �ӽ�����
        { "��å", "�����ǻ�", 600, Full }                 // ���� ���Ȯ���� ���� �ӽ�����
    };

    int Select_Main_Menu = 0;

    initsortList(list);

    // ���α׷� ���ۺ�
    while(1)
    {
        // ���θ޴� ���
        Select_Main_Menu = PrintMainMennu();

        
        if (Select_Main_Menu == Main_Print_TITLE)                               // 1.������(�̸�����)
        {   
            SortByTitle(list);
        }

      
        else if (Select_Main_Menu == Main_Registe)                          // 2.���
        {   
            InsertList(list);
        }

        
        else if (Select_Main_Menu == Main_Set_SortStandard)                          // 3.���� ���
        {
            while (1)
            {
                // ���� �޴� ���
                int Select_Sort_Menu = PrintSortMenu();

                if (Select_Sort_Menu == SORT_TITLE)                       // 3.1 Ÿ��Ʋ ���� ����
                {
                    SortByTitle(list);
                    
                }

                else if (Select_Sort_Menu == SORT_PUB)                  // 3.2 ���ǻ� ���� ����
                {
                    SortByPubName(list);
                    
                }

                else if (Select_Sort_Menu == SORT_PRICE)                  // 3.3 ���� ���� ����
                {
                    SortByPrice(list);
                    
                }
                else if (Select_Sort_Menu == Sort_EXIT)                 // 3.4 �ڷ�
                {
                    system("cls");
                    break;
                }
                else
                {
                    printf("\n�߸��� ���Դϴ� �ٽ� �Է����ּ���.\n");
                    system("PAUSE");
                    system("cls");
                }
            }
            
        }

        // ����
        else if (Select_Main_Menu == Main_EXIT)                          // 4.  ����
        {
            break;
        }

        else
        {
            printf("�߸��� �Է��Դϴ�.");
        }
    }
   
    return 0;
}

// ============================== < �Լ� ���� > =====================================================



// ����Ʈ�� ��ϵ� �׸��� ������ ���ϴ� �Լ�
int Length_of_List(struct bookInfo *bookPtr)
{
    int Length = 0;
    for (int i = 0; i < Max_List; i++)
    {
        if ((bookPtr+i)->check_blank == Full)
        {
            Length++;
        }
    }
    return Length;
}

//  ���� ���� �� ũ�⸦ ���ؼ� �� ���� �� ����ü�� �ּҸ� �����ϴ� ����ü�����͸� ������
//  �ش� �����Ͱ� bookPtr(���ο����� list�� �޾ƿ�)�� ����Ű���Ѵ�
void initsortList(struct bookInfo* bookPtr)
{
    int Length = Length_of_List(bookPtr);
    for (int i = 0; i < Length; i++)
    {
        sort_book_list[i] = &bookPtr[i];
    }
}

// ���ĸ޴� ����Լ�
int PrintSortMenu(void)
{
    system("cls");
    int Select_Sort_Menu = 0;
    printf("\n ==================================================\n");
    printf("\t  < ���� ���� ���� ���� ���� > \n");
    printf("\n ==================================================\n");
    printf("\n 1. ���������\n\n");
    printf(" 2. ���ǻ����\n\n");
    printf(" 3. ���ݱ���\n\n");
    printf(" 4. �ڷ�\n");
    printf("\n ==================================================\n");
    printf(" ���ı����� �����ϼ���: ");
    scanf(" %d", &Select_Sort_Menu);

    return Select_Sort_Menu;
}


// ���θ޴� ����Լ�
int PrintMainMennu(void)
{
    int Select_Menu = 0;
    printf("\n ==================================================\n");
    printf("\t  < ���� ���� ���� ���α׷� > \n");
    printf(" ==================================================\n");
    printf("   1.������� ���   2.�����������   3.����   4.���� \n\n");
    printf("  ���ϴ� �޴��� �����ϼ���: ");
    scanf("%d", &Select_Menu);

    return Select_Menu;
}

// ���� ������ ������ �� ��, ���� �̸��� ������������ �����Ͽ� ������ �ǵ��� �մϴ�.
void InsertList(struct bookInfo* bookPtr)
{
    struct bookInfo temp = { NULL, };
    struct bookInfo* Temp = { NULL, };
    int Length = Length_of_List(bookPtr);

    

    // �Է¹���
    printf("\n����Ϸ��� ������ �̸��� �Է����ּ���: ");
    scanf("%s", (bookPtr + Length)->bookTitle);
    printf("\n����Ϸ��� ������ ���ǻ縦 �Է����ּ���: ");
    scanf("%s", (bookPtr + Length)->bookPub);
    printf("\n����Ϸ��� ������ ������ �Է����ּ���: ");
    scanf("%d", &(bookPtr + Length)->bookPrice);
    (bookPtr + Length)->check_blank = Full;

    initsortList(bookPtr);

    // ����
 
    for (int i = 0; i < Length-1; i++)
    {
        for (int j = 0; j < (Length-i)-1; j++)
        {
            if (strcmp(sort_book_list[j]->bookTitle, sort_book_list[j+1]->bookTitle) < 0)
            {

                /* �����ڵ� - ���� �迭���� ���� �ٲ�� -> �ڿ��������, �ӵ�����, �������ɼ� ����
                 
                strcpy(temp.bookTitle, (bookPtr + i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;

                */

                Temp = sort_book_list[j];
                sort_book_list[j] = sort_book_list[j + 1];
                sort_book_list[j + 1] = Temp;
            }

        }
    }
    Length++;
    printf("\n��� �� ������ �Ϸ�Ǿ����ϴ�. ��Ϲ�ȣ: < %d >�� �Դϴ�\n", Length);
    system("PAUSE");
    system("cls");
}


// ���õ� �������� ���������� ������ �ǵ��� �����մϴ�.
// ���� ���� : ���� Ÿ��Ʋ, ���ǻ��, ��������

void SortByTitle(struct bookInfo* bookPtr)      // ����Ÿ��Ʋ��
{
    struct bookInfo temp = { NULL, };
    struct bookInfo* Temp = { NULL, };
    int Length = Length_of_List(bookPtr);

    system("cls");
    for (int i = 0; i < Length-1; i++)
    {
        for (int j = 0; j < (Length-i)-1; j++)
        {
            if (strcmp(sort_book_list[j]->bookTitle, sort_book_list[j+1]->bookTitle) > 0)
            {   
                /* �����ڵ� - ���� �迭���� ���� �ٲ�� -> �ڿ��������, �ӵ�����, �������ɼ� ����
                
                strcpy(temp.bookTitle, (bookPtr + i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;

                */

                Temp = sort_book_list[j];
                sort_book_list[j] = sort_book_list[j + 1];
                sort_book_list[j + 1] = Temp;

            }

        }
    }
    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d��\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
    
    
}

void SortByPubName(struct bookInfo* bookPtr)    // ���ǻ��
{
    struct bookInfo temp = { NULL, };
    struct bookInfo* Temp = { NULL, };
    int Length = Length_of_List(bookPtr);

    system("cls");
    for (int i = 0; i < Length - 1 ; i++)							  
    {
        for (int j = 0; j < (Length-i)-1; j++)
        {
            if (strcmp((sort_book_list[j])->bookPub, sort_book_list[j+1]->bookPub) > 0)
            {
                /* �����ڵ� - ���� �迭���� ���� �ٲ�� -> �ڿ��������, �ӵ�����, �������ɼ� ����

                strcpy(temp.bookTitle, (bookPtr+i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;

                */

                Temp = sort_book_list[j];
                sort_book_list[j] = sort_book_list[j + 1];
                sort_book_list[j + 1] = Temp;
            }
                
        }
    }
    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d��\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
}

void SortByPrice(struct bookInfo* bookPtr)      // ���ݼ�
{
    struct bookInfo temp[Max_List] = { NULL,};
    struct bookInfo* Temp = { NULL, };
    int Length = Length_of_List(bookPtr);

    system("cls");
    for (int i = 0; i < Length-1; i++)							    	
    { 						    	
        for (int j = 0; j < (Length-i)-1; j++)
        {
            if (sort_book_list[j]->bookPrice > sort_book_list[j + 1]->bookPrice)
            {
                Temp = sort_book_list[j];
                sort_book_list[j] = sort_book_list[j + 1];
                sort_book_list[j + 1] = Temp;
            }
        }
    }

    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");



    for (int i = 0; i < Length; i++)
    {
       printf("\t%-15s \t %10s \t %5d��\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }



    printf(" ==============================================================\n");
    printf("\n");
    system("PAUSE");
    system("cls");
}


