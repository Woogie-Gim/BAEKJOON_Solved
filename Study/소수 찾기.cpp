#include <string>
#include <vector>
#include <set>

using namespace std;

// [상태]     cur(만든 자릿수), num(만든 수)
// [전이]     안 쓴 조각을 뒤에 붙임 → num * 10 + digit
// [가지치기] visited[i] 인 조각은 건너뜀
// [종료]     매 단계마다 num을 set에 기록. cur == 길이면 반환

set<int> made;              // 만들어진 수들 (중복 자동 제거)
vector<bool> visited;
string paper;

// 소수 판정. 제곱근까지만
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void rec(int cur, int num)
{
    // 조각을 하나라도 썼으면 기록
    if (cur > 0)
    {
        made.insert(num);
    }

    if (cur == (int)paper.size())
    {
        return;
    }

    for (int i = 0; i < (int)paper.size(); i++)
    {
        if (visited[i] == true)
        {
            continue;                       // 가지치기
        }

        visited[i] = true;                  // 선택
        rec(cur + 1, num * 10 + (paper[i] - '0'));
        visited[i] = false;                 // 복구
    }
}

int solution(string numbers)
{
    paper = numbers;
    made.clear();
    visited.assign(numbers.size(), false);

    rec(0, 0);

    int answer = 0;
    for (set<int>::iterator it = made.begin(); it != made.end(); it++)
    {
        if (isPrime(*it) == true)
        {
            answer++;
        }
    }

    return answer;
}