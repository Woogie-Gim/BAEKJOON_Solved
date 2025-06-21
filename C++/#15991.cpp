#include <iostream>

using namespace std;

int T, n;
long long dp[100001] = { 0,1,2,2,3,3,6, };

void solution() 
{
    for (int i = 7; i <= n; i++) 
    {
        dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
    }

    cout << dp[n] << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin >> T;

    while(T--) 
    {
        cin >> n;

        solution();
    }
    
    return 0;
}