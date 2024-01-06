// 완전 탐색
#include <iostream>

using namespace std;

int a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	for (int i = -1000; i <= 1000; i++)
	{
		if ((i * i) + (2 * a * i) + b == 0)
		{
			cout << i << ' ';
		}
	}

	return 0;
}

// 짝수 공식

#include <iostream>
#include <cmath>
using namespace std;

int a, b;

int main() 
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	// 짝수공식
	int x = -a + sqrt(a * a - b);
	int y = -a - sqrt(a * a - b);

	if (x == y) cout << x;
	else cout << y << " " << x;

	return 0;
}