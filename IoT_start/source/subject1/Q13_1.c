#include <stdio.h>
#include <windows.h>
#include <string.h>

/*

문제 13. 아래의 요구사항을 확인하여 프로그램을 작성하세요.

1. 도서정보를 저장할 수 있는 구조체를 구현합니다.
struct bookInfo{
    char bookTitle[];
    char bookPub[];
    int bookPrice;
};

2. 도서정보를 관리할 수 있도록 구조체 배열을 구현합니다.

3. 도서 타이틀과 출판사명은 최대 길이 50으로 제한합니다.

4. 도서 정보 전체를 출력하는 함수를 구현하세요.
void PrintSortList(void);

5. 도서 정보가 저장이 될 때, 도서 이름의 오름차순으로 정렬하여 저장이 되도록 합니다.
int InsertList(bookInfo* bookPtr);

6. 선택된 기준으로 도서정보가 정렬이 되도록 구현합니다.
   정렬 기준 : 도서 타이틀, 출판사면, 도서가격
void SortByTitle(void);
void SortByPubName(void);
void SortByPrice(void);

7. 가독성, 재사용성, 유지보수성, 확장성을 고려해서 작성하세요.

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

// ============================== < 매인 함수 > =====================================================

int main(void)
{
    // 정렬 기능확인을 위한 임시정보
    struct bookInfo list[Max_List] = {
        { "다책", "가출판사", 800,1 },
        { "라책", "자출판사", 300,1 },
        { "마책", "바출판사", 500,1 },
        { "자책", "사출판사", 100,1 },
        { "아책", "나출판사", 700,1 },
        { "나책", "아출판사", 900,1 },
        { "가책", "마출판사", 110,1 },
        { "바책", "차출판사", 20,1 },
        { "사책", "라출판사", 400,1 },
        { "차책", "다출판사", 600,1 }
    };

    int Select_Main_Menu = 0;

    // 프로그램 동작부
    while(1)
    {
        // 매인메뉴 출력
        Select_Main_Menu = PrintMainMennu();

        
        if (Select_Main_Menu == 1)                               // 1.목록출력
        {   
            PrintSortList(list);
            system("PAUSE");
            system("cls");
        }

      
        else if (Select_Main_Menu == 2)                          // 2.등록
        {   
            InsertList(list);
        }

        
        else if (Select_Main_Menu == 3)                          // 3.정렬 출력
        {
            while (1)
            {
                // 정렬 메뉴 출력
                int Select_Sort_Menu = PrintSortMenu();

                if (Select_Sort_Menu == 1)                       // 3.1 타이틀 기준 정렬
                {
                    SortByTitle(list);
                    break;
                }

                else if (Select_Sort_Menu == 2)                  // 3.2 출판사 기준 정렬
                {
                    SortByPubName(list);
                    break;
                }

                else if (Select_Sort_Menu == 3)                  // 3.3 가격 기준 정렬
                {
                    SortByPrice(list);
                    break;
                }
                else
                {
                    printf("\n잘못된 값입니다 다시 입력해주세요.\n");
                    system("PAUSE");
                    system("cls");
                }
            }
            
        }

        // 종료
        else if (Select_Main_Menu == 4)                          // 4.  종료
        {
            break;
        }

        else
        {
            printf("잘못된 입력입니다.");
        }
    }
   
    return 0;
}

// ============================== < 함수 정의 > =====================================================


// 리스트내 등록된 항목의 갯수를 구하는 함수
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

// 정렬메뉴 출력함수
int PrintSortMenu(void)
{
    int Select_Sort_Menu = 0;
    printf("\n ==================================================\n");
    printf("\n1. 도서명기준\n\n");
    printf("2. 출판사기준\n\n");
    printf("3. 가격기준\n\n");
    printf("\n ==================================================\n");
    printf("정렬기준을 선택하세요: ");
    scanf(" %d", &Select_Sort_Menu);

    return Select_Sort_Menu;
}


// 매인메뉴 출력함수
int PrintMainMennu(void)
{
    int Select_Menu = 0;
    printf("\n ==================================================\n");
    printf("\t  < 도서 정보 관리 프로그램 > \n");
    printf(" ==================================================\n");
    printf("   1.도서목록 출력   2.도서정보등록   3.정렬   4.종료 \n\n");
    printf("  원하는 메뉴를 선택하세요: ");
    scanf("%d", &Select_Menu);

    return Select_Menu;
}

// 도서 정보 전체를 출력하는 함수를 구현하세요. 
void PrintSortList(struct bookInfo* bookPtr)
{
    int Length = Length_of_List(bookPtr);
    printf("\n ==============================================================\n");
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");
    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d원\n", (bookPtr+i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }
    printf(" ==============================================================\n");
    printf("\n");

}


// 도서 정보가 저장이 될 때, 도서 이름의 오름차순으로 정렬하여 저장이 되도록 합니다.
int InsertList(struct bookInfo* bookPtr)
{
    struct bookInfo temp = { NULL, };
    char temp_bookTitle[50] = "0";
    char temp_bookPub[50] = "0";
    int temp_bookPrice = 0;
    int Length = Length_of_List(bookPtr);

    

    // 입력받음
    printf("\n등록하려는 도서의 이름을 입력해주세요: ");
    scanf("%s", (bookPtr + Length)->bookTitle);
    printf("\n등록하려는 도서의 출판사를 입력해주세요: ");
    scanf("%s", (bookPtr + Length)->bookPub);
    printf("\n등록하려는 도서의 가격을 입력해주세요: ");
    scanf("%d", &temp_bookPrice);
    (bookPtr + Length)->bookPrice = temp_bookPrice;
    (bookPtr + Length)->check_blank = 1;


    // 정렬
 
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


// 선택된 기준으로 도서정보가 정렬이 되도록 구현합니다.
// 정렬 기준 : 도서 타이틀, 출판사면, 도서가격
void SortByTitle(struct bookInfo* bookPtr)      // 도서타이틀순
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
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d원\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
    
    
}

void SortByPubName(struct bookInfo* bookPtr)    // 출판사순
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
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d원\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
}

void SortByPrice(struct bookInfo* bookPtr)      // 가격순
{
    struct bookInfo temp[Max_List] = { NULL,};
    int Length = Length_of_List(bookPtr);
    int Rank[Max_List] = { 0 };


    for (int i = 0; i < Length; i++)							    	// 등수 구하기
    {
        Rank[i] = Length;										    	// 모든 랭크를 n+1로 한다(같거나를 이용하므로 ( ' >= ' 사용 안하면 똑같은 점수를 가진사람들이 모두 불이익을 본다 ))
        for (int j = 0; j < Length; j++)
        {
            if ((bookPtr + i)->bookPrice >= (bookPtr + j)->bookPrice)	// 하나하나를 다른 모든 값과 비교하여 같거나 자신이 크면 랭크를 하나씩 낮춘다
                Rank[i]--;
        }
    }

    printf("\n ==============================================================\n");
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
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
       printf("\t%-15s \t %10s \t %5d원\n", (bookPtr + i)->bookTitle, (bookPtr + i)->bookPub, (bookPtr + i)->bookPrice);
    }



    printf(" ==============================================================\n");
    printf("\n");
    system("PAUSE");
    system("cls");
}


