#include <iostream>

using namespace std;

int arr[10];
int sum = 0;

int main() 
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++) 
	{

		if (abs(100 - sum) >= abs(100 - (sum + arr[i])))
		{
			sum += arr[i];
		}

		else break;
	}
	cout << sum << "\n";

	return 0;
}