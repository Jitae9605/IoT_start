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
    int returnValue;

    FILE* fp = fopen("weather.dat", "w");
    if (fp == NULL)
    {
        puts("���� 'weather.dat'�� ������ �ʾҽ��ϴ�.");
        return -1;
    }

    while (1)
    {
        fputs("=== ���� ������ �Է� === \n", stdout);

        /* 1. ��¥ �Է� : ���� */
        fputs("��¥: ", stdout);
        returnValue = scanf("%d", &dateOfmeasurement);
        getchar();
        if (returnValue == EOF)
            break;
        fwrite(&dateOfmeasurement, sizeof(int), 1, fp);

        /* 2. ���� �Է�: ���ڿ� */
        fputs("����: ", stdout);
        fgets(areaOfmeasurement, MAX_STRING, stdin);
        fputs(areaOfmeasurement, fp);

        /* 3. ����/����: ���� */
        fputs("����(A)/����(P): ", stdout);
        ampmOfmeasurement = fgetc(stdin);
        fputc(ampmOfmeasurement, fp);
        getchar();

        /* 4. ���� �Է�: ���ڿ� */
        fputs("����: ", stdout);
        fgets(detailedWeatherInfo, MAX_STRING, stdin);
        fputs(detailedWeatherInfo, fp);

        fputs("\n", stdout);  // �� �� �ǳʶ�� ���� �ڵ�
    }

    fclose(fp);
    puts("�Է��� �Ϸ�Ǿ����ϴ�.");
    return 0;
}