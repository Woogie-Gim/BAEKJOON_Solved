#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, char>> vec;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
    
	for (char c = 'a'; c <= 'z'; c++) 
    {
		int cnt = 0;
		for (auto& l : s) 
        {
			if (l == c) cnt++;
		}
		vec.emplace_back(make_pair(-cnt, c));
	}

	sort(vec.begin(), vec.end());
	for (auto& p : vec) 
    {
		while (p.first) 
        {
			cout << p.second;
			p.first++;
		}
	}
}