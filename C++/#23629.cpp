#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    if (!(cin >> s))
    {
        return 0;
    }

    string words[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    int i = 0;
    string decoded_expr = "";
    vector<long long> nums;
    vector<char> ops;
    long long current_num = -1;

    while (i < s.length())
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == '/' || s[i] == '=')
        {
            if (current_num == -1)
            {
                cout << "Madness!\n";
                return 0;
            }
            nums.push_back(current_num);
            ops.push_back(s[i]);
            decoded_expr += s[i];
            current_num = -1;
            i++;
        }
        else
        {
            bool matched = false;
            for (int d = 0; d < 10; d++)
            {
                if (s.substr(i, words[d].length()) == words[d])
                {
                    if (current_num == -1)
                    {
                        current_num = d;
                    }
                    else
                    {
                        current_num = current_num * 10 + d;
                    }
                    decoded_expr += to_string(d);
                    i += words[d].length();
                    matched = true;
                    break;
                }
            }
            if (!matched)
            {
                cout << "Madness!\n";
                return 0;
            }
        }
    }

    if (current_num != -1 || ops.empty() || ops.back() != '=')
    {
        cout << "Madness!\n";
        return 0;
    }

    long long res = nums[0];
    for (int j = 0; j < (int)ops.size() - 1; j++)
    {
        if (ops[j] == '+')
        {
            res += nums[j + 1];
        }
        else if (ops[j] == '-')
        {
            res -= nums[j + 1];
        }
        else if (ops[j] == 'x')
        {
            res *= nums[j + 1];
        }
        else if (ops[j] == '/')
        {
            res /= nums[j + 1];
        }
    }

    cout << decoded_expr << "\n";
    if (res < 0)
    {
        cout << "-";
        res = -res;
    }
    
    if (res == 0)
    {
        cout << "ZERO\n";
    }
    else
    {
        string res_str = to_string(res);
        for (char c : res_str)
        {
            cout << words[c - '0'];
        }
        cout << "\n";
    }

    return 0;
}