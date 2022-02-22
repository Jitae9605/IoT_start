#include <stdio.h>
#define MAX_STRING 100

int main(void)
{
    /* ������ */
    int dateOfmeasurement;
    /* ���� ���� */
    char areaOfmeasurement[MAX_STRING];
    /* ���� ���� ���� */
    int ampmOfmeasurement; //am or pm
    /* ���� ������ �� */
    char detailedWeatherInfo[MAX_STRING];

    FILE* fp = fopen("weather.dat", "r");
    if (fp == NULL)
    {
        puts("���� 'weather.dat'�� ������ �ʾҽ��ϴ�.");
        return -1;
    }

    while (1)
    {
        /* 1. ��¥ ��� : ���� */
        fread(&dateOfmeasurement, sizeof(int), 1, fp);
        if (feof(fp) != 0)
            break;

        fprintf(stdout, "��¥: %d \n", dateOfmeasurement);

        /* 2. ���� ���: ���ڿ� */
        fgets(areaOfmeasurement, MAX_STRING, fp);
        fprintf(stdout, "����: %s", areaOfmeasurement);

        /* 3. ����/����: ���� */
        ampmOfmeasurement = fgetc(fp);
        fprintf(stdout, "����(A)/����(P): %c \n", ampmOfmeasurement);

        /* 4. ���� ���: ���ڿ� */
        fgets(detailedWeatherInfo, MAX_STRING, fp);
        fprintf(stdout, "����: %s \n", detailedWeatherInfo);
    }

    fclose(fp);
    puts("����� �Ϸ�Ǿ����ϴ�.");
    return 0;
}
