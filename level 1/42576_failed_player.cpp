// https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    vector<string>::iterator itp = participant.begin();
    for (vector<string>::iterator itc = completion.begin(); itc != completion.end(); itc++)
    {
        if (*itp != *itc)
            break ;
        itp++;
    }
    return *itp;
}

int main(void)
{
    string ans = "";
    // vector<string> part = {"leo", "kiki", "eden"};
    // vector<string> comp = {"eden", "kiki"};

    // vector<string> part = {"marina", "josipa", "nikola", "vinko", "filipa"};
    // vector<string> comp = {"josipa", "filipa", "marina", "nikola"};

    // vector<string> part = {"mislav", "stanko", "mislav", "ana"};
    // vector<string> comp = {"stanko", "ana", "mislav"};

    vector<string> part = {"ana", "ana", "ana", "ana"};
    vector<string> comp = {"ana", "ana", "ana"};

    ans = solution(part, comp);
    cout << "The answer is " << ans << endl;
    return (0);
}
