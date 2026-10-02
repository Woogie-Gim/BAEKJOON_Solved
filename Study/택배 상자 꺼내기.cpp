#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int col = ceil(double(n) / w);
    vector<vector<int>> v (col, vector<int> (w, 0));
    
    int digit = 1;
    int pos1 = 0;
    int pos2 = 0;
    for(int i = 0; i < col; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < w && digit <= n; j++)
            {
                v[i][j] = digit;
                if(digit == num)
                {
                    pos1 = i;
                    pos2 = j;
                }
                digit++;
            }
        }
        else
        {
            for(int j = w - 1; j >= 0 && digit <= n; j--)
            {
                v[i][j] = digit;
                if(digit == num)
                {
                    pos1 = i;
                    pos2 = j;
                }
                digit++;
            }
        }
    }
    
    for(int i = pos1; i < col; i++)
    {
        if(v[i][pos2] != 0) answer++;
    }

    
    return answer;
}