#include <stdio.h>
#include <string.h>

void print_init_title(void);
void print_serch_title(void);
void print_list(void);
void print_list_all(void);

char student_name[10][80] = { "학생1","학생2","학생3","학생4","학생5","학생6","학생7","학생8","학생9","학생10" };
int student_grade[4][10] = {
	{15,12,13,14,23,16,17,18,15,20},		// 국어
	{21,61,23,24,25,26,27,25,29,31},		// 영어
	{61,37,55,34,35,41,37,38,86,60},		// 수학
	{81,72,43,94,41,46,47,48,79,57}			// 과학
};
int student_rank[10] = { 1,2,3,4,5,6,7,8,9,10 };
int select_menu_num = 0;
int select_student_name_for_revice = 0;
int select_student_grade_for_revice = 0;

char student_name_change[80];
int cnt = sizeof(student_name) / sizeof(student_name[0]);
int student_grade_change[4] = { 0 };
char serch_student_name[80];
int check_for_same = 0;
int total_grade[10] = { 0 };
double avg_grade[10] = { 0 };
int rank_all[10] = { 0 };
int temp = 0;
int total_grade_temp[10] = { 0 };



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

	// 0. 성적계산
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			total_grade[i] = total_grade[i] + student_grade[j][i];		// 총점 구하기
		}
		avg_grade[i] = total_grade[i] / 4;								// 평균 구하기
	}

	for (int i = 0; i < 10; i++)
	{
		total_grade_temp[i] = total_grade[i];
	}

	for (int i = 0; i < 10; i++)											// 석차 구하기
	{
		student_rank[i] = 11;
		for (int j = 0; j < 10; j++)
		{
			if (total_grade[i] >= total_grade[j])
				student_rank[i]--;
		}
	}


	while (1)
	{
		print_init_title();
		printf("\n원하는 메뉴를 선택하십시오. : ");
		scanf("%d", &select_menu_num);

		if (select_menu_num == 1)
		{
			// 1. 학생 등록 및 수정
			// 1.1 리스트 출력 및 대상입력받기
			printf("수정전 리스트입니다.\n");
			print_list();
			while (1)
			{
				printf("\n등록 및 수정할 학생의 번호를 입력하여 주세요 : ");
				scanf("%d", &select_student_name_for_revice);
				if (select_student_name_for_revice > 10 || select_student_name_for_revice < 0)
				{
					printf("잘못된 값입니다. 다시입력해 주세요.");
				}
				else
				{
					printf("변경할 이름을 말씀해주세요 :");
					scanf("%s", student_name_change);
					break;
				}
			}

			// 1.2 변경할 이름 입력받기
			for (int i = 0; i < 80; i++)
			{
				student_name[select_student_name_for_revice-1][i] = student_name_change[i];
			}

			printf("수정후 리스트입니다.\n");
			print_list();
		} 

		else if (select_menu_num == 2)
		{
			// 2. 성적 등록 및 수정
			// 2.1 리스트 출력 및 대상입력받기
			printf("\n수정전 리스트입니다.\n");
			print_list();
			while (1)
			{
				printf("\n등록 및 수정할 학생의 번호를 입력하여 주세요 : ");
				scanf("%d", &select_student_grade_for_revice);
				if (select_student_grade_for_revice > 10 || select_student_grade_for_revice < 0)
				{
					printf("잘못된 값입니다. 다시입력해 주세요.");
				}
				else
				{
					printf("\n성적을 입력해주세요 :");
					scanf("%d %d %d %d", &student_grade_change[0], &student_grade_change[1], &student_grade_change[2], &student_grade_change[3]);
					break;
				}
			}

			// 2.2 입력받은 성적 변경하기
			for (int i = 0; i < 4; i++)
			{
				student_grade[i][select_student_grade_for_revice - 1] = student_grade_change[i];
			}

			printf("수정후 리스트입니다.\n");
			print_list();
		}

		else if (select_menu_num == 3)
		{
			// 3. 조회

			while (1)
			{
				print_serch_title();
				printf("\n원하는 메뉴를 선택하십시오. : ");
				scanf("%d", &select_menu_num);

				if (select_menu_num == 1)
				{
					// 3.1 학생이름으로 조회
					printf("조회하고자 하는 학생의 이름을 입력하세요 : ");
					scanf("%s", serch_student_name);

					// 이름 문자열 비교
					while (1)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 80; j++)
							{
								if (serch_student_name[j] == student_name[i][j])
								{
									check_for_same++;
								}
							}
							if (check_for_same == 80)
							{
								printf("\n----------------------------------------------------------\n\n");
								printf("\t 이름\t 국어\t 영어\t 수학\t 과학\n\n");
								printf(" %d번\t %s\t %d\t %d\t %d\t %d\t\n", i + 1, student_name[i], student_grade[0][i], student_grade[1][i], student_grade[2][i], student_grade[3][i]);
								printf("\n----------------------------------------------------------\n\n");
								break;
							}
							else
							{
								check_for_same = 0;
							}
						}
						break;
						
					}

				}

				else if (select_menu_num == 2)
				{
					// 3.2 전체학생성적 조회
					print_list_all();
				}

				else if (select_menu_num == -1)
				{
					break;
				}
				else
				{
					printf("\n잘못된 수를 입력하였습니다. 다시입력하세요.\n");
				}
			}

			
		}


		else if (select_menu_num == -1)
		{
			// 4. 프로그램 종료
			break;
		}

		else
		{
			// 5. 잘못된 입력 처리
			printf("\n잘못된 수를 입력하였습니다. 다시입력하세요.\n");
			select_menu_num = 0;
		}
	}
	




	return 0;
}

void print_init_title(void)
{
	// 프로그램 초기화면( 메뉴 0 )
	printf("\n\t === < 학생성적 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n\n");
	printf(" 1)학생등록 및 수정 \t2)성적등록 및 수정 \t3)조회 \n");
	printf(" \n*종료하시려면 -1을 입력해주세요\n");
	printf("----------------------------------------------------------\n\n");


}

void print_serch_title(void)
{
	printf("\n\t === < 학생성적 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n\n");
	printf(" 1)학생이름으로 조회 \t2)전체학생통계조회 \n");
	printf(" \n*메인메뉴로 돌아가시려면 -1을 입력해주세요\n");
	printf("----------------------------------------------------------\n\n");

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

void print_list_all(void)
{
	// 총점순으로 재정렬후 출력(걍 석차순으로 출력하면 됨)
	printf("\n----------------------------------------------------------\n\n");
	printf("\t 이름\t 국어\t 영어\t 수학\t 과학\t 총점\t 평균\t 석차\n\n");


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (student_rank[j] == i + 1)
				printf(" %d번\t %s\t %d\t %d\t %d\t %d\t %d\t %lf\t %d\t\n", j + 1, student_name[j], student_grade[0][j], student_grade[1][j], student_grade[2][j], student_grade[3][j], total_grade[j], avg_grade[j], student_rank[j]);

		}
	}
	printf("\n----------------------------------------------------------\n\n");

}