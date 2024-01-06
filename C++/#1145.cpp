#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	int k = 1;
	while (1)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (k % v[i] == 0) cnt += 1;
		}

		if (cnt >= 3)
		{
			cout << k;
			break;
		}

		k++;
	}

	return 0;
}