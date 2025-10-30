#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<vector<long long> > prod(N + 2, vector<long long>(N + 2, 1));
    for (int i = 1; i <= N; ++i)
    {
        long long p = 1;
        for (int j = i; j <= N; ++j)
        {
            p *= A[j];
            prod[i][j] = p;
        }
    }

    const int G = 4;
    vector<vector<long long> > dp(N + 2, vector<long long>(G + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        dp[i][1] = prod[i][N];
    }

    for (int g = 2; g <= G; ++g)
    {
        for (int i = 1; i <= N; ++i)
        {
            long long best = 0;
            int lastStart = N - g + 1;
            for (int j = i; j <= lastStart; ++j)
            {
                long long cand = prod[i][j] + dp[j + 1][g - 1];
                if (cand > best)
                {
                    best = cand;
                }
            }
            dp[i][g] = best;
        }
    }

    cout << dp[1][G] << '\n';
    return 0;
}
