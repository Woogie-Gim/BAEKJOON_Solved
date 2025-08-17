#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<char>> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;

	cin >> k;

	string pwd;

	cin >> pwd;

	int col = k;
	int row = pwd.size() / k;

	vector<vector<char>> v(row, vector<char>(col));

	int idx = 0;

	for (int i = 0; i < row; ++i)
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < col; ++j)
			{
				v[i][j] = pwd[idx++];
			}
		}
		else 
		{
			for (int j = col - 1; j >= 0; --j) 
			{
				v[i][j] = pwd[idx++];
			}
		}
	}

	string ans;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			ans += v[j][i];
		}
	}

	cout << ans << "\n";

	return 0;
}