#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int visited[300001];
int main() {

	int N; //도시 수
	int M; //도로의 수
	int K; //거리 정보
	int X; //출발 도시

	cin >> N >> M >> K >> X;

	vector<vector<int>> arr(N+1);
	int input1;
	int input2;
	for (int i = 0; i < M; i++)
	{
		cin >> input1 >> input2;
		arr[input1].push_back(input2);
	}

	vector<int> result; 

	queue<pair<int,int>> q;
	q.push({ X,0 }); //시작지점,깊이 0
	visited[X] = 1;

	while (!q.empty())
	{
		int curNum = q.front().first;
		int curDepth = q.front().second;
		q.pop();


		if (curDepth == K) //거리와 방문 깊이가 같으면 정답
		{
			result.push_back(curNum);
		}
		for (int i = 0; i <(signed)arr[curNum].size(); i++)
		{
			int nextNum = arr[curNum][i];

			if (!visited[nextNum])
			{
				visited[nextNum] = 1;
				q.push({ nextNum,curDepth+1 });
			}
		}
	}

	if (result.size() == 0) //정답 없으면 -1 출력
	{
		cout << -1 << endl;
		return 0;
	}

	sort(result.begin(), result.end()); //정렬

	for (auto a : result)
		cout << a << '\n';
	return 0;
}