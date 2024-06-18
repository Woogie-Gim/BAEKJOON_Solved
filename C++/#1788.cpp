#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	if (N > 0)
    {
		int x = 0, y = 1;
		while (N--) 
        {
			int tmp = x + y;
			if (tmp > 999999999) tmp -= 1000000000;
			x = y; y = tmp;
		}
		
		if (x > 0) cout << 1 << '\n';
		else if (x < 0) cout << -1 << '\n';
		else cout << 0 << '\n';

		cout << x;
	}
	else if (N < 0)
    {
		int x = 0, y = 1;
		while (N++)
        {
			int tmp = x - y;
			if (tmp > 999999999) tmp -= 1000000000;
			else if (tmp < -999999999) tmp += 1000000000;
			x = y; y = tmp;
		}

		if (x > 0) cout << 1 << '\n';
		else if (x < 0) cout << -1 << '\n';
		else cout << 0 << '\n';

		cout << abs(x);
	}
	else cout << 0 << '\n' << 0;
}