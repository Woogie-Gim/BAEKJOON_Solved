#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			s.pop();
		}
		else
		{
			s.push(n);
		}
	}

	int size = s.size();
	int sum = 0;
	if (size == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			sum += s.top();
			s.pop();
		}

		cout << sum << "\n";
	}


	return 0;
}