#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    stack<int> St;
    int size = s.size();
    char c;
    int num, num2;
    for(int i = 0; i<size; ++i)
    {
        c = s[i];
        if(c == '+')
        {
            num = St.top(); St.pop();
            num += St.top(); St.pop();
            St.push(num);
        }
        else if(c == '-')
        {
            num = St.top(); St.pop();
            num -= St.top(); St.pop();
            St.push(-num);
        }
        else if(c == '*')
        {
            num = St.top(); St.pop();
            num *= St.top(); St.pop();
            St.push(num);
        }
        else if(c == '/')
        {
            num2 = St.top(); St.pop();
            num = St.top(); St.pop();
            St.push(num/num2);
        }
        else
        {
            num = c - '0';
            St.push(num);
        }
    }
    cout << St.top();
}