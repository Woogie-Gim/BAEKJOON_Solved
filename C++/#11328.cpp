#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int strfry(string st1, string st2)
{
	int len = st1.length();
	int len2 = st2.length();
	if (len != len2)
	{
		return 0;
	}

	std::sort(st1.begin(), st1.end());
	std::sort(st2.begin(), st2.end());

	for (int x = 0; x < len; x++)
	{
		if (st1[x] != st2[x])
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int a;
	cin >> a;

	for (int x = 0; x < a; x++)
	{
		string a, b;
		cin >> a >> b;
		
		int ret = strfry(a, b);

		if (ret)
		{
			cout << "Possible" << "\n";
		}
		else
		{
			cout << "Impossible" << "\n";
		}
	}

	return 0;
}