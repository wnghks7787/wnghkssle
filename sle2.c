#include <stdio.h>

int main()
{
    int n;
    int i, j;
    float max;
    float average, total = 0.f;

    scanf("%d", &n);
    float score[n];

    for(i = 0 ; i < n ; i++)
    {
        scanf("%f", &score[i]);

        if(i == 0)
            max = score[i];
        else if(score[i] > max)
            max = score[i];
    }
    for(i = 0 ; i < n ; i++)
    {
        score[i] = score[i] / max * 100;
        total += score[i];
    }

    average = total / n;

    printf("%g", average);
    
    return 0;
}