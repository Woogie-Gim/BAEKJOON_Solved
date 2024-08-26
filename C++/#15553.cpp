#include <iostream>
#include <queue>

using namespace std;

int N, K;
priority_queue<int> pq;
int A[100000];
int ans;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K; K--;
	for (int i = 0; i < N; i++) cin >> A[i];
	ans = A[N - 1] - A[0] + 1;
	for (int i = 1; i < N; i++) pq.push(A[i] - A[i - 1] - 1);
	
	while (K--) 
    {
		ans -= pq.top();
		pq.pop();
	}

	cout << ans;
}