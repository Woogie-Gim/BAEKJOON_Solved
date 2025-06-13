#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	cout << (a + b + c + d) / 60 << "\n";
	cout << (a + b + c + d) % 60 << "\n";

	return 0;
}