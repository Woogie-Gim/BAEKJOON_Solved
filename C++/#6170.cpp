#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long dp[46];
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= 45; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;

        cout << "Scenario #" << tc << ":\n";
        cout << dp[n] << "\n\n";
    }

    return 0;
}
