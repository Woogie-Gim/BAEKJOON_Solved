#include <vector>

using namespace std;

// [제약] nums 길이 3~50 / C(50,3) = 19,600 → 완전탐색 가능
// [상태]     cur(고른 개수), start(다음 후보 시작), sum(합)
// [전이]     start 부터 하나 골라 → cur+1, i+1, sum+nums[i]
// [가지치기] i = start 부터만 → 순서 다른 중복 원천 차단
// [종료]     cur == 3 이면 소수 판정

int cnt;
vector<int> arr;

bool isPrime(int n)
{
    if (n < 2) { return false; }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) { return false; }
    }
    return true;
}

void rec(int cur, int start, int sum)
{
    if (cur == 3)
    {
        if (isPrime(sum) == true)
        {
            cnt++;
        }
        return;
    }

    for (int i = start; i < (int)arr.size(); i++)
    {
        rec(cur + 1, i + 1, sum + arr[i]);      // 다음은 i 보다 큰 것만
    }
}

int solution(vector<int> nums)
{
    arr = nums;
    cnt = 0;

    rec(0, 0, 0);
    return cnt;
}