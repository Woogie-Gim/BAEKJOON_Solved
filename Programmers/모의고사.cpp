#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    
    int p1[] = {1, 2, 3, 4, 5};
    int p2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    
    for (int i = 0; i < answers.size(); i++) 
    {
        if (answers[i] == p1[i % 5]) 
        {
            score1++;
        }
        if (answers[i] == p2[i % 8]) 
        {
            score2++;
        }
        if (answers[i] == p3[i % 10]) 
        {
            score3++;
        }
    }
    
    int max_score = max(score1, max(score2, score3));
    
    if (max_score == score1) 
    {
        answer.push_back(1);
    }
    if (max_score == score2) 
    {
        answer.push_back(2);
    }
    if (max_score == score3) 
    {
        answer.push_back(3);
    }
    
    return answer;
}