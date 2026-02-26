#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    vector<int> visited(2505, 0);
    int visit_mark = 0;

    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        long long ans = 0;

        for (int i = 1; i <= N; i++)
        {
            visit_mark++;
            vector<int> q;
            q.push_back(i);
            visited[i] = visit_mark;

            int head = 0;

            while (head < (int)q.size())
            {
                int curr = q[head++];

                for (int j = 0; j < (int)adj[curr].size(); j++)
                {
                    int next = adj[curr][j];

                    if (visited[next] != visit_mark)
                    {
                        visited[next] = visit_mark;
                        q.push_back(next);
                        ans++;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}