#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int board[1003][3];
int dp[1003][3];
int answer = 2e9;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cin >> board[i][j];
        }
    }
    
    for (int first = 0; first < 3; first++) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (i == first) 
            {
                dp[0][i] = board[0][i];
            }
            else 
            {
                dp[0][i] = 1e9;
            }
        }

        for (int i = 1; i < N; i++) 
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + board[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + board[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + board[i][2];
        }

        for (int i = 0; i < 3; i++) 
        {
            if (i == first) continue;
            answer = min(answer, dp[N-1][i]);
        }

    }
    
    cout << answer;
   
    return 0;
}