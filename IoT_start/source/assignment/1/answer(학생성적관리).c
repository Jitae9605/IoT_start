#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define CONST_TRUE 1
#define CNT_OF_STUDENT 10
#define LENGTH_OF_STRING 20

#define CLASS_RANKING_DEFAULT_VALUE 1

#define EXCEPT_ON_WHEN_SEARCH 0
#define EXCEPT_OFF_WHEN_SEARCH 1
#define EXCEPT_ON_WHEN_SEARCH_MSG "삭제"

/* CURD 함수 */
void insertData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);
void updateData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);
void deleteData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray);
void recoveryData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray);
void printData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[], int idxOfArray);
void selectData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);

/* 샘플 데이터 등록 함수 */
int insertSampleData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[]);

/* 메뉴 관련 함수 */
int menuOfLevel1();
void movePreMenu();

/* 메인 함수 */
void main421313() {
	int idxOfArray = 0;

	int deleteDataList[CNT_OF_STUDENT];
	char studentNameList[CNT_OF_STUDENT][LENGTH_OF_STRING];
	int korScoreList[CNT_OF_STUDENT];
	int engScoreList[CNT_OF_STUDENT];
	int mathScoreList[CNT_OF_STUDENT];
	int sciScoreList[CNT_OF_STUDENT];
	int totScoreList[CNT_OF_STUDENT];

	idxOfArray = insertSampleData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, deleteDataList);

	while (CONST_TRUE) {

		system("cls");
		int numberOfMenu = menuOfLevel1();

		switch (numberOfMenu) {
			case 1:							//학생 성적 등록
				insertData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				idxOfArray++;		//사람 한명을 등록했으므로 idxOfArray+1
				break;

			case 2:							//학생 성적 전체 출력
				printData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, deleteDataList, idxOfArray);
				break;

			case 3:							//학생 성적 수정
				updateData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				break;

			case 4:							//학생 성적 삭제
				deleteData(studentNameList, deleteDataList, idxOfArray);
				break;

			case 5:							//학생 성적 복구
				recoveryData(studentNameList, deleteDataList, idxOfArray);
				break;

			case 6:							//학생 이름으로 성적 조회
				selectData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				break;

			case 7:							//프로그램 종료
				exit(0);
		}

	}
}

int menuOfLevel1() {
	int numberOfMenu;

	printf(" 번호     메뉴명   \n");
	printf("=====================\n");

	printf("  1.  학생 성적 등록\n");
	printf("  2.  학생 성적 전체 출력\n");
	printf("  3.  학생 성적 수정\n");
	printf("  4.  학생 성적 삭제\n");
	printf("  5.  학생 성적 복구\n");
	printf("  6.  학생 이름으로 성적 조회\n");
	printf("  7.  프로그램 종료\n\n");
	printf("메뉴 번호를 입력하세요. >> ");

	scanf("%d", &numberOfMenu);

	return numberOfMenu;
}

void movePreMenu() {
	printf("\n상위메뉴로 가시려면 엔터키를 누르세요.\n");
	getch();
}

void insertData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray) {
	char studentName[LENGTH_OF_STRING];

	system("cls");

	printf("학생의 성적을 등록합니다. \n\n");
	printf("학생의 이름을 입력해주세요 >> ");
	scanf("%s", studentName);
	strcpy(studentNameList[idxOfArray], studentName);

	printf("학생의 국어 성적을 입력해주세요 >> ");
	scanf("%d", &(korScoreList[idxOfArray]));

	printf("학생의 영어 성적을 입력해주세요 >> ");
	scanf("%d", &(engScoreList[idxOfArray]));

	printf("학생의 수학 성적을 입력해주세요 >> ");
	scanf("%d", &(mathScoreList[idxOfArray]));

	printf("학생의 과학 성적을 입력해주세요 >> ");
	scanf("%d", &(sciScoreList[idxOfArray]));
	totScoreList[idxOfArray] = (korScoreList[idxOfArray] + engScoreList[idxOfArray] + mathScoreList[idxOfArray] + sciScoreList[idxOfArray]);

}

void updateData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("학생의 성적을 수정합니다. \n\n");
	printf("  번호  이름   \n");
	printf("===============\n");

	for (int i = 0; i < idxOfArray; i++)
		printf("%d. %s\n", i + 1, studentNameList[i]);

	printf("\n수정할 학생의 번호를 입력하세요. >> ");

	scanf("%d", &numberOfSelect);


	printf("학생의 이름을 입력해주세요 >> ");
	scanf("%s", studentName);
	strcpy(studentNameList[numberOfSelect - 1], studentName);

	printf("학생의 국어 성적을 입력해주세요 >> ");
	scanf("%d", &(korScoreList[numberOfSelect - 1]));

	printf("학생의 영어 성적을 입력해주세요 >> ");
	scanf("%d", &(engScoreList[numberOfSelect - 1]));

	printf("학생의 수학 성적을 입력해주세요 >> ");
	scanf("%d", &(mathScoreList[numberOfSelect - 1]));

	printf("학생의 과학 성적을 입력해주세요 >> ");
	scanf("%d", &(sciScoreList[numberOfSelect - 1]));

	totScoreList[numberOfSelect - 1] = (korScoreList[numberOfSelect - 1] + engScoreList[numberOfSelect - 1] + mathScoreList[numberOfSelect - 1] + sciScoreList[numberOfSelect - 1]);
}

void deleteData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("학생의 성적을 삭제합니다. \n\n");
	printf("  번호  이름   삭제여부 \n");
	printf("========================\n");

	for (int i = 0; i < idxOfArray; i++)
		if (deleteDataList[i] == EXCEPT_ON_WHEN_SEARCH) printf("  %d. %s  %s\n", i + 1, studentNameList[i], EXCEPT_ON_WHEN_SEARCH_MSG);
		else printf("  %d. %s\n", i + 1, studentNameList[i]);

	printf("\n성적을 삭제할 학생의 번호를 입력하세요.( 취소는 0 입력! ) >> ");

	scanf("%d", &numberOfSelect);

	if (!numberOfSelect) return;

	deleteDataList[numberOfSelect - 1] = EXCEPT_ON_WHEN_SEARCH;
}

void recoveryData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("학생의 성적을 복구합니다. \n\n");
	printf("  번호  이름   삭제여부 \n");
	printf("========================\n");

	for (int i = 0; i < idxOfArray; i++)
		if (deleteDataList[i] == EXCEPT_ON_WHEN_SEARCH) printf("  %d. %s  %s\n", i + 1, studentNameList[i], EXCEPT_ON_WHEN_SEARCH_MSG);
		else printf("  %d. %s\n", i + 1, studentNameList[i]);

	printf("\n복구할 학생의 번호를 입력하세요.( 취소는 0 입력! ) >> ");

	scanf("%d", &numberOfSelect);

	if (!numberOfSelect) return;

	deleteDataList[numberOfSelect - 1] = EXCEPT_OFF_WHEN_SEARCH;
}

void printData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[], int idxOfArray) {
	int classRanking[LENGTH_OF_STRING];

	system("cls");

	for (int i = 0; i < idxOfArray; i++)
		classRanking[i] = CLASS_RANKING_DEFAULT_VALUE;

	for (int i = 0; i < idxOfArray; i++) {
		for (int j = 0; j < idxOfArray; j++) {
			if (totScoreList[i] < totScoreList[j])
				classRanking[i]++;
		}
	}
	printf("  학생명     국어    영어    수학   과학   총점   평균   석차\n");
	printf("===================================================================\n");
	for (int i = 1; i < idxOfArray + 1; i++) {
		for (int j = 0; j < idxOfArray; j++) {
			if (i == classRanking[j])
				if(deleteDataList[i-1] == EXCEPT_OFF_WHEN_SEARCH)
					printf(" %s    %3d    %3d     %3d    %3d    %3d    %3d     %3d\n", 
						studentNameList[j], korScoreList[j], engScoreList[j], mathScoreList[j], sciScoreList[j], totScoreList[j], totScoreList[j] / 4, classRanking[j]);
		}
	}

	movePreMenu();
}
void selectData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray) {
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("학생의 성적을 조회합니다. \n\n");
	printf("성적을 조회할 학생명을 입력해주세요. >> ");
	scanf("%s", studentName);

	printf("  학생명     국어    영어    수학   과학   총점\n");
	printf("===================================================================\n");

	for (int i = 0; i < idxOfArray; i++) {
		if (!(strcmp(studentName, studentNameList[i]))) {
			printf(" %s    %3d    %3d     %3d    %3d    %3d\n",
				studentNameList[i], korScoreList[i], engScoreList[i], mathScoreList[i], sciScoreList[i], totScoreList[i]);
		}
	}

	movePreMenu();
}

int insertSampleData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[]) {

	strcpy(studentNameList[0], "일번학생");
	deleteDataList[0] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[0] = 80;	engScoreList[0] = 80;	mathScoreList[0] = 80;	sciScoreList[0] = 80;	totScoreList[0] = 320;

	strcpy(studentNameList[1], "이번학생");
	deleteDataList[1] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[1] = 90;	engScoreList[1] = 90;	mathScoreList[1] = 90;	sciScoreList[1] = 90;	totScoreList[1] = 360;

	strcpy(studentNameList[2], "삼번학생");
	deleteDataList[2] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[2] = 90;	engScoreList[2] = 90;	mathScoreList[2] = 90;	sciScoreList[2] = 90;	totScoreList[2] = 360;

	strcpy(studentNameList[3], "사번학생");
	deleteDataList[3] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[3] = 90;	engScoreList[3] = 90;	mathScoreList[3] = 90;	sciScoreList[3] = 90;	totScoreList[3] = 360;

	strcpy(studentNameList[4], "오번학생");
	deleteDataList[4] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[4] = 100;	engScoreList[4] = 100;	mathScoreList[4] = 100;	sciScoreList[4] = 100;	totScoreList[4] = 400;

	return 5;
}