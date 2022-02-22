#include <stdio.h>
#define MAX_STRING 100

int main(void)
{
    /* 측정일 */
    int dateOfmeasurement;
    /* 측정 지역 */
    char areaOfmeasurement[MAX_STRING];
    /* 측정 오전 오후 */
    int ampmOfmeasurement; //am or pm
    /* 측정 날씨의 상세 */
    char detailedWeatherInfo[MAX_STRING];
    int returnValue;

    FILE* fp = fopen("weather.dat", "w");
    if (fp == NULL)
    {
        puts("파일 'weather.dat'가 열리지 않았습니다.");
        return -1;
    }

    while (1)
    {
        fputs("=== 날씨 데이터 입력 === \n", stdout);

        /* 1. 날짜 입력 : 숫자 */
        fputs("날짜: ", stdout);
        returnValue = scanf("%d", &dateOfmeasurement);
        getchar();
        if (returnValue == EOF)
            break;
        fwrite(&dateOfmeasurement, sizeof(int), 1, fp);

        /* 2. 지역 입력: 문자열 */
        fputs("지역: ", stdout);
        fgets(areaOfmeasurement, MAX_STRING, stdin);
        fputs(areaOfmeasurement, fp);

        /* 3. 오전/오후: 문자 */
        fputs("오전(A)/오후(P): ", stdout);
        ampmOfmeasurement = fgetc(stdin);
        fputc(ampmOfmeasurement, fp);
        getchar();

        /* 4. 날씨 입력: 문자열 */
        fputs("날씨: ", stdout);
        fgets(detailedWeatherInfo, MAX_STRING, stdin);
        fputs(detailedWeatherInfo, fp);

        fputs("\n", stdout);  // 한 줄 건너띄기 위한 코드
    }

    fclose(fp);
    puts("입력이 완료되었습니다.");
    return 0;
}