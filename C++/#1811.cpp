#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while (true)
    {
        if (!getline(cin, line))
        {
            break;
        }
        if (line == "#")
        {
            break;
        }
        if (line.empty())
        {
            continue;
        }

        size_t sp = line.find(' ');
        string T = line.substr(0, sp);
        string G = line.substr(sp + 1);

        int n = (int)T.size();

        vector<int> usedT(n, 0), usedG(n, 0);

        int black = 0, grey = 0, white = 0;

        for (int i = 0; i < n; i++)
        {
            if (T[i] == G[i])
            {
                black++;
                usedT[i] = 1;
                usedG[i] = 1;
            }
        }

        auto bipartite_match = [&](const vector<vector<int>> &adj) -> pair<int, vector<int>>
        {
            vector<int> matchR(n, -1);
            int res = 0;

            function<bool(int, vector<int>&)> dfs = [&](int u, vector<int> &vis) -> bool
            {
                for (int v : adj[u])
                {
                    if (vis[v])
                    {
                        continue;
                    }
                    vis[v] = 1;
                    if (matchR[v] == -1 || dfs(matchR[v], vis))
                    {
                        matchR[v] = u;
                        return true;
                    }
                }
                return false;
            };

            for (int u = 0; u < n; u++)
            {
                if (adj[u].empty())
                {
                    continue;
                }
                vector<int> vis(n, 0);
                if (dfs(u, vis))
                {
                    res++;
                }
            }

            return {res, matchR};
        };

        vector<vector<int>> adjGrey(n);
        for (int i = 0; i < n; i++)
        {
            if (usedG[i])
            {
                continue;
            }
            if (i - 1 >= 0 && !usedT[i - 1] && T[i - 1] == G[i])
            {
                adjGrey[i].push_back(i - 1);
            }
            if (i + 1 < n && !usedT[i + 1] && T[i + 1] == G[i])
            {
                adjGrey[i].push_back(i + 1);
            }
        }

        auto mg = bipartite_match(adjGrey);
        grey = mg.first;
        for (int j = 0; j < n; j++)
        {
            if (mg.second[j] != -1)
            {
                usedT[j] = 1;
                usedG[mg.second[j]] = 1;
            }
        }

        vector<vector<int>> adjWhite(n);
        for (int i = 0; i < n; i++)
        {
            if (usedG[i])
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (usedT[j])
                {
                    continue;
                }
                if (T[j] == G[i] && (abs(i - j) >= 2))
                {
                    adjWhite[i].push_back(j);
                }
            }
        }

        auto mw = bipartite_match(adjWhite);
        white = mw.first;

        cout << G << ": " << black << " black, " << grey << " grey, " << white << " white\n";
    }

    return 0;
}
