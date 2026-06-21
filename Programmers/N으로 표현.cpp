#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) 
{
    if (N == number) 
    {
        return 1;
    }
    
    vector<unordered_set<int>> dp(9);
    
    int base_num = 0;
    for (int i = 1; i <= 8; i++) 
    {
        base_num = base_num * 10 + N;
        dp[i].insert(base_num);
    }
    
    for (int k = 1; k <= 8; k++) 
    {
        for (int i = 1; i < k; i++) 
        {
            int j = k - i;
            
            for (unordered_set<int>::iterator it1 = dp[i].begin(); it1 != dp[i].end(); ++it1) 
            {
                for (unordered_set<int>::iterator it2 = dp[j].begin(); it2 != dp[j].end(); ++it2) 
                {
                    int op1 = *it1;
                    int op2 = *it2;
                    
                    dp[k].insert(op1 + op2);
                    dp[k].insert(op1 - op2);
                    dp[k].insert(op1 * op2);
                    if (op2 != 0) 
                    {
                        dp[k].insert(op1 / op2);
                    }
                }
            }
        }
        
        if (dp[k].count(number) > 0) 
        {
            return k;
        }
    }
    
    return -1;
}