#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n;
    if (!(cin >> c >> n))
    {
        return 0;
    }

    vector<int> dp(c + 105, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int cost, cust;
        cin >> cost >> cust;
        
        for (int j = cust; j <= c + 100; j++)
        {
            dp[j] = min(dp[j], dp[j - cust] + cost);
        }
    }

    int min_cost = 1e9;
    for (int i = c; i <= c + 100; i++)
    {
        min_cost = min(min_cost, dp[i]);
    }

    cout << min_cost << "\n";

    return 0;
}