#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (a == 60 && b == 60 && c == 60)
	{
		cout << "Equilateral";
	}
	else if (a + b + c == 180 && (a == b || b == c || c == a))
	{
		cout << "Isosceles";
	}
	else if (a + b + c == 180 && a != b && b != c && c != a)
	{
		cout << "Scalene";
	}
	else if (a + b + c != 180)
	{
		cout << "Error";
	}

	return 0;
}