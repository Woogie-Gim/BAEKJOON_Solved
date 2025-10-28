#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    while (cin >> k >> n)
    {
        long double dp[101][11] = {0.0L};

        for (int i = 0; i <= k; ++i)
        {
            dp[1][i] = 1.0L;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i <= k; ++i)
            {
                dp[len][i] = dp[len - 1][i];
                if (i > 0)
                {
                    dp[len][i] += dp[len - 1][i - 1];
                }
                if (i < k)
                {
                    dp[len][i] += dp[len - 1][i + 1];
                }
            }
        }

        long double tightCount = 0.0L;
        for (int i = 0; i <= k; ++i)
        {
            tightCount += dp[n][i];
        }

        long double totalCount = powl(k + 1.0L, n);
        long double percentage = (tightCount / totalCount) * 100.0L;

        cout << fixed << setprecision(5) << percentage << '\n';
    }

    return 0;
}
