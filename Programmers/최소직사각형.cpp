#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int max_w = 0;
    int max_h = 0;

    for (int i = 0; i < sizes.size(); i++) 
    {
        int w = sizes[i][0];
        int h = sizes[i][1];

        int longer = max(w, h);
        int shorter = min(w, h);

        if (longer > max_w) 
        {
            max_w = longer;
        }
        if (shorter > max_h) 
        {
            max_h = shorter;
        }
    }

    return max_w * max_h;
}