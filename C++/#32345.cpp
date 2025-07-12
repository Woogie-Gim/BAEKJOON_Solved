#include <iostream>

using namespace std;

constexpr int mod = 1e9 + 7;

auto sol = [](auto s) 
{
	int res = 1, p = -1;
	for (int i = 0; i < s.size(); i++)
    {
		if (string("aeiou").find(s[i]) == -1) continue;
		if (p != -1) res = 1LL * res * (i - p) % mod;
		p = i;
	}
	return p < 0 ? -1 : res;
};

int main() 
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n; cin >> n;
    
	while (n--) 
    {
		string s; cin >> s;
		cout << sol(s) << '\n';
	}
}