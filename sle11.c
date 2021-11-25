#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int min, max; // 최소, 최댓값 입력
    int i; // 루프 돌리는 용도
    int d = 2; // 2의 배수부터 제거

    // 최소 최대 입력
    scanf("%d %d", &min, &max);

    // arr에 저장할 예정(저장값이 -1이면 해당 숫자는 소수가 아님. calloc인 이유는 초기화를 위함)
    int* arr = calloc(max - min + 1, sizeof(int));

    // 시작값이 1이면 1을 제거
    if(min == 1)
        arr[0] = -1;

    // 2부터 시작, d*d = max이면 d 이상의 숫자는 계산해 볼 필요가 없으므로 sqrt(max)까지만 생각.
    for(d = 2 ; d <= sqrt(max) ; d++)
    {
        // d - min이 0보다 클 경우
        if(d - min > 0)
            // 이미 제거된 숫자는 다시 생각하지 않음
            if(arr[d - min] == -1)
                continue;

        // 2부터 시작해서 각각 배수를 없앰(arr값에 -1을 넣음)
        for(i = 2 ; i <= max / d ; i++)
        {
            if(d * i >= min)
                arr[d * i - min] = -1;
        }
    }
    
    // arr값에 -1이 들어가지 않은 숫자만 표시
    for(i = 0 ; i <= max - min ; i++)
    {
        if(arr[i] != -1)
            printf("%d\n", i + min);
    }
}