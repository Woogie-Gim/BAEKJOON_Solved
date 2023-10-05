#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
int res;
int p[27];

void dfs(int idx, string cur) 
{

	if (idx == str.size()) 
	{
		res++;
		return;
	}

	for (int i = 0; i < 26; i++) 
	{
		if (p[i] == 0) continue;
		if (cur != "" && cur[cur.size() - 1] == (char)('a' + i)) continue;
		p[i]--;
		dfs(idx + 1, cur + (char)('a' + i));
		p[i]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> str;
	for (int i = 0; i < str.size(); i++)
		p[str[i] - 'a']++;

	dfs(0, "");

	cout << res;

	return 0;
}