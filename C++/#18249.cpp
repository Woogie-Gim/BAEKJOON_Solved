#include <iostream>

using namespace std;

int dp[10101010] = {1, 1};
const int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int t; 
    cin >> t;
    
    for(int i = 2; i < 10101010; i++) 
    {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    
    while(t--)
    {
        int n; 
        cin >> n;
        
        cout << dp[n] << "\n";
    }
}