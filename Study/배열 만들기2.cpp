#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r)
{
    vector<int> answer;
    string Num = "";
    bool isCheck = false;

    for (int i = l; i <= r; i++)
    {
        if (0 == (i % 10) || 5 == (i % 10))
        {
            Num = to_string(i);
            for (int j = 0; j < Num.length(); j++)
            {
                if ('0' == Num[j] || '5' == Num[j])
                    isCheck = true;
                else
                {
                    isCheck = false;
                    break;
                }
            }
            if (isCheck)
                answer.push_back(i);
        }
    }
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}