#include <iostream>

using namespace std;

int main()
{
	int num[9];
	int sum = 0;
	int a, b;

	for (int i = 0; i < 9; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (num[i] + num[j]) == 100)
			{
				a = i; b = j;
			}
		}
	}

	for (int k = 0; k < 9; k++)
	{
		if (k == a || k == b)
			continue;
		else
			cout << num[k] << "\n";
	}
	return 0;
}