#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int E, L, B;
    cin >> E >> L >> B;

    vector<bool> is_cow(E + 1, false);
    for (int i = 0; i < B; i++)
    {
        int pos;
        cin >> pos;
        is_cow[pos] = true;
    }

    vector<int> dist(E + 1, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == E)
        {
            cout << dist[E];
            return 0;
        }

        for (int leap = 1; leap <= L; leap++)
        {
            int next = curr + leap;

            if (next > E)
            {
                continue;
            }

            if (is_cow[next])
            {
                continue;
            }

            if (dist[next] != -1)
            {
                continue;
            }

            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }

    return 0;
}