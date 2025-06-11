#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	if (next_permutation(s.begin(), s.end())) cout << s;
	else cout << 0;
}