#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int best_colors = n + 1;
    vector<int> best_color_assign(n + 1);

    auto start_time = chrono::steady_clock::now();
    mt19937 rng(1337);

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(), [&](int a, int b) {
        return adj[a].size() > adj[b].size();
    });

    vector<int> used(n + 2, 0);
    int color_visit_id = 0;

    while (true)
    {
        auto current_time = chrono::steady_clock::now();
        if (chrono::duration_cast<chrono::milliseconds>(current_time - start_time).count() > 900)
        {
            break;
        }

        vector<int> color(n + 1, 0);
        int max_color = 0;
        
        for (int u : order)
        {
            color_visit_id++;
            for (int v : adj[u])
            {
                if (color[v] != 0)
                {
                    used[color[v]] = color_visit_id;
                }
            }
            
            int c = 1;
            while (used[c] == color_visit_id) c++;
            
            color[u] = c;
            if (c > max_color) max_color = c;
            
            if (max_color >= best_colors) break; 
        }
        
        if (max_color < best_colors)
        {
            best_colors = max_color;
            best_color_assign = color;
        }

        shuffle(order.begin(), order.end(), rng);
    }

    cout << best_colors << "\n";
    vector<vector<int>> teams(best_colors + 1);
    for (int i = 1; i <= n; i++)
    {
        teams[best_color_assign[i]].push_back(i);
    }

    for (int c = 1; c <= best_colors; c++)
    {
        for (int i = 0; i < (int)teams[c].size(); i++)
        {
            cout << teams[c][i] << (i + 1 == (int)teams[c].size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}