#include <iostream>
#include <algorithm>
 
using namespace std;

int n;
int egg[8][2];
int ans = 0;
 
void dfs(int idx) 
{
	if (idx >= n) 
    {
		int cnt = 0;
        
		for (int i = 0; i < n; i++) 
        {
			if (egg[i][0] <= 0) cnt++;
		}
        
		if (cnt > ans) ans = cnt;
		return;
	}
 
	if (egg[idx][0] <= 0) dfs(idx + 1);
 
	else 
    {
		bool check = false;
		for (int i = 0; i < n; i++) 
        {
			if (idx == i || egg[i][0] <= 0) continue;
 
			egg[i][0] -= egg[idx][1];
			egg[idx][0] -= egg[i][1];
			check = true;
			dfs(idx + 1);
			egg[i][0] += egg[idx][1];
			egg[idx][0] += egg[i][1];
 
		}
		if (!check) dfs(n);
	}
}
 
int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
    {
		cin >> egg[i][0] >> egg[i][1];
	}
 
	dfs(0);
	cout << ans;
}