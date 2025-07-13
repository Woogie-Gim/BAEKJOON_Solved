#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string code;
string loc_code;
string bir_code;
string ord_code;
vector<string> loc_codes;
int m_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

char check()
{
    bool found = false;
    for (const string& loc : loc_codes)
    {
        if (loc_code == loc)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        return 'I';
    }

    int Y = stoi(bir_code.substr(0, 4));
    int M = stoi(bir_code.substr(4, 2));
    int D = stoi(bir_code.substr(6, 2));

    if (Y < 1900 || Y > 2011)
    {
        return 'I';
    }

    bool isLeap = false;
    if (M == 2)
    {
        if (Y % 4 == 0)
        {
            if (Y % 100 == 0)
            {
                if (Y % 400 == 0)
                {
                    isLeap = true;
                }
            }
            else
            {
                isLeap = true;
            }
        }
    }

    if (M < 1 || M > 12)
    {
        return 'I';
    }

    if (D < 1 || D > m_day[M] + (isLeap ? 1 : 0))
    {
        return 'I';
    }

    if (ord_code == "000")
    {
        return 'I';
    }

    int sum_code = 0;
    for (int i = 0; i < 17; ++i)
    {
        sum_code += ( (code[i] - '0') * ((int)pow(2, 17 - i)) ) % 11;
    }

    int check_sum = (code[17] == 'X') ? 10 : (code[17] - '0');

    if ((sum_code + check_sum) % 11 == 1)
    {
        if ((stoi(ord_code) % 2) == 1)
        {
            return 'M';
        }
        else
        {
            return 'F';
        }
    }
    else
    {
        return 'I';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> code;

    int n;
    cin >> n;

    loc_codes.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> loc_codes[i];
    }

    loc_code = code.substr(0, 6);
    bir_code = code.substr(6, 8);
    ord_code = code.substr(14, 3);

    cout << check() << '\n';

    return 0;
}
