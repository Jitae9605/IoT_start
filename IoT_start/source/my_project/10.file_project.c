#define _CRT_SECURE_NO_WARNINGS // c에서 fopen은 매우 강력해서 위험함 이를 경고하는 오류를 무시하게 해준다
#include <stdio.h>

// 프로젝트 
// [비밀일기]
// 비밀번호를 입력받아서
// 맞은경우, 비밀일기(txt)를 읽어와서 보여주고 계속 작성 가능
// 틀린경우, 경고 메세지 표시하고 종료

#define MAX 10000
 
int main321(void)
{
	// fgets, fputs 활용
	char line[MAX]; // 파일에서 불러온 내용 저장할 변수(공간)
	char contexts[MAX]; // 일기장에 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력할때 키값 확인용(도난방지의 '*'표 출력효과 = 마스킹)

	printf("'비밀일기'에 오신 것을 환영합니다\n");
	printf("비밀번호를 입력하세요 : ");

	int i = 0; // 패스워드를 입력받는 함수
	while(1)
	{
		// ! getchar() / getch()의 차이 !
		// getchar() = 엔터를 입력받아야 동작함
		// getch() = 키 입력 시 바로바로 동작함
		c = getch();

		if (c == 13) // 13은 'Enter'를 나타내는 아스키코드
					 // Enter -> 비밀번호 입력 종료
		{
			password[i] = '\0';
			break;
		}

		else // 비밀번호 입력중
		{
			printf("*");
			password[i] = c;
		}
		i++; // 키를 누를때 마다 '*' 이 출력되고 
			 // 'c'에 값이 저장되어 'Enter'의 입력을 감지
	}

	// 비밀번호 : 나도코딩 = skehzheld
	printf("\n\n === 비밀번호 확인 중 ... === \n\n");

	// srrcmp(A, B) = A의 값이 B의 값과 일치하면 '0'을 반환
	if (strcmp(password, "skehzheld") == 0) // 비밀번호 일치 판단
	{
		printf(" === 비밀번호 확인 완료 ===\n\n");
		char* fileName = "d:\\secretdiaty.txt";
		FILE* file = fopen(fileName, "a+b");
		// = 파일이 없으면 생성, 있으면 append(뒤에서부터 내용추가)를 한다.

		// 파일열기 실패한 경우 출력
		if (file == NULL)
		{
			printf("파일 열기 실패\n");
			return 1;
		}

		// 파일열기 성공한 경우 파일의 기존 쓰여진 내용을 출력해줌
		// fgets함수를 통해 line에 file의 내용을 가져온다(한줄씩)
		while (fgets(line, MAX, file) != NULL) // 가져올 내용이 없을때 까지
		{
			printf("%s", line); // 가져온 내용을 반복출력
		}

		// 이어서 작성 및 빠져나가는 방법
		printf("\n\n 내용을 계속 작성하세요! 종료하려면 EXIT를 입력하세요.\n\n");

		while (1)
		{
			scanf("%[^\n]", contexts); // 새 줄(= 줄바꿈)이 나올때까지 읽어들여라는 의미
			getchar(); // Enter입력(\n)을  Flush처리(= 무시 or 삭제)

			// 입력된 내용이 EXIT인지여부 확인
			if (strcmp(contexts, "EXIT") == 0)
			{
				printf("비밀일기 입력을 종료합니다\n\n");
				break;
			}
			fputs(contexts, file);
			fputs("\n", file); // getchar()을 통해 입력받은 Enter를 한번 무시했으니
							   //이를 보상해야 입력한 대로 저장된다
		}
		fclose(file);
	}
	else // 비밀번호 틀린경우
	{
		printf(" === 비밀번호 틀림 === \n\n");
		printf("접속 거부 처리되었습니다!\n\n\n");
	}

	return 0;
}