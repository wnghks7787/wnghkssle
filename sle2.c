#include <stdio.h>

int main()
{
    int n;                                  // 시험을 본 과목의 개수
//    float score [];                     // 각 시험 점수
    int i;                                  // count
    int max;                                // 최고점수
    float average, total = 0.f;             // 총 합계와 평균

    printf("how many test? ");              // 시험을 본 과목의 갯수 입력
    scanf("%d", &n);
    float score [n];

    for(i = 0 ; i < n ; i++)
    {
        scanf("%f", &score[i]);             // 각 시험 점수 입력

        if(i != 0)
        {
            if(score[i] >= score[i-1])      // 각 시험 점수별 대소 비교, 최대값 산출
                max = score[i];
        }
        else
            max = score[i];
    }
    for(i = 0 ; i < n ; i++)                // 조작한 점수와 총점 계산
    {
        score[i] = score[i] / max * 100;
        total += score[i];
    }

    average = total / n;                    // 조작된 평균 산출

    printf("new average is %g\n", average); // 결과값 출력
    
    return 0;
}

