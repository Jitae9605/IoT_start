#include <stdio.h>
#define PI 3.14
#define DATA_CNT    7
#define ARR_LEN    5
#define STR_LEN  256

#define  FACTOR_ONEUNDER_ERROR    -100

int Factorial(int);


int total(int kor, int eng, int mat);
double average(int tot);
void print_title(int kor, int eng, int mat, int tot, double avg);

int main_answer(void)
{

    /*문제 1 - 1

        실수(정수가 아닌 실수이다) 두 개를 입력 받아서, 두 실수의 사칙연산 결과를 
        출력하는 프로그램을 작성하세요.

        문제 1 - 1 실행의 예

        두 개의 실수 입력 : 3.7 2.5
        덧셈 결과 : 6.200000
        뺄셈 결과 : 1.200000
        곱셈 결과 : 9. 250000
        나눗셈 결과 : 1.480000*/


    /*double num1, num2;

    printf("두 개의 실수 입력: ");
    scanf("%lf %lf", &num1, &num2);

    printf("덧셈 결과: %lf \n", num1 + num2);
    printf("뺄셈 결과: %lf \n", num1 - num2);
    printf("곱셈 결과: %lf \n", num1 * num2);
    printf("나눗셈 결과: %.6lf \n", num1 / num2);*/


    //문제 1 - 2

    //    원의 반지름 정보를 입력 받아서, 원의 넓이를 계산해서 출력하는 프로그램을 작성해보세요.
    //    단 원의 넓이를 계산하는 공식은 다음과 같습니다.

    //    원의 넓이 공식 : 반지름 × 반지름 × 3.14

    /*double rad;

    printf("반지름 입력: ");
    scanf("%lf", &rad);

    printf("원의 넓이: %lf \n", rad * rad * PI);*/


    //문제 2

    //    7개의 숫자를 정수 형태로(반드시 정수 형태로 입력 받는다) 입력 받아서
    //    입력 받은 수들의 최대값, 최소값, 전체 합, 그리고 평균을 구하는 프로그램을 작성하세요.
    //    단 평균은 정확히 계산하여 소수점 이하까지 출력합니다.


    //int total = 0;
    //int min = 0, max = 0;
    //int i, input;

    ///** 초기 입력 **/
    //printf("정수형 데이터 입력: ");
    //scanf("%d", &input);
    //min = input;
    //max = input;
    //total += input;

    ///** 두 번째 이후 입력 **/
    //for (i = 0; i < DATA_CNT - 1; i++)
    //{
    //    printf("정수형 데이터 입력: ");
    //    scanf("%d", &input);
    //    if (min > input)   // 최소값 계산.
    //        min = input;

    //    if (max < input)   // 최대값 계산.
    //        max = input;

    //    total += input;   // 전체 합 계산.
    //}

    //printf("최대값: %d \n", max);
    //printf("최소값: %d \n", min);
    //printf("전체합: %d \n", total);
    //printf("평  균: %f \n", (double)total / DATA_CNT);



    //문제 3 - 1
    //    두 개의 숫자를 입력 받아서 그 중 큰 수를 출력하는 프로그램을 작성하세요.
    //    단, if 관련 문장을 사용한다면 삼항연산자(조건연산자)를 사용하는 프로그램도 작성해보세요.

    /*int num1, num2;
    int bigNumber;
    printf("두 개의 숫자를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    bigNumber = (num1 > num2) ? num1 : num2;

    printf("큰 수는 %d \n", bigNumber);*/



    /*문제 3 - 2
        세 개의 숫자를 입력 받아서 그 중 가장 큰 수를 출력하는 프로그램을 구현하세요.
        삼항연산자(조건연산자)를 사용해서 작성해보세요.*/

        //int num1, num2, num3;
        //int bigNumber;
        //printf("세 개의 숫자를 입력하세요: ");
        //scanf("%d %d %d", &num1, &num2, &num3);

        //bigNumber =
        //    (num1 > num2) ?
        //    (num1 > num3) ? num1 : num3 : (num2 > num3) ? num2 : num3;

        //printf("큰 수는 %d \n", bigNumber);


//문제 4 - 1 정수 n을 입력 받습니다.
//그리고 1부터 입력 받은 정수 n까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하세요.
//예를 들어서 정수 5를 입력 받으면, 1 + 2 + 3 + 4 + 5 의 연산 결과인 15를 출력해야 합니다.

//int num, i;
//int total = 0;
//
///* 1 이상의 정수를 입력받는 과정 */
//while (1)
//{
//    printf("1 이상의 정수 입력: ");
//    scanf("%d", &num);
//
//    if (num > 0)
//        break;
//    else
//        printf("1 이상의 정수를 입력해야 합니다.");
//}
//
///* 합의 계산 과정 */
//for (i = 1; i <= num; i++)
//total += i;
//
//printf("1부터 %d까지의 합은 %d. \n", num, total);



//문제 4 - 2 정수 n1과 n2를 입력 받습니다.
//그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하세요.
//예를 들어 2와 5가 입력되면  2 + 3 + 4 + 5 의 연산 결과를 출력해야 합니다.

//int num1, num2, i;
//int total = 0;
//
//int start, end;
//
//printf("두 개의 정수 입력: ");
//scanf("%d %d", &num1, &num2);
//
//if (num1 > num2)
//{
//    start = num2;
//    end = num1;
//}
//else
//{
//    start = num1;
//    end = num2;
//}
//
//for (i = start; i <= end; i++)
//total += i;
//
//printf(
//    "%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d\n",
//    num1, num2, total
//);


//문제5.정수 n1과 n2를 입력 받는다.그리고 1부터 2까지의 합을 계산해서 그 결과를 출력하되,
//3의 배수이거나 5의 배수이면 총 합에서 제외시키는 프로그램을 작성하세요.

//int num1, num2, i;
//int total = 0;
//
//int start, end;
//
//printf("두 개의 정수 입력: ");
//scanf("%d %d", &num1, &num2);
//
//if (num1 > num2)
//{
//    start = num2;
//    end = num1;
//}
//else
//{
//    start = num1;
//    end = num2;
//}
//
//for (i = start; i <= end; i++)
//{
//    if (!(i % 3) || !(i % 5))
//    {
//        printf("%d는 합에서 제외. \n", i);
//        continue;
//    }
//    total += i;
//}
//
//printf(
//    "%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d\n",
//    num1, num2, total
//);



//문제 6 - 1. 입력 받은 정수 n 이하의 자연수 중에서 짝수의 합과, 홀수의 합을 각각 계산하여
//출력하는 프로그램을 구현하세요.참고로 자연수라 함은 0보다 큰 정수를 의미합니다.

//int num, i;
//int oddTotal = 0;
//int evenTotal = 0;
//
//while (1)
//{
//    printf("자연수 입력: ");
//    scanf("%d", &num);
//
//    if (num > 0)
//        break;
//    else
//        printf("자연수가 아닙니다. 다시 입력!");
//}
//
//for (i = 1; i <= num; i++)
//{
//    if ((i % 2) == 0)
//        evenTotal += i;
//    else
//        oddTotal += i;
//}
//
//printf("%d 이하 홀수 합: %d \n", num, oddTotal);
//printf("%d 이하 짝수 합: %d \n", num, evenTotal);


//문제 6 - 2. 정수 n을 입력 받습니다(단 n은 2 이상이 입력되어야 합니다).
//그리고 1부터 시작해서 다음과 같은 형태로 점진적인 덧셈을 진행합니다.
//1 + 2 + 3 + 4 + 5 + 6 + .......
//이 때 얼마를 더하는 순간부터 덧셈의 결과가 n보다 커지기 시작하는지,
//그리고 n보다커지기 전과 n보다 커진 후의 덧셈 결과를 출력하는 프로그램을 구현하세요.

//int num, i;
//int total = 0;
//
//while (1)
//{
//    printf("2 이상 입력: ");
//    scanf("%d", &num);
//
//    if (num > 1)
//        break;
//    else
//        printf("2 이상이 아닙니다. 다시 입력!");
//}
//
//i = 1;
//while (num >= (total + i))
//{
//    total += i;
//    i++;
//}
//
//printf("%d를 더할 때 처음 %d를 넘기 시작한다. \n", i, num);
//printf("%d를 넘기 이전의 합: %d \n", num, total);
//printf("%d를 넘은 이후의 합: %d \n", num, total + i);





//문제 7 - 1. 대표적인 for문 중첩 예제인 구구단 출력 프로그램을 작성해보세요.
//그냥 전체를 출력하는 프로그램은 너무 단순한 관계로 1이 입력되면 홀수 단을(3, 5, 7, 9 단을),
//2가 입력되면 짝수 단을(2, 4, 6, 8 단을) 출력하도록 예제를 작성해보세요.

//int i;
//int sel = 0;
//int start = 0;
//
//while (1)  /** 정확한 입력을 위해서 **/
//{
//    printf("홀수 단(1), 짝수 단(2): ");
//    scanf("%d", &sel);
//
//    if (sel == 1 || sel == 2)
//        break;
//    else
//        printf("잘못된 입력입니다. 1 또는 2만 입력하세요. ");
//}
//
//start = (sel == 2) ? 2 : 3;  //sel이 2이면 2단부터, 아니면 3단부터 출력.
//
//for (; start <= 9; start += 2)
//{
//    for (i = 1; i <= 9; i++)
//        printf("%d x %d = %d \n", start, i, start * i);
//}


//문제 7 - 2. 정수 n을 입력 받습니다.그리고 다음 수식을 만족하는 정수 a, b, c의 모든 조합을 찾아서
//출력하는 프로그램을 작성하세요.단, a, b 그리고 c 값의 범위는 0 이상 100 이하로 제한합니다.
//
//axb - c = n
//
//
//문제 7 - 2 실행의 예
//
//정수 입력 : 12
//(1) ×(12) - (0) = (12)
//(1) ×(13) - (1) = (12)
//(1) X(14) - (2) (12)

//int num;
//int a, b, c;
//
//printf("정수 입력: ");
//scanf("%d", &num);
//
//for (a = 0; a <= 100; a++)
//{
//    for (b = 0; b <= 100; b++)
//    {
//        for (c = 0; c <= 100; c++)
//        {
//            if ((a * b - c) == num)
//                printf("(%d)x(%d)-(%d)=%d \n\n", a, b, c, num);
//        }
//    }
//}


//문제8.아래의 세부 요구사항에서 제시하는 정렬 알고리즘의 원리를 우선 이해하세요.
//그리고 이를 기반으로, 총 다섯 개의 숫자를 입력 받아서
//작은 수에서 큰 수의 순으로 정렬하여 출력하는 프로그램을 작성해보세요.
//
//● 세부 요구사항
//• 총 다섯 개의 숫자를 입력 받기 위해서 길이가 5인 int형 배열을 선언하세요.
//• 다섯 개의 숫자를 배열에 저장한 다음에, 작은 수에서 큰 수의 순서로 정렬을 하세요.그리고 정렬된 순서대로 출력해보세요.
//
//여러 가지 정렬 알고리즘 가운데 가장 간단한 버블 정렬(bubble sort) 알고리즘을 활용하세요.


//int arr[ARR_LEN];
//int idx;
//int i, j;
//int temp;
//
//for (idx = 0; idx < ARR_LEN; idx++)
//{
//    printf("숫자 %d 입력: ", idx + 1);
//    scanf("%d", &arr[idx]);
//}
//
//for (i = 0; i < ARR_LEN - 1; i++)
//{
//    for (j = 0; j < (ARR_LEN - i) - 1; j++)
//    {
//        if (arr[j] > arr[j + 1])
//        {
//            temp = arr[j];
//            arr[j] = arr[j + 1];
//            arr[j + 1] = temp;
//        }
//    }
//}
//
//printf("정렬된 출력: ");
//for (i = 0; i < ARR_LEN; i++)
//    printf("%d ", arr[i]);


//문제9.문자열을 입력 받으세요.그리고 입력 받은 문자열 중에서 알파벳 대문자는 소문자로,
//소문자는 대문자로 각각 변경하여 출력하는 프로그램을 작성하세요.
//단 알파벳 이외의 문자가 존재하면 특별한 변경 없이 출력하는 것으로 합니다.

//문자열 입력 : What Is Your Name ?
//wHAT iS yOUR nAME ?

//char str[STR_LEN];
//int strLen = 0;
//int i;
////A : 65, B : 66  //32 차
////a : 97, b : 98
//int diff = 'A' - 'a';     // 대문자와 소문자의 차를 계산.
//
//printf("문자열 입력: ");
//gets(str);
//strLen = strlen(str);    // 입력된 문자열의 길이 계산.
//
//for (i = 0; i < strLen; i++)
//{
//    if ('a' <= str[i] && str[i] <= 'z')
//        str[i] += diff;
//
//    else if ('A' <= str[i] && str[i] <= 'Z')
//        str[i] -= diff;
//
//    else
//        ;   // 이외의 경우에는 별로 할 일이 없어서 비워 둠.
//}
//
//puts(str);



//문제10.세 과목의 점수를 입력하여 총점과 평균을 구하고 출력하는 프로그램을 작성하세요.
//단, 다음 함수 원형과 기능을 참고하여 작성합니다.
//
//int total(int kor, int eng, int mat); // 세 과목의 점수를 넘겨받아 총점 반환 
//double average(int tot); // 총점을 넘겨받아 평균 반환
//void print_title(void); // 점수를 제외한 나머지 부분 출력


    //int score[3] = { 70, 80, 91 };
    //int sum = 0;
    //double avg = 0;

    //sum = total(score[0], score[1], score[2]);
    //avg = average(sum);

    //print_title(score[0], score[1], score[2], sum, avg);


//문제11.프로그램 사용자로부터 정수 하나를 입력 받아서, 입력 받은 수의 팩토리얼을
//계산하여 그 결과를 출력하는 프로그램을 작성하고자 합니다.
//예를 들어서 입력 받은 정수가 N이라면 1 × 2 X … X N 을 계산하여 그 결과를
//출력해야 합니다.
//이 문제 해결을 위해서 팩토리얼 계산 기능을 제공하는 함수 Factorial를 정의하고
//활용하고자 합니다.Factorial 함수는 호출될 때 정수 데이터를 하나 전달받아야 하며,
//전달받은 값을 기준으로 계산된 값을 반환해야 합니다.
//그리고, 프로그램 사용자로부터 1 이상의 정수를 입력 받도록 하고, 1보다 작은 수가
//입력되는 상황을 처리할 수 있도록 하세요.

int n, result;

printf("숫자 입력(1이상): ");
scanf("%d", &n);

result = Factorial(n);
if (result == FACTOR_ONEUNDER_ERROR)
puts("입력이 잘못되어 예상치 못한 결과를 얻었습니다.");
else
printf("%d! = %d \n", n, result);

return 0;
}

int Factorial(int num)
{
    int fact = 1;
    int i;

    if (num < 1)
        return FACTOR_ONEUNDER_ERROR;

    for (i = 1; i <= num; i++)
        fact *= i;

    return fact;
}


int total(int kor, int eng, int mat)
{
    int sum;

    sum = kor + eng + mat;

    return sum;
}

double average(int tot)
{
    double avg;

    avg = tot / 3;

    return avg;
}

void print_title(int kor, int eng, int mat, int tot, double avg)
{
    printf("------------------------------------------\n");
    printf("국어\t영어\t수학\t총점\t평균\n");
    printf("------------------------------------------\n");
    printf("%d\t%d\t%d\t%d\t%lf\n", kor, eng, mat, tot, avg);
}