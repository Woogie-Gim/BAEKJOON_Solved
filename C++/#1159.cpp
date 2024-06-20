#include <iostream>
#include <string>

using namespace std;

int n;
int cnt[26];
string ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		
		cin >> str;
		cnt[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			ret += char(i + 'a');
		}
	}

	if (ret.size()) cout << ret << "\n";
	else cout << "PREDAJA" << "\n";

	return 0;
}