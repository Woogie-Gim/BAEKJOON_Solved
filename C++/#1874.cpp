#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main() {
    int num[100002];
    int n;
    string result = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int cnt = 0;
    int next = 1;
    stack<int> st;
    bool flag = true;
    while (flag) 
    {
        if (st.empty()) 
        { 
            if (num[cnt] < next) 
            {
                cout << "NO";
                return 0;
            }
            st.push(next);
            result += "+";
            next++;
        }
        else if (num[cnt] > st.top())
        {
            if (num[cnt] < next) 
            { 
                cout << "NO";
                return 0;
            }
            st.push(next);
            next++;
            result += "+";
        }
        else if (num[cnt] < st.top()) 
        {
            st.pop();
            result += "-";
        }
        else if (num[cnt] == st.top()) 
        { 
            result += "-";
            st.pop();
            cnt++;
            if (cnt == n) 
            { 
                flag = false;
            }
        }
    }
    for (int i = 0; i < result.length(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}
