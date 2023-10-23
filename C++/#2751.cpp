/* 우선순위 큐 풀이 */

#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < n; i++)
	{
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}

/* sort 풀이 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}