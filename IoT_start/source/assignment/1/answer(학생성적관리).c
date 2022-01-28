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
#define EXCEPT_ON_WHEN_SEARCH_MSG "����"

/* CURD �Լ� */
void insertData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);
void updateData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);
void deleteData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray);
void recoveryData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray);
void printData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[], int idxOfArray);
void selectData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray);

/* ���� ������ ��� �Լ� */
int insertSampleData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int deleteDataList[]);

/* �޴� ���� �Լ� */
int menuOfLevel1();
void movePreMenu();

/* ���� �Լ� */
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
			case 1:							//�л� ���� ���
				insertData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				idxOfArray++;		//��� �Ѹ��� ��������Ƿ� idxOfArray+1
				break;

			case 2:							//�л� ���� ��ü ���
				printData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, deleteDataList, idxOfArray);
				break;

			case 3:							//�л� ���� ����
				updateData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				break;

			case 4:							//�л� ���� ����
				deleteData(studentNameList, deleteDataList, idxOfArray);
				break;

			case 5:							//�л� ���� ����
				recoveryData(studentNameList, deleteDataList, idxOfArray);
				break;

			case 6:							//�л� �̸����� ���� ��ȸ
				selectData(studentNameList, korScoreList, engScoreList, mathScoreList, sciScoreList, totScoreList, idxOfArray);
				break;

			case 7:							//���α׷� ����
				exit(0);
		}

	}
}

int menuOfLevel1() {
	int numberOfMenu;

	printf(" ��ȣ     �޴���   \n");
	printf("=====================\n");

	printf("  1.  �л� ���� ���\n");
	printf("  2.  �л� ���� ��ü ���\n");
	printf("  3.  �л� ���� ����\n");
	printf("  4.  �л� ���� ����\n");
	printf("  5.  �л� ���� ����\n");
	printf("  6.  �л� �̸����� ���� ��ȸ\n");
	printf("  7.  ���α׷� ����\n\n");
	printf("�޴� ��ȣ�� �Է��ϼ���. >> ");

	scanf("%d", &numberOfMenu);

	return numberOfMenu;
}

void movePreMenu() {
	printf("\n�����޴��� ���÷��� ����Ű�� ��������.\n");
	getch();
}

void insertData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray) {
	char studentName[LENGTH_OF_STRING];

	system("cls");

	printf("�л��� ������ ����մϴ�. \n\n");
	printf("�л��� �̸��� �Է����ּ��� >> ");
	scanf("%s", studentName);
	strcpy(studentNameList[idxOfArray], studentName);

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(korScoreList[idxOfArray]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(engScoreList[idxOfArray]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(mathScoreList[idxOfArray]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(sciScoreList[idxOfArray]));
	totScoreList[idxOfArray] = (korScoreList[idxOfArray] + engScoreList[idxOfArray] + mathScoreList[idxOfArray] + sciScoreList[idxOfArray]);

}

void updateData(char studentNameList[][LENGTH_OF_STRING], int korScoreList[], int engScoreList[], int mathScoreList[], int sciScoreList[], int totScoreList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("�л��� ������ �����մϴ�. \n\n");
	printf("  ��ȣ  �̸�   \n");
	printf("===============\n");

	for (int i = 0; i < idxOfArray; i++)
		printf("%d. %s\n", i + 1, studentNameList[i]);

	printf("\n������ �л��� ��ȣ�� �Է��ϼ���. >> ");

	scanf("%d", &numberOfSelect);


	printf("�л��� �̸��� �Է����ּ��� >> ");
	scanf("%s", studentName);
	strcpy(studentNameList[numberOfSelect - 1], studentName);

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(korScoreList[numberOfSelect - 1]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(engScoreList[numberOfSelect - 1]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(mathScoreList[numberOfSelect - 1]));

	printf("�л��� ���� ������ �Է����ּ��� >> ");
	scanf("%d", &(sciScoreList[numberOfSelect - 1]));

	totScoreList[numberOfSelect - 1] = (korScoreList[numberOfSelect - 1] + engScoreList[numberOfSelect - 1] + mathScoreList[numberOfSelect - 1] + sciScoreList[numberOfSelect - 1]);
}

void deleteData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("�л��� ������ �����մϴ�. \n\n");
	printf("  ��ȣ  �̸�   �������� \n");
	printf("========================\n");

	for (int i = 0; i < idxOfArray; i++)
		if (deleteDataList[i] == EXCEPT_ON_WHEN_SEARCH) printf("  %d. %s  %s\n", i + 1, studentNameList[i], EXCEPT_ON_WHEN_SEARCH_MSG);
		else printf("  %d. %s\n", i + 1, studentNameList[i]);

	printf("\n������ ������ �л��� ��ȣ�� �Է��ϼ���.( ��Ҵ� 0 �Է�! ) >> ");

	scanf("%d", &numberOfSelect);

	if (!numberOfSelect) return;

	deleteDataList[numberOfSelect - 1] = EXCEPT_ON_WHEN_SEARCH;
}

void recoveryData(char studentNameList[][LENGTH_OF_STRING], int deleteDataList[], int idxOfArray) {
	int numberOfSelect;
	char studentName[LENGTH_OF_STRING];

	system("cls");
	printf("�л��� ������ �����մϴ�. \n\n");
	printf("  ��ȣ  �̸�   �������� \n");
	printf("========================\n");

	for (int i = 0; i < idxOfArray; i++)
		if (deleteDataList[i] == EXCEPT_ON_WHEN_SEARCH) printf("  %d. %s  %s\n", i + 1, studentNameList[i], EXCEPT_ON_WHEN_SEARCH_MSG);
		else printf("  %d. %s\n", i + 1, studentNameList[i]);

	printf("\n������ �л��� ��ȣ�� �Է��ϼ���.( ��Ҵ� 0 �Է�! ) >> ");

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
	printf("  �л���     ����    ����    ����   ����   ����   ���   ����\n");
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
	printf("�л��� ������ ��ȸ�մϴ�. \n\n");
	printf("������ ��ȸ�� �л����� �Է����ּ���. >> ");
	scanf("%s", studentName);

	printf("  �л���     ����    ����    ����   ����   ����\n");
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

	strcpy(studentNameList[0], "�Ϲ��л�");
	deleteDataList[0] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[0] = 80;	engScoreList[0] = 80;	mathScoreList[0] = 80;	sciScoreList[0] = 80;	totScoreList[0] = 320;

	strcpy(studentNameList[1], "�̹��л�");
	deleteDataList[1] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[1] = 90;	engScoreList[1] = 90;	mathScoreList[1] = 90;	sciScoreList[1] = 90;	totScoreList[1] = 360;

	strcpy(studentNameList[2], "����л�");
	deleteDataList[2] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[2] = 90;	engScoreList[2] = 90;	mathScoreList[2] = 90;	sciScoreList[2] = 90;	totScoreList[2] = 360;

	strcpy(studentNameList[3], "����л�");
	deleteDataList[3] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[3] = 90;	engScoreList[3] = 90;	mathScoreList[3] = 90;	sciScoreList[3] = 90;	totScoreList[3] = 360;

	strcpy(studentNameList[4], "�����л�");
	deleteDataList[4] = EXCEPT_OFF_WHEN_SEARCH;
	korScoreList[4] = 100;	engScoreList[4] = 100;	mathScoreList[4] = 100;	sciScoreList[4] = 100;	totScoreList[4] = 400;

	return 5;
}