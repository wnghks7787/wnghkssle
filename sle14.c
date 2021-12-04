#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N; // 입력받을 숫자의 갯수
    int M; // 숫자 M
    int i, j, k; // 세 숫자 index
    int cardi, cardj, cardk; // 최종 선택된 카드 세장

    int temp = 0, hand = 0; // temp = 임시 저장소, hand = 실제로 도출할 결과

    // N과 M 입력
    scanf("%d %d", &N, &M);

    // 주어지는 card 크기 설정
    int* card = (int*)malloc(sizeof(int) * N);

    // card로 주어지는 값 입력
    for(i = 0 ; i < N ; i++)
        scanf("%d", &card[i]);

    // 세 장의 카드 선택
    for(i = 0 ; i < N - 2 ; i++)
    {
        for(j = i + 1 ; j < N - 1 ; j++)
        {
            for(k = j + 1 ; k < N ; k++)
            {
                // 선택된 카드들을 더함
                temp = card[i] + card[j] + card[k];

                // temp가 M보다 작거나 같아야 함
                if(temp <= M)
                    // temp는 가능한 큰 숫자여야 함
                    if(temp > hand)
                        hand = temp;
            }
        }
    }

    printf("%d\n", hand);

    free(card);
    return 0;
}