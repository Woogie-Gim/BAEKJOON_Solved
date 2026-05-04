#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<int> q;
    
    for (int i = 0; i < bridge_length; i++) 
    {
        q.push(0);
    }
    
    int current_weight = 0;
    int truck_idx = 0;
    
    while (truck_idx < truck_weights.size()) 
    {
        answer++;
        
        current_weight -= q.front();
        q.pop();
        
        if (current_weight + truck_weights[truck_idx] <= weight) 
        {
            q.push(truck_weights[truck_idx]);
            current_weight += truck_weights[truck_idx];
            truck_idx++;
        } 
        else 
        {
            q.push(0);
        }
    }
    
    answer += bridge_length;
    
    return answer;
}