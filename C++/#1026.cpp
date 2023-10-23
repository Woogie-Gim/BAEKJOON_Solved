/* 우선순위 큐 풀이 */

#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq1.push(a);
	}

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		pq2.push(b);
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += (pq1.top() * pq2.top());
		pq1.pop();
		pq2.pop();
	}

	cout << sum << "\n";

	return 0;
}

/* sort  풀이 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v1;
vector<int> v2;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v1.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		v2.push_back(b);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += (v1[i] * v2[i]);
	}

	cout << sum << "\n";

	return 0;
}