#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, P;
    cin >> N >> M >> P;

    vector<int> fav(N + 1), hate(N + 1);
    
    for (int i = 1; i <= N; i++)
    {
        cin >> fav[i] >> hate[i];
    }

    vector<int> next(M + 1, -1);

    for (int i = 1; i <= N; i++)
    {
        int h = hate[i];
        if (next[h] == -1)
        {
            next[h] = fav[i];
        }
    }

    vector<bool> visited(M + 1, false);
    int cnt = 0;
    int cur = P;

    while (true)
    {
        if (next[cur] == -1)
        {
            cout << cnt << "\n";
            return 0;
        }

        if (visited[cur])
        {
            cout << -1 << "\n";
            return 0;
        }

        visited[cur] = true;
        cur = next[cur];
        cnt++;
    }

    return 0;
}
