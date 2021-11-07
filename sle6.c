#include <stdio.h>

int selfnum(int number);

int main()
{
    int num = 1;
    int self;

    for(num = 1 ; num <= 10000 ; num++)
    {
        self = selfnum(num);
        switch(self)
        {
            case 0:
                break;
            case 1:
                printf("%d\n", num);
                break;
        }
    }
    return 0;
}

int selfnum(int number)
{
    int plus;
    int i = 0;

    if(number >= i)
    {
        for(i = 0 ; i < 10 ; i++)
        {
            plus = i + i;
            if(number == plus)
                return 0;
        }
        for(i = 10 ; i < 100 ; i++)
        {
            plus = i + (i / 10) + (i % 10);
            if(number == plus)
                return 0;
        }
        for(i = 100 ; i < 1000 ; i++)
        {
            plus = i + (i / 100) + ((i / 10) % 10) + (i % 10);
            if(number == plus)
                return 0;
        }
        for(i = 1000 ; i < 10000 ; i++)
        {
            plus = i + (i / 1000) + ((i / 100) % 10) + ((i / 10) % 10) + (i % 10);
            if(number == plus)
                return 0;
        }
        i = 10000;
        plus = i + (i / 10000) + ((i / 1000) % 10) + ((i / 100) % 10) + ((i / 10) % 10);
        if(number == plus)
            return 0;
    }
    return 1;
}
