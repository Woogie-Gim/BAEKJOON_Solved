#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isOneLetterDifferent(string a, string b) 
{
    int diff_count = 0;
    for (int i = 0; i < a.length(); i++) 
    {
        if (a[i] != b[i]) 
        {
            diff_count++;
        }
    }
    if (diff_count == 1) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int solution(string begin, string target, vector<string> words) 
{
    bool target_exists = false;
    for (int i = 0; i < words.size(); i++) 
    {
        if (words[i] == target) 
        {
            target_exists = true;
            break;
        }
    }
    
    if (!target_exists) 
    {
        return 0;
    }
    
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    
    q.push(make_pair(begin, 0));
    
    while (!q.empty()) 
    {
        string current_word = q.front().first;
        int current_step = q.front().second;
        q.pop();
        
        if (current_word == target) 
        {
            return current_step;
        }
        
        for (int i = 0; i < words.size(); i++) 
        {
            if (!visited[i] && isOneLetterDifferent(current_word, words[i])) 
            {
                visited[i] = true;
                q.push(make_pair(words[i], current_step + 1));
            }
        }
    }
    
    return 0;
}