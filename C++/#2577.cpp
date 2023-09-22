#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ans = 1;
	for (int x = 0; x < 3; x++)
	{
		string str;
		cin >> str;
		
		ans *= stoi(str);
	}

	int arr[10] = {};
	string ret = to_string(ans);
	int len = ret.length();
	for (int x = 0; x < len; x++)
	{
		int idx = ret[x] - '0';
		arr[idx]++;
	}

	for (int x = 0; x < 10; x++)
	{
		cout << arr[x] << "\n";
	}

	return 0;
}