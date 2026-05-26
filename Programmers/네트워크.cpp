#include <string>
#include <vector>

using namespace std;

void dfs(int current, int n, vector<vector<int>>& computers, vector<bool>& visited) 
{
    visited[current] = true;
    
    for (int i = 0; i < n; i++) 
    {
        if (computers[current][i] == 1 && !visited[i]) 
        {
            dfs(i, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            answer++;
            dfs(i, n, computers, visited);
        }
    }
    
    return answer;
}