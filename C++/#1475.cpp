#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int bucket[10] = {};

	int len = str.length();
	for (int x = 0; x < len; x++)
	{
		int idx = str[x] - '0';
		bucket[idx]++;
	}

	int set_count = (bucket[6] + bucket[9] + 1) / 2;

	for (int x = 0; x < 10; x++)
	{
		if (x != 6 && x != 9)
		{
			if (set_count < bucket[x])
			{
				set_count = bucket[x];
			}
		}
	}

	cout << set_count;
}