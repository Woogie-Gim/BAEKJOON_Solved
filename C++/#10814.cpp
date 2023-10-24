#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, string>> v;

bool comp(pair<int, string> v1, pair<int, string> v2)
{
	return v1.first < v2.first;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		string str;
		cin >> a >> str;

		v.push_back({ a, str });
	}

	stable_sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}