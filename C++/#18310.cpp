#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	// 오름차순으로 정렬
	sort(v.begin(), v.end());

	// n이 짝수 일 때 중앙 두 값 중 아무 곳이나 선택
	// n이 홀수 일 때 중앙 값 선택
	// vector의 index 값이므로 n을 2로 나눈 index 값을 출력
	// 짝수일 경우 중앙 값 중 작은 값을 출력
	if (n % 2)
	{
		cout << v[n / 2] << "\n";
	}
	else
	{
		cout << v[(n / 2) - 1] << "\n";
	}

	return 0;
}