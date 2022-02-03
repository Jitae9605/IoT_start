#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)

#define id_limit 12
#define pw_limit 4
#define game 4
#define max_player 10

int loginCheck = 1; // 로그인 성공=1, 실패 또는 로그아웃=0

struct score {   // [게임 점수 구조체]
	int upDown;  // 업다운 점수
	int cal;     // 암산 점수
	int BW;      // 청기백기 점수
	int spot;    // 틀린그림 찾기
	int total;   // 통합 점수
};

struct player {              // [플레이어 정보 관리 구조체]
	struct score sc;		 // score 구조체를 멤버로 사용
	char id[id_limit + 1];   // 아이디
	char pw[pw_limit + 1];   // 비밀번호
	int rank;                // 랭킹
	int join;                // 등록 순서
};

int start();
void join(struct player allPlayerList[]); // 플레이어 등록 함수
struct player logIn(struct player p, struct player allPlayerList[]);
int main_menu();
int rank();

int main123() {
	int start_choice = 0, menu_choice = 0, rank_choice = 0;
	struct player p; // 플레이어 구조체 변수 선언
	struct player allPlayerList[max_player]; // 모든 플레이어 정보 저장할 구조체 배열 선언
	
	for (int i = 0; i < max_player; i++) {
		for (int j = 0; j <= id_limit; j++) {
			allPlayerList[i].id[j] = '\0';
		}
	} //플레이어 아이디 배열 null로 초기화

	while (1) {
		start_choice = start(); // 시작화면 출력

		if (start_choice == 1) { // 로그인 선택했을 때
			p = logIn(p, allPlayerList); // 로그인 함수 호출

			if (loginCheck == 0)continue; // 등록된 아이디 없을 때 시작화면으로 돌아가기
			else { // 로그인 성공, 메인화면으로
				menu_choice = main_menu();

				if (menu_choice == 1) {       // 업다운 게임 선택
					//업다운 게임 호출 작성하기
				}
				else if (menu_choice == 2) {  // 암산 게임 선택
					//암산 게임 호출 작성하기
				}
				else if (menu_choice == 3) {  // 청기백기 게임 선택
					//청기백기 게임 호출 작성하기
				}
				else if (menu_choice == 4) {  // 틀린그림찾기 게임 선택
					//틀린그림찾기 게임 호출 작성하기
				}
				else if (menu_choice == 5) {  // 랭킹 조회
					rank_choice = rank();

					if (rank_choice == 1) {   // 게임별 랭킹 조회

					}
					else if (rank_choice == 2) {  // 통합 랭킹 조회
					
					}
					else if (rank_choice == 3) {  // 다시 메인화면으로

					}
					else { // 이상한 거 눌렀을 때
					
					}
				}
				else if (menu_choice == 6) {  // 로그아웃
					printf("로그아웃되었습니다.\n");
					loginCheck = 0;
				}
				else if (menu_choice == 7) {  // 프로그램 종료
					printf("프로그램을 종료합니다.\n");
					break;
				}
				else { // 잘못된 선택
					printf("잘못된 입력입니다.\n");
				}
			}
		}

		else if (start_choice == 2) { // 플레이어 등록 선택했을 때
			join(allPlayerList);
		}

		else if (start_choice == 3) { // 종료 선택했을 때
			printf("프로그램을 종료합니다.\n");
			break;
		}

		else printf("잘못된 입력입니다.\n"); // 1,2,3 아닌 거 입력했을 때
	}

	return 0;
}

int start() {
	int choice;

	printf("\n[미니게임천국]\n\n"); 
	printf("(1) 로그인\n");
	printf("(2) 플레이어 등록\n");
	printf("(3) 종료\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}

void join(struct player allPlayerList[]) {
	int id_check = -1;
	char id_temp[id_limit + 1] = { NULL };

	printf("[플레이어 등록]\n\n");
	while (1) {
		printf("사용할 아이디를 입력하세요(최대 영어12글자, 한글6글자)\n");
		printf("입력 : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교
			if (id_check == 0) { // 존재하는 아이디일 때
				printf("이미 존재하는 아이디입니다.\n");
				break;
			}
		}

		if (id_check != 0) { // 생성 가능한 아이디일 때
			for (int i = 0; i < max_player; i++) {
				if (allPlayerList[i].id != NULL) { // 빈자리 찾아서
					strcpy(allPlayerList[i].id, id_temp); // 빈자리에 아이디 저장
					printf("사용 가능한 아이디입니다.\n");
					printf("비밀번호를 입력하세요(4자리 숫자)\n");
					printf("입력 : ");
					scanf("%s", allPlayerList[i].pw); // 비밀번호 저장
					break;
				}
			}
			printf("등록이 완료되었습니다.\n");
			break;
		}
	}
}

struct player logIn(struct player p, struct player allPlayerList[]) {
	char id_temp[id_limit + 1] = { NULL };
	char pw_temp[pw_limit + 1] = { NULL };
	int id_check = -1, pw_check = -1;

	printf("[로그인]\n\n");
	while (1) {
		printf("아이디 : ");
		scanf("%s", id_temp);

		for (int i = 0; i < max_player; i++) {
			id_check = strcmp(allPlayerList[i].id, id_temp); // 존재하는 아이디인지 비교
			if (id_check == 0) { // 존재하는 아이디일 때
				printf("비밀번호 :");
				scanf("%s", pw_temp);
				pw_check = strcmp(allPlayerList[i].pw, pw_temp); // 비번 맞는지 확인
			}
		}

		if (id_check != 0) { // 존재하는 아이디가 아닐 때,
			printf("존재하지 않는 아이디입니다.\n");
			loginCheck = 0;
			break;
		}

		if (id_check == 0 && pw_check == 0) { // 로그인 성공
			printf("로그인되었습니다.\n");
			loginCheck = 1;
			strcpy(p.id, id_temp);
			strcpy(p.pw, pw_temp); // 구조체 변수에 아디, 비번 멤버 저장
			//  메인메뉴 화면으로 보내주기
			break;
		}
		else if (id_check == 0 && pw_check != 0) { // 아이디 있는데 비번 틀릴 때
			printf("잘못된 비밀번호 입니다.\n");
		}
	}

	return p;
}

int main_menu() {
	int choice = 0;

	printf("[메인 메뉴]\n\n");
	printf("(1) 업다운\n");
	printf("(2) 암산\n");
	printf("(3) 청기백기\n");
	printf("(4) 틀린그림찾기\n");
	printf("(5) 랭킹 조회\n");
	printf("(6) 로그아웃\n");
	printf("(7) 프로그램 종료\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}

int rank() {
	int choice = 0;

	printf("[랭킹 조회]\n\n");
	printf("(1) 게임별 랭킹 조회\n");
	printf("(2) 통합 랭킹 조회\n");
	printf("(3) 뒤로가기\n");
	printf("입력 : ");
	scanf("%d", &choice);

	return choice;
}