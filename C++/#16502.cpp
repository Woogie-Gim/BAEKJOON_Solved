#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

int t, m;
double res[4];
vector<pair<int, double>> adj[4];

void dfs(int now, double p, int cnt)
{
    if (cnt == t)
    {
        res[now] += p * 100;
        return;
    }

    for (int i = 0; i < adj[now].size(); ++i)
    {
        int next = adj[now][i].first;
        double prob = adj[now][i].second;
        dfs(next, p * prob, cnt + 1);
    }
}

int main()
{
    cin >> t >> m;

    for (int i = 0; i < m; ++i)
    {
        char s, e;
        double p;
        cin >> s >> e >> p;
        int from = s - 'A';
        int to = e - 'A';
        adj[from].push_back(make_pair(to, p));
    }

    for (int i = 0; i < 4; ++i)
    {
        dfs(i, 0.25, 0);
    }

    cout << fixed << setprecision(3);
    for (int i = 0; i < 4; ++i)
    {
        cout << res[i] << '\n';
    }

    return 0;
}
