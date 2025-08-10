#include <iostream>

using namespace std;

int P;
int sieve[10001];
int hap[10001];

int dfs(int cur) 
{
	hap[cur] = 2;
    
	int tmp = cur, nxt = 0;
    
	while (tmp)
    {
		nxt += (tmp % 10) * (tmp % 10);
		tmp /= 10;
	}

	if (hap[nxt]) return hap[cur] = hap[nxt];
	else return hap[cur] = dfs(nxt);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sieve[1] = 1;
    
	for (int i = 2; i < 10001; i++)
    {
		if (sieve[i]) continue;
		for (int j = i * i; j < 10001; j += i) sieve[j] = 1;
	}

	hap[1] = 1;
    
	for (int i = 2; i < 10001; i++) 
    {
		if (hap[i]) continue;
		dfs(i);
	}

	cin >> P;
    
	while (P--) 
    {
		int T, x; cin >> T >> x;
		if (hap[x] < 2 && !sieve[x]) cout << T << ' ' << x << " YES\n";
		else cout << T << ' ' << x << " NO\n";
	}
}