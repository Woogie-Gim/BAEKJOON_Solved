#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;

int binary_search(int target)
{
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (target == arr[mid]) return 1;
		if (target < arr[mid]) end = mid - 1;
		else if (target > arr[mid]) start = mid + 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		cout << binary_search(b) << "\n";
	}

	return 0;
}