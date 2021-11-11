#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000002]; // 뒤에 +2 한 이유 : 개행문자 +1, NULL +1
    int count = 0; // 단어 갯수 카운터

    // 문자열 입력
    fgets(input, 1000002, stdin);
    input[strlen(input)] = '\0';

    // 맨 앞이 space가 아닌 경우에도 count++
    if(isalpha(input[0]) != 0)
        count++;
    // 맨 앞부터 space가 나올 때마다 count++(단, space 뒤에 문자가 있어야 함)
    for(int i = 0 ; i < 1000002 ; i++)
    {
        if(input[i] == ' ' && isalpha(input[i + 1]) != 0)
            count++;
        // 문자열 맨 끝에서 for문 종료
        if(input[i] == '\0')
            break;
    }

    // 결과 출력
    printf("%d\n", count);

    return 0;
}