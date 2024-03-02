#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
bool visited[100001] = {false};
int result[100001] = {0};
int cnt = 0;

void dfs(int R)
{
    if (visited[R])
    {
        return;
    }
    visited[R] = true;
    cnt++;
    result[R] = cnt;
    for (int i = 0; i < graph[R].size(); i++)
    {
        dfs(graph[R][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N, M, R, tempX, tempY;
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++)
    {
        cin >> tempX >> tempY;
        graph[tempX].push_back(tempY);
        graph[tempY].push_back(tempX);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    dfs(R);

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }
}