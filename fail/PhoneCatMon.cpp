// https://programmers.co.kr/learn/courses/30/lessons/1845
// 실패

#include <vector>
#include <algorithm>
using namespace std;

int EraseDblCnt(vector<int> nums)
{
    vector<int> copy_nums(nums);
    int cnt = 1;
    int flag = 0;

    sort(copy_nums.begin(), copy_nums.end());
    if (copy_nums.size() == 0)
        return (0);
    for (int i = 1; i < copy_nums.size(); i++)
    {
        if (copy_nums[i] != copy_nums[i - 1])
            cnt++;
    }
    return (cnt);
}

int solution(vector<int> nums)
{
    int answer = 1;
    int num_species = 0;
    int picks = nums.size() / 2;

    num_species = EraseDblCnt(nums);
    for (int i = 0; i < picks; i++)
    {
        answer *= num_species--;
    }

    return (answer);
}

int main(void)
{
    // vector<int> nums = { 1, 1, 1, 1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 7};
    vector<int> nums = { 3, 1, 2, 3};
    printf("숫자 종류 갯수는 ? %d\n", EraseDblCnt(nums)); // 정답 7개
    printf("%d\n", nums.size());
    printf("%d\n", solution(nums));
    return (0);
}