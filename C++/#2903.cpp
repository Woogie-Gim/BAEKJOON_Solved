#include <iostream>
#include <cmath>

using namespace std;

int arr[16];

int main()
{
	// 0 -> 4 /2 1 -> 9 /3 (2 + (2 - 1) 2 -> 25 /5 (3 + (3 - 1)) 3 -> 81 /9 (5 + (5 - 1) 4 -> 9 + 8 = 17 * 17 5 -> 1089 /33 = 17 + 16
	arr[0] = 4;

	for (int i = 1; i < 16; i++)
	{
		arr[i] = pow(sqrt(arr[i - 1]) + (sqrt(arr[i - 1]) - 1), 2);
	}

	int k;

	cin >> k;

	cout << arr[k] << "\n";

	return 0;
}