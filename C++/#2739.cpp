#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

	for (int x = 1; x <= 9; x++)
	{
		cout << a << " * " << x << " = " << a * x << "\n";
	}

	return 0;
}