#include <stdio.h>
#include <ctype.h>

int main()
{
    char input; // 입력 문자
    int charnum[26] = {0}; // 입력 횟수
    int max = 0; // charnum의 최댓값
    char most; // 가장 많이 나온 문자
    int i; // 인덱스(for문 용)
    int warn = 0; // max값이 2회 이상 나올 시 ? 반환
    
    // 입력받는 문자 체크(엔터키 입력시 반복문 종료)
    while((input = getchar()) != '\n')
        charnum[toupper(input) - 'A']++;

    // 가장 많이 나온 문자 체크
    for(i = 0 ; i < 26 ; i++)
    {
        if(charnum[i] > max)
        {
            max = charnum[i];
            most = i + 'A';
        }
    }

    // 가장 많이 나온 문자가 2개 이상인지 체크
    for(i = 0 ; i < 26 ; i++)
    {
        if(max == charnum[i])
            warn++;
        
        if(warn >= 2)
            most = '?';
    }

    // 결과 출력
    printf("%c\n", most);

    return 0;
}