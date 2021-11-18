#include <stdio.h>
#include <string.h>

int main()
{
    char input[256]; // 입력 문장
    int count = 0; // 입력된 크로아티아 알파벳의 수
    int len; // 문장 길이

    // 문장 입력
    scanf("%s", input);

    // 문장 길이 체크
    len = strlen(input);

    // 크로아티아 알파벳 갯수 확인(끝에서부터)
    for(int i = len - 1 ; i >= 0 ; i--)
    {
        // 글자가 '='일 경우
        if(input[i] == '=')
        {
            // 그 전 글자가 c나 s면 1회 카운트 후 해당 글자는 다시 체크하지 않음
            if(input[i - 1] == 'c' || input[i] == 's')
            {
                count++;
                i--;
            }
            // 그 전 글자가 z이면 z 이전 글자도 확인함(d일 경우 1회 카운트 후 다시 체크하지 않음.)
            else if(input[i - 1] == 'z')
            {
                if(input[i - 2] == 'd')
                {
                    count++;
                    i -= 2;
                }
                else
                {
                    count++;
                    i--;
                }
            }
        }
        // 글자가 '-'일 경우
        else if(input[i] == '-')
        {
            // 그 전 글자가 c나 d일 경우 1회 카운트 후 다시 체크하지 않음
            if(input[i - 1] == 'c' || input[i - 1] == 'd')
            {
                count++;
                i--;
            }
        }
        // 글자가 j일 경우
        else if(input[i] == 'j')
        {
            // 그 전 글자가 l이나 n일 경우 1회 카운트 후 다시 체크하지 않음
            if(input[i - 1] == 'l' || input[i - 1] == 'n')
            {
                count++;
                i--;
            }
            // 그 전 글자가 크로아티아 알파벳과 상관 없을 경우 1회 카운트
            else
                count++;
        }
        // 그 외의 경우 1회 카운트
        else
            count++;
    }

    // 총 카운트한 횟수 출력
    printf("%d\n", count);

    return 0;
}