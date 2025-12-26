#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const long long MOD = 1000000007;

    int N;
    cin >> N;

    vector<long long> A(N);
    long long totalSum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        totalSum = (totalSum + A[i]) % MOD;
    }

    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        totalSum = (totalSum - A[i] + MOD) % MOD;
        answer = (answer + A[i] * totalSum) % MOD;
    }

    cout << answer << "\n";

    return 0;
}
