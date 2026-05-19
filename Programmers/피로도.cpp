#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = 0;
    vector<int> order;
    
    for (int i = 0; i < dungeons.size(); i++) 
    {
        order.push_back(i);
    }
    
    do 
    {
        int current_k = k;
        int count = 0;
        
        for (int i = 0; i < order.size(); i++) 
        {
            int dungeon_idx = order[i];
            int required_k = dungeons[dungeon_idx][0];
            int consumed_k = dungeons[dungeon_idx][1];
            
            if (current_k >= required_k) 
            {
                current_k -= consumed_k;
                count++;
            } 
            else 
            {
                break;
            }
        }
        
        if (count > answer) 
        {
            answer = count;
        }
        
    } while (next_permutation(order.begin(), order.end()));
    
    return answer;
}