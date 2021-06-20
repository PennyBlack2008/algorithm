// 77484
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
순위	당첨 내용
1	6개 번호가 모두 일치
2	5개 번호가 일치
3	4개 번호가 일치
4	3개 번호가 일치
5	2개 번호가 일치
6(낙첨)	그 외
*/

int CalTrueCnt(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len)
{
    int true_cnt = 0;

    for (int i = 0; i < lottos_len; i++)
    {
        for (int j = 0; j < lottos_len; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                true_cnt++; break ;
            }
        }
    }
    return (true_cnt);
}

int CalFalseCnt(int lottos[], size_t lottos_len)
{
    int false_cnt = 0;

    for (int i = 0; i < lottos_len; i++)
    {
        if (lottos[i] == 0)
            false_cnt++;
    }
    return (false_cnt);
}

// void CalResult(int* lowest, int* highest, int true_cnt, int false_cnt)
// {
//     if (true_cnt == 6)
//         *lowest = 1;
//     else if (true_cnt == 5)
//         *lowest = 2;
//     else if (true_cnt == 4)
//         *lowest = 3;
//     else if (true_cnt == 3)
//         *lowest = 4;
//     else if (true_cnt == 2)
//         *lowest = 5;
//     else
//         *lowest = 6;

//     if (true_cnt + false_cnt == 6)
//         *highest = 1;
//     else if (true_cnt + false_cnt == 5)
//         *highest = 2;
//     else if (true_cnt + false_cnt == 4)
//         *highest = 3;
//     else if (true_cnt + false_cnt == 3)
//         *highest = 4;
//     else if (true_cnt + false_cnt == 2)
//         *highest = 5;
//     else
//         *highest = 6;
// }

void CalResult(int* lowest, int* highest, int true_cnt, int false_cnt)
{
    switch(true_cnt)
    {
        case 6: { *lowest = 1; break ; }
        case 5: { *lowest = 2; break ; }
        case 4: { *lowest = 3; break ; }
        case 3: { *lowest = 4; break ; }
        case 2: { *lowest = 5; break ; }
        default: { *lowest = 6; break ; }
    }
    printf("*lowest = %d\n", *lowest);

    switch(true_cnt + false_cnt)
    {
        case 6: { *highest = 1; break ; }
        case 5: { *highest = 2; break ; }
        case 4: { *highest = 3; break ; }
        case 3: { *highest = 4; break ; }
        case 2: { *highest = 5; break ; }
        default: { *highest = 6; break ; }
    }
    printf("*highest = %d\n", *highest);
}


// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int lowest, highest;
    int true_cnt; // 0 제외 몇개 맞췄는 지?
    int false_cnt; // 0 이 몇개 있는 지 확인

    // 0 제외 몇 개 맞췄는 지 계산
    true_cnt = CalTrueCnt(lottos, lottos_len, win_nums, win_nums_len);

    // 0 이 몇개인지
    false_cnt = CalFalseCnt(lottos, lottos_len);

    // 결과 계산
    CalResult(&lowest, &highest, true_cnt, false_cnt);

    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2);
    answer[0] = highest; answer[1] = lowest;
    return answer;
}

int main(void)
{
    int lottos[] = { 1, 2, 3, 4, 6, 5 };
    size_t lottos_len = 6;

    int win_nums[] = { 1, 2, 3, 4, 5, 6 };
    size_t win_nums_len = 6;

    int *ans;
    ans = solution(lottos, lottos_len, win_nums, win_nums_len);
    
    printf("\nthe answer is [%d, %d]\n", ans[0], ans[1]);

    return (0);
}