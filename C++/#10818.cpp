#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

	int arr[1000001];
	for (int x = 0; x < a; x++)
	{
		cin >> arr[x];
	}

	int k;
	k = 21e8;
	for (int x = 0; x < a; x++)
	{
		if (k > arr[x])
		{
			k = arr[x];
		}
	}

	int t;
	t = -21e8;
	for (int x = 0; x < a; x++)
	{
		if (t < arr[x])
		{
			t = arr[x];
		}
	}

	cout << k << " " << t;

	return 0;
}
