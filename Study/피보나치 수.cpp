#include <vector>

using namespace std;

const int MOD = 1234567;
vector<int> memo;

// [상태]     n — 구하려는 항 번호
// [전이]     f(n) = (f(n-1) + f(n-2)) % MOD
// [가지치기] memo[n]에 값이 있으면 재계산 안 함
// [종료]     n <= 1 이면 n 반환

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;
    return memo[n];
}

int solution(int n)
{
    memo.assign(n + 1, -1);
    return fibo(n);
}