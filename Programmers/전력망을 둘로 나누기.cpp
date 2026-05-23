#include <string>
#include <vector>
#include <queue>

using namespace std;

int get_component_size(int start, int ignore_u, int ignore_v, int n, const vector<vector<int>>& graph) 
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();
        count++;
        
        for (int i = 0; i < graph[curr].size(); i++) 
        {
            int next = graph[curr][i];
            
            if ((curr == ignore_u && next == ignore_v) || (curr == ignore_v && next == ignore_u)) 
            {
                continue;
            }
            
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) 
{
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < wires.size(); i++) 
    {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    int answer = n;
    
    for (int i = 0; i < wires.size(); i++) 
    {
        int u = wires[i][0];
        int v = wires[i][1];
        
        int c1 = get_component_size(u, u, v, n, graph);
        int c2 = n - c1;
        
        int diff = 0;
        if (c1 > c2) 
        {
            diff = c1 - c2;
        } 
        else 
        {
            diff = c2 - c1;
        }
        
        if (diff < answer) 
        {
            answer = diff;
        }
    }
    
    return answer;
}
