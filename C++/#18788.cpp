#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long K;
    cin >> N >> K;

    int A1, A2, B1, B2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;

    vector<int> cur(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cur[i] = i;
    }

    reverse(cur.begin() + A1, cur.begin() + A2 + 1);
    reverse(cur.begin() + B1, cur.begin() + B2 + 1);

    vector<int> p(N + 1);
    
    for (int i = 1; i <= N; i++)
    {
        p[cur[i]] = i;
    }

    vector<int> result(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
        {
            continue;
        }

        vector<int> cycle;
        int x = i;

        while (!visited[x])
        {
            visited[x] = true;
            cycle.push_back(x);
            x = p[x];
        }

        int L = cycle.size();
        for (int j = 0; j < L; j++)
        {
            int nextIndex = (j + K % L) % L;
            result[cycle[nextIndex]] = cycle[j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}
