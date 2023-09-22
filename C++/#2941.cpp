#include <iostream>
#include <string>
using namespace std;

string arr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main()
{
	string str;
	cin >> str;


	int idx;
	for (int x = 0; x < 8; x++)
	{
		while (1)
		{
			idx = str.find(arr[x]);
			if (idx == -1)
			{
				break;
			}
			
			str.replace(idx, arr[x].length(), "a");
		}

	}

	cout << str.length();
}