#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const bool EMPTY_WITH_SPACE = true; 
    
    auto mul3 = [](const string &s) -> string
    {
        string r;
        r.reserve(s.size() + 1);
        int carry = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            int d = (s[i] - '0') * 3 + carry;
            r.push_back(char('0' + (d % 10)));
            carry = d / 10;
        }
        if (carry)
        {
            r.push_back(char('0' + carry));
        }
        reverse(r.begin(), r.end());
        return r;
    };

    vector<string> pow3(64);
    pow3[0] = "1";
    for (int i = 1; i < 64; ++i)
    {
        pow3[i] = mul3(pow3[i - 1]);
    }

    string nstr;
    while (cin >> nstr)
    {
        if (nstr == "0")
        {
            break;
        }

        unsigned long long n = 0;
        for (char c : nstr)
        {
            n = n * 10 + (unsigned long long)(c - '0');
        }

        unsigned long long k = n - 1;
        vector<string> elems;
        int idx = 0;

        while (k > 0)
        {
            if (k & 1ULL)
            {
                elems.push_back(pow3[idx]);
            }
            k >>= 1ULL;
            ++idx;
        }

        if (elems.empty())
        {
            if (EMPTY_WITH_SPACE)
            {
                cout << "{ }\n";
            }
            else
            {
                cout << "{}\n";
            }
            continue;
        }

        cout << "{ ";
        for (size_t i = 0; i < elems.size(); ++i)
        {
            if (i)
            {
                cout << ", ";
            }
            cout << elems[i];
        }
        cout << " }\n";
    }

    return 0;
}
