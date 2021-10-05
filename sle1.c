#include <stdio.h>

int spsum(int number);

int main()
{
    int num;                                    // 입력받을 숫자
    int ten, one;                               // 10의자리, 1의자리 숫자
    int new_num = 0;                            // 새로운 숫자
    int i = 0;                                  // 카운팅

    printf("input nubmer : ");                  // 숫자 입력받기
    scanf("%d", &num);

    if(num >= 0 && num < 100)
    {
        new_num = spsum(num);                   // 최초 1회 시행
        i++;

        while(num != new_num)                   // 사이클이 끝날때까지 돌리기
        {
            new_num = spsum(new_num);
            i++;
        }

        printf("cycle is %d.\n", i);
    }
    else
        printf("error \n");                     // 범위 외 숫자 : 에러

    return 0;
}

int spsum(int number)
{
    int ten, one;
    int sum;

    ten = number / 10 % 10;                     // 10의 자리 숫자 뽑기
    one = number % 10;                          // 1의자리 숫자 뽑기

    sum = ten + one;                            // 10의자리 숫자 + 1의자리 숫자

    sum = sum % 10;
    sum += one * 10;

    return sum;
}