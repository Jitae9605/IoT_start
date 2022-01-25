#include <stdio.h>
#include <string.h>

void print_init_title(void);
void print_reg_title(void);
void print_list(void);

char student_name[10][80] = { "학생1","학생2","학생3","학생4","학생5","학생6","학생7","학생8","학생9","학생10" };
int student_grade[4][10] = {
	{11,12,13,14,15,16,17,18,19,20},		// 국어
	{21,22,23,24,25,26,27,28,29,30},		// 영어
	{31,32,33,34,35,36,37,38,39,40},		// 수학
	{41,42,43,44,45,46,47,48,49,50}		// 과학
};
int select_menu_num = 0;
int select_student_name_for_revice = 0;
int select_student_grade_for_revice = 0;

char student_name_change[80];
int cnt = sizeof(student_name) / sizeof(student_name[0]);
int student_grade_change[4] = { 0 };


int main(void)
{
	// 지금 까지 C언어의 배운 범위내에서 구현하시면 됩니다.

	//	- 관리할 학생 수
	//	10명

	//	- 관리할 학생의 데이터
	//	이름(문자), 4 과목(국어, 영어, 수학, 과학)의 성적 점수(숫자)

	//	- 기능
	//	학생 등록 및 수정,
	//	성적 등록 및 수정,
	//	학생 이름으로 성적 조회 후 출력,
	//	전체 학생을 성적순으로 출력,
	//	성적 출력시 제목으로 이름, 과목명, 총점, 평균, 석차 를 먼저 출력한 후,
	//	학생 별 성적 결과가 출력이 되도록 할 것.

	//	- 구현시 고려할 점.
	//	재사용 및 유지보수를 고려해서 구현할 것.
	//	미니프로젝트 시연 동영상을 참고할 것. (단톡에 공지한 내용 참고)


	while (1)
	{
		print_init_title();
		printf("원하는 메뉴를 선택하십시오. : ");
		scanf("%d", &select_menu_num);

		if (select_menu_num == 1)
		{
			// 학생 등록 및 수정
			printf("수정전 리스트입니다.\n");
			print_list();
			printf("\n등록 및 수정할 학생의 번호를 입력하여 주세요 : ");
			scanf("%d", &select_student_name_for_revice);
			printf("변경할 이름을 말씀해주세요 :");
			scanf("%s", student_name_change);
			
			// 이름 변경
			for (int i = 0; i < 80; i++)
			{
				student_name[select_student_name_for_revice-1][i] = student_name_change[i];
			}

			printf("수정후 리스트입니다.\n");
			print_list();
		} 

		else if (select_menu_num == 2)
		{
			// 성적 등록 및 수정
			printf("\n수정전 리스트입니다.\n");
			print_list();
			printf("\n등록 및 수정할 학생의 번호를 입력하여 주세요 : ");
			scanf("%d", &select_student_grade_for_revice);
			printf("\n성적을 입력해 말씀해주세요 :");
			scanf("%d %d %d %d", &student_grade_change[0], &student_grade_change[1], &student_grade_change[2], &student_grade_change[3]);

			// 성적변경
			for (int i = 0; i < 4; i++)
			{
				student_grade[i][select_student_grade_for_revice - 1] = student_grade_change[i];
			}

			printf("수정후 리스트입니다.\n");
			print_list();
		}

		else if (select_menu_num == 2)
		{
			// 조회
		}

		else
		{
			printf("잘못된 수를 입력하였습니다. 다시입력하세요.\n");
			select_menu_num = 0;
		}
	}
	




	return 0;
}

void print_init_title(void)
{
	// 프로그램 초기화면( 메뉴 0 )
	printf("\t === < 학생성적 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n");
	printf(" 1)학생등록 및 수정 \t2)성적등록 및 수정 \t3)조회 \n");
	printf("----------------------------------------------------------\n");


}

void print_reg_title(void)
{
	printf("\n\t === < 학생성적 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n");

}

void print_list(void)
{
	printf("\n----------------------------------------------------------\n\n");
	printf("\t 이름\t 국어\t 영어\t 수학\t 과학\n\n");

	for (int j = 0; j < 10; j++)
	{
		printf(" %d번\t %s\t %d\t %d\t %d\t %d\t\n", j+1, student_name[j], student_grade[0][j], student_grade[1][j], student_grade[2][j], student_grade[3][j]);
	}
	printf("\n----------------------------------------------------------\n\n");
	
}