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

    FILE* fp = fopen("weather.dat", "r");
    if (fp == NULL)
    {
        puts("파일 'weather.dat'가 열리지 않았습니다.");
        return -1;
    }

    while (1)
    {
        /* 1. 날짜 출력 : 숫자 */
        fread(&dateOfmeasurement, sizeof(int), 1, fp);
        if (feof(fp) != 0)
            break;

        fprintf(stdout, "날짜: %d \n", dateOfmeasurement);

        /* 2. 지역 출력: 문자열 */
        fgets(areaOfmeasurement, MAX_STRING, fp);
        fprintf(stdout, "지역: %s", areaOfmeasurement);

        /* 3. 오전/오후: 문자 */
        ampmOfmeasurement = fgetc(fp);
        fprintf(stdout, "오전(A)/오후(P): %c \n", ampmOfmeasurement);

        /* 4. 날씨 출력: 문자열 */
        fgets(detailedWeatherInfo, MAX_STRING, fp);
        fprintf(stdout, "날씨: %s \n", detailedWeatherInfo);
    }

    fclose(fp);
    puts("출력이 완료되었습니다.");
    return 0;
}
