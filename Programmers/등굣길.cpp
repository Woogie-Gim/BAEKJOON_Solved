#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < puddles.size(); i++) 
    {
        int p_m = puddles[i][0];
        int p_n = puddles[i][1];
        dp[p_n][p_m] = -1;
    }
    
    dp[1][1] = 1;
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (i == 1 && j == 1) 
            {
                continue;
            }
            
            if (dp[i][j] == -1) 
            {
                dp[i][j] = 0;
                continue;
            }
            
            int from_up = dp[i - 1][j];
            int from_left = dp[i][j - 1];
            
            dp[i][j] = (from_up + from_left) % 1000000007;
        }
    }
    
    return dp[n][m];
}