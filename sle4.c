#include <stdio.h>

int main()
{
    int t;
    int h;
    int i;
    int count = 0;

    scanf("%d", &t);
    int w[t];
    int room[t];
    int n[t];

    for(i = 0 ; i < t ; i++)
        scanf("%d %d %d", &w[i], &h, &n[i]);

    for(i = 0 ; i < t ; i++)
    {
        count = 0;
        while(w[i] < n[i])
        {
            n[i] -= w[i];
            count++;
        }
        room[i] = n[i] * 100 + count + 1;
        printf("%d\n", room[i]);
    }

    return 0;
}