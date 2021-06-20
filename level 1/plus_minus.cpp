// https://programmers.co.kr/learn/courses/30/lessons/76501
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0;
    for (int i = 0; i < absolutes_len; i++)
    {
        if (signs[i] == true)
            answer += absolutes[i];
        else if (signs[i] == false)
            answer += absolutes[i] * -1;
    }
    return answer;
}

int main(void)
{
    int ab1[] = {4, 7, 12}; bool sg1[] = {true, false, true};
    int ab2[] = {1, 2, 3}; bool sg2[] = {false, false, true};

    int ans1, ans2;

    ans1 = solution(ab1, 3, sg1, 3);
    ans2 = solution(ab2, 3, sg2, 3);

    printf("ans1 : %d\n", ans1);
    printf("ans2 : %d\n", ans2);
    return (0);
}