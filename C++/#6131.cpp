#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int b = 1; b <= 500; b++)
	{
		for (int a = b + 1; a <= 500; a++)
		{
			if (b * b + n == a * a) v.push_back({ a,b });
		}
	}

	cout << v.size() << "\n";

	return 0;
}