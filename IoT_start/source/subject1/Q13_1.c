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
    int check_blank;                                // 내용있으면 Full(= 1) 없는 빈공간(배열요소)이면 Empty(= 0) 
};

struct bookInfo* sort_book_list[Max_List];          // 정렬값 주소 저장

int PrintSortMenu(void);
int Length_of_List(struct bookInfo* bookPtr);
int PrintMainMennu();
void SortByTitle(struct bookInfo* bookPtr);
void SortByPubName(struct bookInfo* bookPtr);
void SortByPrice(struct bookInfo* bookPtr);
void InsertList(struct bookInfo* bookPtr);
void initsortList(struct bookInfo* bookPtr);

// ============================== < 매인 함수 > =====================================================

int main(void)
{
    
    struct bookInfo list[Max_List] = { //NULL,       // 실제 사용시
        { "다책", "가출판사", 800, Full },                // 정렬 기능확인을 위한 임시정보
        { "라책", "자출판사", 300, Full },                // 정렬 기능확인을 위한 임시정보
        { "마책", "바출판사", 500, Full },                // 정렬 기능확인을 위한 임시정보
        { "자책", "사출판사", 100, Full },                // 정렬 기능확인을 위한 임시정보
        { "아책", "나출판사", 700, Full },                // 정렬 기능확인을 위한 임시정보
        { "나책", "아출판사", 900, Full },                // 정렬 기능확인을 위한 임시정보
        { "가책", "마출판사", 110, Full },                // 정렬 기능확인을 위한 임시정보
        { "바책", "차출판사", 20, Full},                 // 정렬 기능확인을 위한 임시정보
        { "사책", "라출판사", 400, Full },                // 정렬 기능확인을 위한 임시정보
        { "차책", "다출판사", 600, Full }                 // 정렬 기능확인을 위한 임시정보
    };

    int Select_Main_Menu = 0;

    initsortList(list);

    // 프로그램 동작부
    while(1)
    {
        // 매인메뉴 출력
        Select_Main_Menu = PrintMainMennu();

        
        if (Select_Main_Menu == Main_Print_TITLE)                               // 1.목록출력(이름정렬)
        {   
            SortByTitle(list);
        }

      
        else if (Select_Main_Menu == Main_Registe)                          // 2.등록
        {   
            InsertList(list);
        }

        
        else if (Select_Main_Menu == Main_Set_SortStandard)                          // 3.정렬 출력
        {
            while (1)
            {
                // 정렬 메뉴 출력
                int Select_Sort_Menu = PrintSortMenu();

                if (Select_Sort_Menu == SORT_TITLE)                       // 3.1 타이틀 기준 정렬
                {
                    SortByTitle(list);
                    
                }

                else if (Select_Sort_Menu == SORT_PUB)                  // 3.2 출판사 기준 정렬
                {
                    SortByPubName(list);
                    
                }

                else if (Select_Sort_Menu == SORT_PRICE)                  // 3.3 가격 기준 정렬
                {
                    SortByPrice(list);
                    
                }
                else if (Select_Sort_Menu == Sort_EXIT)                 // 3.4 뒤로
                {
                    system("cls");
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
        else if (Select_Main_Menu == Main_EXIT)                          // 4.  종료
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
        if ((bookPtr+i)->check_blank == Full)
        {
            Length++;
        }
    }
    return Length;
}

//  값을 보고 그 크기를 비교해서 그 값이 들어간 구조체의 주소를 저장하는 구조체포인터를 생성함
//  해당 포인터가 bookPtr(매인에서의 list를 받아옴)를 가리키게한다
void initsortList(struct bookInfo* bookPtr)
{
    int Length = Length_of_List(bookPtr);
    for (int i = 0; i < Length; i++)
    {
        sort_book_list[i] = &bookPtr[i];
    }
}

// 정렬메뉴 출력함수
int PrintSortMenu(void)
{
    system("cls");
    int Select_Sort_Menu = 0;
    printf("\n ==================================================\n");
    printf("\t  < 도서 정보 정렬 기준 선택 > \n");
    printf("\n ==================================================\n");
    printf("\n 1. 도서명기준\n\n");
    printf(" 2. 출판사기준\n\n");
    printf(" 3. 가격기준\n\n");
    printf(" 4. 뒤로\n");
    printf("\n ==================================================\n");
    printf(" 정렬기준을 선택하세요: ");
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

// 도서 정보가 저장이 될 때, 도서 이름의 오름차순으로 정렬하여 저장이 되도록 합니다.
void InsertList(struct bookInfo* bookPtr)
{
    struct bookInfo temp = { NULL, };
    struct bookInfo* Temp = { NULL, };
    int Length = Length_of_List(bookPtr);

    

    // 입력받음
    printf("\n등록하려는 도서의 이름을 입력해주세요: ");
    scanf("%s", (bookPtr + Length)->bookTitle);
    printf("\n등록하려는 도서의 출판사를 입력해주세요: ");
    scanf("%s", (bookPtr + Length)->bookPub);
    printf("\n등록하려는 도서의 가격을 입력해주세요: ");
    scanf("%d", &(bookPtr + Length)->bookPrice);
    (bookPtr + Length)->check_blank = Full;

    initsortList(bookPtr);

    // 정렬
 
    for (int i = 0; i < Length-1; i++)
    {
        for (int j = 0; j < (Length-i)-1; j++)
        {
            if (strcmp(sort_book_list[j]->bookTitle, sort_book_list[j+1]->bookTitle) < 0)
            {

                /* 기존코드 - 직접 배열값을 전부 바꿨다 -> 자원낭비심함, 속도느림, 오류가능성 높음
                 
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
    printf("\n등록 및 정력이 완료되었습니다. 등록번호: < %d >번 입니다\n", Length);
    system("PAUSE");
    system("cls");
}


// 선택된 기준으로 도서정보가 정렬이 되도록 구현합니다.
// 정렬 기준 : 도서 타이틀, 출판사면, 도서가격

void SortByTitle(struct bookInfo* bookPtr)      // 도서타이틀순
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
                /* 기존코드 - 직접 배열값을 전부 바꿨다 -> 자원낭비심함, 속도느림, 오류가능성 높음
                
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
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d원\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
    
    
}

void SortByPubName(struct bookInfo* bookPtr)    // 출판사순
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
                /* 기존코드 - 직접 배열값을 전부 바꿨다 -> 자원낭비심함, 속도느림, 오류가능성 높음

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
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");

    for (int i = 0; i < Length; i++)
    {
        printf("\t%-15s \t %10s \t %5d원\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }

    printf(" ==============================================================\n");

    printf("\n");
    system("PAUSE");
    system("cls");
}

void SortByPrice(struct bookInfo* bookPtr)      // 가격순
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
    printf("\t도서명 \t\t\t 출판사 \t 가격(원) ");
    printf("\n ==============================================================\n");



    for (int i = 0; i < Length; i++)
    {
       printf("\t%-15s \t %10s \t %5d원\n", sort_book_list[i]->bookTitle, sort_book_list[i]->bookPub, sort_book_list[i]->bookPrice);
    }



    printf(" ==============================================================\n");
    printf("\n");
    system("PAUSE");
    system("cls");
}


