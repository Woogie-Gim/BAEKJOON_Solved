#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;
    
	int dp[41] = { 1,1,2 };
    
	for (int i = 3; i <= 40; i++) 
    {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
    
	int idx = 1;
	int answer = 1;
	
	for (int i = 0; i < m; i++) 
    {
		int vip;
		cin >> vip;
		answer *= dp[vip - idx];
		idx = vip + 1;
	}
    
	answer *= dp[n+1 - idx];
	
	cout << answer;
    
	return 0;
}