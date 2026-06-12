#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    int n = number.length();
    int target_size = n - k;
    
    for (int i = 0; i < n; i++) 
    {
        while (k > 0 && !answer.empty() && answer.back() < number[i]) 
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    
    while (answer.length() > target_size) 
    {
        answer.pop_back();
    }
    
    return answer;
}