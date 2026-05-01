#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    vector<int> days;

    for (int i = 0; i < progresses.size(); i++) 
    {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];
        if (remain % speeds[i] != 0) 
        {
            day += 1;
        }
        days.push_back(day);
    }

    int max_day = days[0];
    int count = 1;

    for (int i = 1; i < days.size(); i++) 
    {
        if (days[i] <= max_day) 
        {
            count++;
        } 
        else 
        {
            answer.push_back(count);
            count = 1;
            max_day = days[i];
        }
    }
    answer.push_back(count);

    return answer;
}