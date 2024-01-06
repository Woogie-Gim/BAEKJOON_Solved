#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int cnt = 0;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int k = n - (i + j);
			for (int k = 1; k < n + 1; k++)
			{
				if (i + j + k != n) continue;
				else if (k < j + 2) continue;
				else if (i % 2 == 1) continue;

				cnt += 1;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}