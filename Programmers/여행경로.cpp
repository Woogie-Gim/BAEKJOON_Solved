#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string current, const vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& path, vector<string>& answer) 
{
    if (path.size() == tickets.size() + 1) 
    {
        answer = path;
        return true;
    }
    
    for (int i = 0; i < tickets.size(); i++) 
    {
        if (tickets[i][0] == current && !visited[i]) 
        {
            visited[i] = true;
            path.push_back(tickets[i][1]);
            
            if (dfs(tickets[i][1], tickets, visited, path, answer)) 
            {
                return true;
            }
            
            path.pop_back();
            visited[i] = false;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    sort(tickets.begin(), tickets.end());
    
    vector<string> answer;
    vector<string> path;
    vector<bool> visited(tickets.size(), false);
    
    path.push_back("ICN");
    
    dfs("ICN", tickets, visited, path, answer);
    
    return answer;
}