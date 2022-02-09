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

struct bookInfo 
{
    char bookTitle[50];
    char bookPub[50];
    int bookPrice;
    int check_blank;
};

int PrintSortMenu(void);
int Length_of_List(struct bookInfo* bookPtr);
int PrintMainMennu();
void PrintSortList(struct bookInfo *bookPtr);
void SortByTitle(struct bookInfo* bookPtr);
void SortByPubName(struct bookInfo* bookPtr);
void SortByPrice(struct bookInfo* bookPtr);
int InsertList(struct bookInfo* bookPtr);

// ============================== < ���� �Լ� > =====================================================

int main(void)
{
    // ���� ���Ȯ���� ���� �ӽ�����
    struct bookInfo list[Max_List] = {
        { "��å", "�����ǻ�", 800,1 },
        { "��å", "�����ǻ�", 300,1 },
        { "��å", "�����ǻ�", 500,1 },
        { "��å", "�����ǻ�", 100,1 },
        { "��å", "�����ǻ�", 700,1 },
        { "��å", "�����ǻ�", 900,1 },
        { "��å", "�����ǻ�", 110,1 },
        { "��å", "�����ǻ�", 20,1 },
        { "��å", "�����ǻ�", 400,1 },
        { "��å", "�����ǻ�", 600,1 }
    };

    int Select_Main_Menu = 0;

    // ���α׷� ���ۺ�
    while(1)
    {
        // ���θ޴� ���
        Select_Main_Menu = PrintMainMennu();

        
        if (Select_Main_Menu == 1)                               // 1.������
        {   
            PrintSortList(list);
            system("PAUSE");
            system("cls");
        }

      
        else if (Select_Main_Menu == 2)                          // 2.���
        {   
            InsertList(list);
        }

        
        else if (Select_Main_Menu == 3)                          // 3.���� ���
        {
            while (1)
            {
                // ���� �޴� ���
                int Select_Sort_Menu = PrintSortMenu();

                if (Select_Sort_Menu == 1)                       // 3.1 Ÿ��Ʋ ���� ����
                {
                    SortByTitle(list);
                    break;
                }

                else if (Select_Sort_Menu == 2)                  // 3.2 ���ǻ� ���� ����
                {
                    SortByPubName(list);
                    break;
                }

                else if (Select_Sort_Menu == 3)                  // 3.3 ���� ���� ����
                {
                    SortByPrice(list);
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
        else if (Select_Main_Menu == 4)                          // 4.  ����
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
        if ((bookPtr+i)->check_blank == 1)
        {
            Length++;
        }
    }
    return Length;
}

// ���ĸ޴� ����Լ�
int PrintSortMenu(void)
{
    int Select_Sort_Menu = 0;
    printf("\n ==================================================\n");
    printf("\n1. ���������\n\n");
    printf("2. ���ǻ����\n\n");
    printf("3. ���ݱ���\n\n");
    printf("\n ==================================================\n");
    printf("���ı����� �����ϼ���: ");
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

// ���� ���� ��ü�� ����ϴ� �Լ��� �����ϼ���. 
void PrintSortList(struct bookInfo* bookPtr)
{
    int Length = Length_of_List(bookPtr);
    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");
    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d��\n", (bookPtr+i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }
    printf(" ==============================================================\n");
    printf("\n");

}


// ���� ������ ������ �� ��, ���� �̸��� ������������ �����Ͽ� ������ �ǵ��� �մϴ�.
int InsertList(struct bookInfo* bookPtr)
{
    struct bookInfo temp = { NULL, };
    char temp_bookTitle[50] = "0";
    char temp_bookPub[50] = "0";
    int temp_bookPrice = 0;
    int Length = Length_of_List(bookPtr);

    

    // �Է¹���
    printf("\n����Ϸ��� ������ �̸��� �Է����ּ���: ");
    scanf("%s", (bookPtr + Length)->bookTitle);
    printf("\n����Ϸ��� ������ ���ǻ縦 �Է����ּ���: ");
    scanf("%s", (bookPtr + Length)->bookPub);
    printf("\n����Ϸ��� ������ ������ �Է����ּ���: ");
    scanf("%d", &temp_bookPrice);
    (bookPtr + Length)->bookPrice = temp_bookPrice;
    (bookPtr + Length)->check_blank = 1;


    // ����
 
    for (int i = 0; i < Length+1; i++)
    {
        for (int j = 0; j < Length+1; j++)
        {
            if (strcmp((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle) < 0)
            {
                strcpy(temp.bookTitle, (bookPtr + i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;
            }

        }
    }
   

}


// ���õ� �������� ���������� ������ �ǵ��� �����մϴ�.
// ���� ���� : ���� Ÿ��Ʋ, ���ǻ��, ��������
void SortByTitle(struct bookInfo* bookPtr)      // ����Ÿ��Ʋ��
{
    struct bookInfo temp = { NULL, };
    int Length = Length_of_List(bookPtr);


    for (int i = 0; i < Length; i++)
    {
        for (int j = 0; j < Length; j++)
        {
            if (strcmp((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle) < 0)
            {
                strcpy(temp.bookTitle, (bookPtr + i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;
            }

        }
    }
    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d��\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
    
    
}

void SortByPubName(struct bookInfo* bookPtr)    // ���ǻ��
{
    struct bookInfo temp = { NULL, };
    int Length = Length_of_List(bookPtr);


    for (int i = 0; i < Length; i++)							  
    {
        for (int j = 0; j < Length; j++)
        {
            if (strcmp((bookPtr + i)->bookPub, (bookPtr + j)->bookPub) < 0)	
            {
                strcpy(temp.bookTitle, (bookPtr+i)->bookTitle);
                strcpy(temp.bookPub, (bookPtr + i)->bookPub);
                temp.bookPrice = (bookPtr + i)->bookPrice;

                strcpy((bookPtr + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((bookPtr + i)->bookPub, (bookPtr + j)->bookPub);
                (bookPtr + i)->bookPrice = (bookPtr + j)->bookPrice;

                strcpy((bookPtr + j)->bookTitle, temp.bookTitle);
                strcpy((bookPtr + j)->bookPub, temp.bookPub);
                (bookPtr + j)->bookPrice = temp.bookPrice;
            }
                
        }
    }
    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d��\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
}

void SortByPrice(struct bookInfo* bookPtr)      // ���ݼ�
{
    struct bookInfo temp[Max_List] = { NULL,};
    int Length = Length_of_List(bookPtr);
    int Rank[Max_List] = { 0 };


    for (int i = 0; i < Length; i++)							    	// ��� ���ϱ�
    {
        Rank[i] = Length;										    	// ��� ��ũ�� n+1�� �Ѵ�(���ų��� �̿��ϹǷ� ( ' >= ' ��� ���ϸ� �Ȱ��� ������ ����������� ��� �������� ���� ))
        for (int j = 0; j < Length; j++)
        {
            if ((bookPtr + i)->bookPrice >= (bookPtr + j)->bookPrice)	// �ϳ��ϳ��� �ٸ� ��� ���� ���Ͽ� ���ų� �ڽ��� ũ�� ��ũ�� �ϳ��� �����
                Rank[i]--;
        }
    }

    printf("\n ==============================================================\n");
    printf("\t������ \t\t\t ���ǻ� \t ����(��) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        for (int j = 0; j < Length; j++)
        {

            if (Rank[j] == i)
            {
                strcpy((temp + i)->bookTitle, (bookPtr + j)->bookTitle);
                strcpy((temp + i)->bookPub, (bookPtr + j)->bookPub);
                (temp + i)->bookPrice = (bookPtr + j)->bookPrice;
               
            }
        }
    }

    for (int i = 0; i < Length; i++)
    {
       strcpy((bookPtr + i)->bookTitle, (temp + i)->bookTitle);
       strcpy((bookPtr + i)->bookPub, (temp + i)->bookPub);
       (bookPtr + i)->bookPrice = (temp + i)->bookPrice;
       printf("\t%-15s \t %10s \t %5d��\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }



    printf(" ==============================================================\n");
    printf("\n");
    system("PAUSE");
    system("cls");
}


