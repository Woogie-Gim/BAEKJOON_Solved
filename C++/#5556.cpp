#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q; cin >> N >> Q;
    
	while (Q--)
    {
		int x, y; cin >> x >> y;
        
		cout << (min(min(x, N - x + 1), min(y, N - y + 1)) - 1) % 3 + 1 << '\n';
	}
}