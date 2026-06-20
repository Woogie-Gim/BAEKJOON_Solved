#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_parent(int node, vector<int>& parent) 
{
    if (parent[node] == node) 
    {
        return node;
    }
    return parent[node] = find_parent(parent[node], parent);
}

void union_parent(int a, int b, vector<int>& parent) 
{
    a = find_parent(a, parent);
    b = find_parent(b, parent);
    if (a < b) 
    {
        parent[b] = a;
    }
    else 
    {
        parent[a] = b;
    }
}

bool compare(vector<int> a, vector<int> b) 
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) 
{
    sort(costs.begin(), costs.end(), compare);
    
    vector<int> parent(n);
    for (int i = 0; i < n; i++) 
    {
        parent[i] = i;
    }
    
    int total_cost = 0;
    int bridge_count = 0;
    
    for (int i = 0; i < costs.size(); i++) 
    {
        if (bridge_count == n - 1) 
        {
            break;
        }
        
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];
        
        if (find_parent(u, parent) != find_parent(v, parent)) 
        {
            union_parent(u, v, parent);
            total_cost += cost;
            bridge_count++;
        }
    }
    
    return total_cost;
}