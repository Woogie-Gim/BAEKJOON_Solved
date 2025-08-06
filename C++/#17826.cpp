#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> rank;
	int idx = 1;

	for (int i = 0; i < 50; i++)
	{
		int score;
		cin >> score;

		rank[score] = idx++;
	}

	int hongikScore;
	cin >> hongikScore;

	int grade = rank[hongikScore];

	if (grade <= 5)
	{
		cout << "A+\n";
	}
	else if (grade <= 15)
	{
		cout << "A0\n";
	}
	else if (grade <= 30)
	{
		cout << "B+\n";
	}
	else if (grade <= 35)
	{
		cout << "B0\n";
	}
	else if (grade <= 45)
	{
		cout << "C+\n";
	}
	else if (grade <= 48)
	{
		cout << "C0\n";
	}
	else
	{
		cout << "F\n";
	}

	return 0;
}