#include <stdio.h>
#include <string.h>

void print_init_title(void);						// 시작메뉴 출력하는 함수
void print_reg_title(void);							// 차량목록을 출력하는 함수

int ans = 0;												// 메인화면 선택지 입력사항 저장공간
char user_name[20] = { 0 };									// 현재 로그인된 아이디 이름_
int user_num = 0;											// 현재 로그인된 아이디 비번
int jugnum_reg = 0;											// 판단 매개변수(0 = 불일치, 1 = 일치)
char car_state[255] = { 0 };								// 차량 렌트상태 ( 0 = 가능, 1 = 렌트중)
char car_name[][80] = { "차1","차2","차3","차4","차5" };		// 초기등록된 차량 리스트
int car_select = 0;											// 렌트 메뉴에서 선택한 차량의 번호
char user_name_check[20] = { 0 };							// 등록된 회원인지 판단하는 temp (아이디)
int user_num_check = 0;										// 등록된 회원인지 판단하는 temp (비번)
int cnt = sizeof(car_name) / sizeof(car_name[0]);			// 행의 수를 계산하는 변수
char car_current_owner[20][20] = { 0 };						// 각 번호의 차량 현 소유주 이름
char user_reg_name[20][20] = { 0 };							// 등록된 사람의 이름
int user_reg_num[20] = { -1 };								// 등록된 사람의 이름
char user_name_reg[20] = { 0 };								// 등록하려는 경우의 temp
int user_num_reg = 0;										// 등록하려는 경우의 temp

int main_mini_project1(void)
{


	while (ans != 3)
	{
		print_init_title();
		printf("원하는 메뉴의 번호를 입력해 주세요 : ");
		scanf("%d", &ans);
		
		if (ans == 1)
		{
			// 렌트
			// 먼저 회원 이름, 연락처를 입력받아 user_name과 user_num에 집어넣는다.
			// 현재 있는 차량의 목록을 띄우고 원하는 차량의 번호(car_num)를 입력하라는 안내 메세지와 입력창을 띄운다
			// 렌트완료 메세지를 출력하고 차량의 상태를 렌트중으로 바꾼다 ( 다시 조회하면 해당 차량 없음 )
			// 렌트완료후 매인페이지로

			printf("\n이름을 입력해주세요 : ");
			scanf("%s", user_name);

			printf("\n비밀번호를 입력해주세요[0~9999]  : ");
			scanf("%d", &user_num);


			// 비밀번호 조건 확인
			if (user_num < 0 || user_num > 9999)
			{
				while (jugnum_reg == 0)
				{
					printf("\n다시 입력해주세요 : ");
					scanf("%s", user_name);
					if (user_num >= 0 && user_num <= 9999)
					{
						jugnum_reg++;
					}
				}

			}

			// 차량 리스트 출력
			else
			{
				print_reg_title();
				for (int i = 0; i < cnt;i++ )
				{
					printf("%d 번 차량: %s\t상태 : ", i+1, car_name[i] );
					// 차량 렌트가능(0), 불가능(1)
					if (car_state[i] == 0)
					{
						printf("렌트가능\n");
					}
					else 
					{
						printf("렌트중\n");
					}
				}

				printf("\n렌트를 원하는 차량의 번호를 입력해 주세요(-1을 입력하면 종료됩니다.) : ");
				scanf("%d", &car_select);							// 차량 선택

				while (1)
				{
					if (car_state[car_select-1] == 0 && (car_select < cnt)	)							// 렌트가능한 차량 선택
					{
						printf("\n%d 번 차량을 렌트하셨습니다. 즐거운 여행되십시오.\n", car_select);
						car_state[car_select - 1] = 1;								// 차량상태 렌트중으로 바꿈
						strcpy(car_current_owner[car_select - 1], user_name);		// 해당 차량번호에 해당하는 문자열에 주인이름을 적어넣음
						break;
					}
					else if (car_state[car_select-1] == 1)
					{
						printf("이미 렌트된 차량입니다. 다시 선택해 주세요.\n");
					}
					else if (car_select == -1)
					{
						printf("렌트메뉴를 종료합니다.\n");
						break;
					}
					else
					{
						printf("잘못된 입력값입니다. 다시 입력해주세요\n");
					}

				}
			

			}
		}

		else if (ans == 2)
		{
			// 반납(반납 = 차량반납)
			print_reg_title();
			printf("\n이름을 입력해주세요 : ");
			scanf("%s", user_name_check);

			printf("\n비밀번호를 입력해주세요[4자리]  : ");
			scanf("%d", &user_num_check);

			// 이름과 비밀번호를 토대로 차량을 조회
			if (user_name == user_name_check && user_num == user_num_check)
			{
				print_reg_title();
				printf("%s님께서 렌트하신 차량은 %d번 입니다.", user_name_check, car_select);
			}
			

		}

		else if (ans == 3)
		{
			// 회원등록
			while (1)
			{
				printf("\n이름을 입력해주세요 : ");
				scanf("%s", user_name_reg);

				for (int i = 0; i < 20; i++)
				{
					if (user_name_reg == user_reg_name[i])
					{
						printf("이미 있는 이름입니다. 다시 입력해주세요.");
						break;
					}

				}

				printf("\n비밀번호를 입력해주세요[4자리]  : ");
				scanf("%d", &user_num_reg);


				// 비밀번호 조건 확인
				if (user_num_reg < 0 || user_num_reg > 9999)
				{
					while (jugnum_reg == 0)
					{
						printf("\n다시 입력해주세요 : ");
						scanf("%s", user_num_reg);
						if (user_num_reg >= 0 && user_num_reg <= 9999)
						{
							jugnum_reg++;
						}
					}
					jugnum_reg = 0;
				}

					for(int i = 0; i < 20; i++)
					{
						// 빈공간 찾기
						if (user_reg_num[i] == -1)			// 초기값은 -1을 찾는다.
						{
							// 방금 입력받은 아이디와 번호를 각각 빈 공간에 넣어준다.
							strcpy(user_reg_name[i], user_name_reg);
							user_reg_num[i] = user_num_reg;
						}
						else
						{
							printf("빈 공간이 없습니다. 직워을 불러주세요.");
							break;
						}
						
					}
					
				
				


				break;
			}
		}

		else if (ans == 4)
		{
		// 시작메뉴에서 4를 입력받으면 프로그램 종료.
		break;

		}
		else
		{
			printf("잘못된 값이 입력되었습니다. 다시 입력해 주십시오.\n");
		}

	}

	printf("프로그램을 종료합니다.\n");

	return 0;
}


void print_init_title(void)
{
	// 프로그램 초기화면( 메뉴 0 )
	printf("\t === < 렌터카 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n");
	printf("\t1)렌트 \t2)반납 \t3)등록 \t4)나가기 \n");
	printf("----------------------------------------------------------\n");

	// 렌트 = 렌트
	// 반납 = 차량반납
	// 나가기 = q입력시 프로그램 종료
}

void print_reg_title(void)
{
	printf("\n\t === < 렌터카 관리프로그램 > === \t\t\n\n");
	printf("----------------------------------------------------------\n");

}

