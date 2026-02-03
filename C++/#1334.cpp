#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int len = s.length();
    bool all_nine = true;

    for (int i = 0; i < len; i++)
    {
        if (s[i] != '9')
        {
            all_nine = false;
            break;
        }
    }

    if (all_nine)
    {
        cout << '1';
        for (int i = 0; i < len - 1; i++)
        {
            cout << '0';
        }
        cout << '1';
        return 0;
    }

    string temp = s;

    for (int i = 0; i < len / 2; i++)
    {
        temp[len - 1 - i] = temp[i];
    }

    if (temp > s)
    {
        cout << temp;
    }
    else
    {
        for (int i = (len - 1) / 2; i >= 0; i--)
        {
            if (temp[i] != '9')
            {
                temp[i]++;
                break;
            }
            else
            {
                temp[i] = '0';
            }
        }

        for (int i = 0; i < len / 2; i++)
        {
            temp[len - 1 - i] = temp[i];
        }

        cout << temp;
    }

    return 0;
}