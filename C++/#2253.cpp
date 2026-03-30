#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State
{
    int pos;
    int v;
    int dist;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector<bool> broken(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        broken[x] = true;
    }

    if (broken[2])
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<vector<bool>> visited(N + 1, vector<bool>(150, false));
    queue<State> q;

    q.push({2, 1, 1});
    visited[2][1] = true;

    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        if (curr.pos == N)
        {
            cout << curr.dist << "\n";
            return 0;
        }

        for (int dv = -1; dv <= 1; dv++)
        {
            int nv = curr.v + dv;
            if (nv < 1)
            {
                continue;
            }

            int npos = curr.pos + nv;
            if (npos <= N && !broken[npos])
            {
                if (nv < 150 && !visited[npos][nv])
                {
                    visited[npos][nv] = true;
                    q.push({npos, nv, curr.dist + 1});
                }
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}