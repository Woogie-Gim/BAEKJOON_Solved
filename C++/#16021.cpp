#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector< vector<int> > graph(N + 1);
    vector<int> isEnding(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        int m;
        cin >> m;

        if (m == 0)
        {
            isEnding[i] = 1;
        }

        for (int j = 0; j < m; j++)
        {
            int nextPage;
            cin >> nextPage;
            graph[i].push_back(nextPage);
        }
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[cur].size(); i++)
        {
            int nxt = graph[cur][i];
            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    int visitedCount = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] != -1)
        {
            visitedCount++;
        }
    }

    if (visitedCount == N)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "N\n";
    }

    int bestEdgeDist = -1;
    for (int i = 1; i <= N; i++)
    {
        if (isEnding[i] == 1 && dist[i] != -1)
        {
            if (bestEdgeDist == -1 || dist[i] < bestEdgeDist)
            {
                bestEdgeDist = dist[i];
            }
        }
    }

    cout << (bestEdgeDist + 1) << "\n";

    return 0;
}
