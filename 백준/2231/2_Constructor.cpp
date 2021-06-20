/*
윤성이의 답
*/

#include <iostream>

using namespace std;

int func(int arg)
{
    int sum = 0;
    /* 이렇게 하면 각 자리수를 더할 수 있다. */
    while (arg != 0)
    {
        sum += arg % 10;
        arg /= 10;
    }
    return (sum);
}

int main()
{
    int in;
    scanf("%d", &in);
    for (int i = 0; i < in; i++)
    {
        int sum = 0;
        /* sum 은 각자리수와 자신을 더한 값 */
        sum += i;
        sum += func(i);
        if (sum == in)
        {
            printf("%d\n", i);
            return (0);
        }
    }
    printf("0");
    return (0);
}