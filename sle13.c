#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void find_primeNumber(bool* arr, int target);

int main()
{
    int N; // 입력받을 값의 개수
    int i, j, k; // 루프 돌리는 Index
    int temp; // 임시 저장소
    int checkJ = 0, checkK = 0; // J와 K 인덱스

    bool* target = (bool*)malloc(sizeof(bool) * 10000); // 에라토스테네스의 체를 받을 애

    // 소수 판별
    find_primeNumber(target, 10000);

    // 입력받을 값의 개수 입력
    scanf("%d", &N);

    // input 크기 설정
    int input[N];

    // N회 반복
    for(i = 0 ; i < N ; i++)
    {
        // 숫자 입력
        scanf("%d", &input[i]);

        // 입려받은 숫자의 절반을 기준으로 j는 작아지고 k는 커지면서 판별
        for(j = input[i] / 2 ; j >= 2 ; j--)
        {
            for(k = input[i] / 2 ; k < input[i] ; k++)
            {
                // j, k가 모두 소수일 경우에만 temp에 더한 값 저장
                if(target[j] == false && target[k] == false)
                {
                    temp = j + k;
                    
                    // temp가 입력받은 숫자를 만족하면 index 저장
                    if(temp == input[i])
                    {
                        checkJ = j;
                        checkK = k;
                    }
                }
                // index 저장 후 빠져나오기
                if(temp == input[i])
                    break;
            }
            // index 저장 후 빠져나오기
            if(temp == input[i])
                break;
        }
        // 결과 도출
        printf("%d %d\n", checkJ, checkK);
    }

    // 동적 메모리 할당 해제
    free(target);

    return 0;
}

//범위의 소수 판별 
void find_primeNumber(bool* arr, int target)
{
    int i, j;
	
    arr[0] = true;
    arr[1] = true;

    // 2부터 특정 수의 배수에 해당하는 수를 모두 지움
    for(i = 2 ; i <= target ; i++)
    {
        if(arr[i])
            continue; // 이미 지워진 수라면 건너뜀

        // 이미 지워진 숫자가 아니라면, 해당 숫자의 배수를 모두 true로 만듦
        for(j = 2 * i ; j <= target ; j += i)
            arr[j] = true;
    }
}