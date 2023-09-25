#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		char v[100000];
		cin >> v;
		

		if (v[0] == '0' && v[1] == '\0')
		{
			break;
		}

		int length = 0;
		for (int x = 0; x < 100000; x++)
		{
			if (v[x] == '\0')
			{
				break;
			}

			length++;
		}

		int flag = 1;
		for (int x = 0; x < length; x++)
		{
			if (v[x] != v[length - 1 - x])
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}

	return 0;
}