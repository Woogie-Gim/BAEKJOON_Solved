#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) 
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) 
{
    sort(routes.begin(), routes.end(), compare);
    
    int answer = 0;
    int camera_position = -30001;
    
    for (int i = 0; i < routes.size(); i++) 
    {
        int entry = routes[i][0];
        int exit = routes[i][1];
        
        if (entry > camera_position) 
        {
            answer++;
            camera_position = exit;
        }
    }
    
    return answer;
}