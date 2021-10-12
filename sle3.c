#include <stdio.h>

int main()
{
    long long int number;
    int direct = 0;
    int sum = 0, six;

    scanf("%lld", &number);
    six = 6;

    while(sum < number - 1)
    {
        sum += six;
        six += 6;
        direct++;
    }

    if(number == 1)
        printf("%d", 1);
    else
        printf("%d", direct + 1);

    return 0;
}