#include <stdio.h>
#include <string.h>

int main()
{
    int num; // 입력받을 문자열 수
    int i, j; // for문 돌리는 용도
    int len; // 문자열의 길이
    int count = 0; // 그룹단어의 수
    int countG[26] = {0}; // 그룹단어를 체크하기 위한 배열
    char group[256]; // 입력받는 문자열
    int ok = 0; // 26이 되면, 그룹단어라는 뜻

    // 문자열 갯수 입력
    scanf("%d", &num);

    // 입력받은 문자열 갯수만큼 반복
    for(i = 0 ; i < num ; i++)
    {
        // 문자열 입력
        scanf("%s", group);

        // 문자열 길이 체크
        len = strlen(group);

        // countG 배열 초기화
        for(j = 0 ; j < 26 ; j++)
            countG[j] = 0;

        // 문자가 최초로 나올 경우, countG에 1을 넣음. 이미 countG가 1이 넘으면, 앞 문자와 같은지 확인하여 같지 않다면 다시 count함.(같을 경우 count하지 않음)
        for(j = 0 ; j < len ; j++)
        {
            if(countG[group[j] - 'a'] == 0)
                countG[group[j] - 'a']++;
            else if(countG[group[j] - 'a'] == 1)
            {
                if(group[j - 1] != group[j])
                    countG[group[j] - 'a']++;
            }

            if(countG[group[j] - 'a'] > 1)
                break;
        }

        // 만약 countG가 2가 넘는 문자가 있다면, ok를 올리지 않음. 한번도 나오지 않은 문자는 countG == 0, 1회만 나오거나 반복하여 나온 문자는 countG == 1이므로 ok를 올림
        for(j = 0 ; j < 26 ; j++)
        {
            if(countG[j] == 0 || countG[j] == 1)
                ok++;
        }
        // ok 가 26이면(모든 알파벳이 0 혹은 1이면), count를 올림
        if(ok == 26)
        {
            count++;
        }
        // ok 초기화
        ok = 0;
    }

    // 결과값 출력
    printf("%d\n", count);

    return 0;
}