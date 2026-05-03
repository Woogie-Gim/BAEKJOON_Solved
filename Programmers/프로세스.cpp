#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    queue<int> q;
    vector<int> sorted_priorities = priorities;
    
    sort(sorted_priorities.begin(), sorted_priorities.end(), greater<int>());
    
    for (int i = 0; i < priorities.size(); i++) 
    {
        q.push(i);
    }
    
    int max_idx = 0;
    int answer = 1;
    
    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();
        
        if (priorities[curr] == sorted_priorities[max_idx]) 
        {
            if (curr == location) 
            {
                return answer;
            }
            answer++;
            max_idx++;
        } 
        else 
        {
            q.push(curr);
        }
    }
    
    return answer;
}