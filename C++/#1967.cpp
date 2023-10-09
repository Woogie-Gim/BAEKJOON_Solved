#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> list[10001];
bool c[10001] = { false };

int Dfs(int x) 
{
	if (c[x]) return -1000;
	int sum = 0;
	c[x] = true;
	for (int i = 0; i < list[x].size(); i++) 
    {
		int node = list[x][i].first;
		int value = list[x][i].second;
		sum = max(sum, value + Dfs(node));
	}
	return sum;
}
int main() 
{	
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i < n; i++) 
    {
		int v1, v2, v3;
		cin >> v1 >> v2 >> v3;
		list[v1].push_back(make_pair(v2, v3));
		list[v2].push_back(make_pair(v1, v3));
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) 
    {
		for (int j = 1; j <= n; j++) c[j] = false;
		answer = max(answer,Dfs(i));
	}
	cout << answer;
    
    return 0;
}