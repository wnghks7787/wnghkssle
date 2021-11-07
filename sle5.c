#include <stdio.h>

int main()
{
    int test;
    int total = 0;
    int overavg = 0;
    int grade[1000];
    float avg;
    int i, j;

    scanf("%d", &test);
    getchar();

    int student[test];
    float result[test];

    for(i = 0 ; i < test ; i++)
    {
        scanf("%d", &student[i]);

        total = 0;
        for(j = 0 ; j < student[i] ; j++)
        {
            scanf("%d", &grade[j]);
            total += grade[j];
        }
        avg = (float)total / student[i];
        overavg = 0;

        for(j = 0 ; j < student[i] ; j++)
        {
            if(grade[j] > avg)
                overavg++;
        }

        result[i] = 100 * (float)overavg / student[i];

    }

    for(i = 0 ; i < test ; i++)
        printf("%.3f%%\n", result[i]);

    return 0;
}