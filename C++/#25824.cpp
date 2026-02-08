#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int adj[12][12];
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cin >> adj[i][j];
        }
    }

    int last_node_1 = 1;
    int current_cost_1 = adj[0][1];

    int last_node_2 = 0;
    int current_cost_2 = adj[1][0];

    for (int group = 1; group < 6; group++)
    {
        int u = 2 * group;
        int v = 2 * group + 1;

        int cost_enter_v_from_1 = current_cost_1 + adj[last_node_1][v];
        int cost_enter_v_from_2 = current_cost_2 + adj[last_node_2][v];
        int min_entry_v = min(cost_enter_v_from_1, cost_enter_v_from_2);
        int new_cost_u = min_entry_v + adj[v][u];

        int cost_enter_u_from_1 = current_cost_1 + adj[last_node_1][u];
        int cost_enter_u_from_2 = current_cost_2 + adj[last_node_2][u];
        int min_entry_u = min(cost_enter_u_from_1, cost_enter_u_from_2);
        int new_cost_v = min_entry_u + adj[u][v];

        last_node_1 = v;
        current_cost_1 = new_cost_v;

        last_node_2 = u;
        current_cost_2 = new_cost_u;
    }

    cout << min(current_cost_1, current_cost_2);

    return 0;
}