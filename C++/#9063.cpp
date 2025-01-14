#include <iostream>

using namespace std;

int k;
int minx = 999999;
int miny = 999999;
int maxx = -999999;
int maxy = -999999;

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;

		if (minx > a) minx = a;
		if (miny > b) miny = b;
		if (maxx < a) maxx = a;
		if (maxy < b) maxy = b;
	}

	cout << (maxx - minx) * (maxy - miny) << "\n";
	
	return 0;
}