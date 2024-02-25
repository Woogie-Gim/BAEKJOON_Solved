#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
    
	cin>>s;
    
	int max = -1;
	int cnt = 0;
	int alpha[26] = {0, };
	int c;
    
	transform(s.begin(), s.end(), s.begin(), (int(*)(int))toupper);
	for(int i = 0; i < s.length(); i++) alpha[s[i] - 'A']++;
    
	for(int i = 0; i < 26; i++)
	{
		if(max < alpha[i])
		{
			max = alpha[i];
			c = i;
			cnt = 0;
		}
		if(max == alpha[i]) cnt++;
	}
	if(cnt > 1) cout << "?";
	else cout<< (char)(c + 'A');
}