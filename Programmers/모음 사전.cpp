#include <string>
#include <vector>

using namespace std;

void dfs(string current, string target, int& count, int& answer) 
{
    if (current == target) 
    {
        answer = count;
        return;
    }
    
    if (current.length() == 5) 
    {
        return;
    }
    
    char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    
    for (int i = 0; i < 5; i++) 
    {
        if (answer != 0) 
        {
            break;
        }
        
        count++;
        dfs(current + vowels[i], target, count, answer);
    }
}

int solution(string word) 
{
    int count = 0;
    int answer = 0;
    
    dfs("", word, count, answer);
    
    return answer;
}