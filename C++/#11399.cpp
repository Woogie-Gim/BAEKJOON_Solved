#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[1001];

	for (int x = 0; x < n; x++)
	{
		int a;
		cin >> a;
		arr[x] = a;
	}

	sort(arr, arr + n);

	int sum = 0;

	for (int x = 0; x < n; x++)
	{
		sum += arr[x] * (n - x);
	}

	cout << sum << "\n";

	return 0;
}