#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int n = prices.size();
    vector<int> answer(n);
    stack<int> st;

    for (int i = 0; i < n; i++) 
    {
        while (!st.empty() && prices[st.top()] > prices[i]) 
        {
            int top_idx = st.top();
            st.pop();
            answer[top_idx] = i - top_idx;
        }
        st.push(i);
    }

    while (!st.empty()) 
    {
        int top_idx = st.top();
        st.pop();
        answer[top_idx] = n - 1 - top_idx;
    }

    return answer;
}