#include <iostream>
#include <vector>

using namespace std;

int n;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
    
	vector <int> v(n), d;

	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < n - 1; i++)
    {
		d.push_back(v[i + 1] - v[i]);        
    }

	int g = d[0];
    
	for (int i = 0; i < d.size(); i++)
    {
		g = gcd(g, d[i]);     
    }

	int dist = v[n - 1] - v[0];
	int ans = dist / g;
	ans -= n - 1;

	cout << ans;

	return 0;
}