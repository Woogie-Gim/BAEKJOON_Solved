#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    if (!(cin >> S))
    {
        return 0;
    }

    int len = S.length();

    if (len == 4)
    {
        cout << 20 << "\n";
    }
    else if (len == 3)
    {
        if (S[1] == '0')
        {
            int B = S[2] - '0';
            cout << 10 + B << "\n";
        }
        else
        {
            int A = S[0] - '0';
            cout << A + 10 << "\n";
        }
    }
    else if (len == 2)
    {
        int A = S[0] - '0';
        int B = S[1] - '0';
        cout << A + B << "\n";
    }

    return 0;
}