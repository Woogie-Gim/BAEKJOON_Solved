#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int vect[26] = {};

	int len = s.length();

	for (int x = 0; x < len; x++)
	{
		vect[(char)((int)(s[x]) - 'a')]++;
	}

	for (int x = 0; x < 26; x++)
	{
		cout << vect[x] << " ";
	}

	return 0;
}