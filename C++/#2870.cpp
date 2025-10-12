#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<string> nums;
    nums.reserve(N * 2);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        string cur = "";
        for (char ch : s)
        {
            if ('0' <= ch && ch <= '9')
            {
                cur.push_back(ch);
            }
            else
            {
                if (!cur.empty())
                {
                    int p = 0;
                    while (p < (int)cur.size() && cur[p] == '0')
                    {
                        p++;
                    }
                    string t = cur.substr(p);
                    if (t.empty())
                    {
                        t = "0";
                    }
                    nums.push_back(t);
                    cur.clear();
                }
            }
        }
        if (!cur.empty())
        {
            int p = 0;
            while (p < (int)cur.size() && cur[p] == '0')
            {
                p++;
            }
            string t = cur.substr(p);
            if (t.empty())
            {
                t = "0";
            }
            nums.push_back(t);
        }
    }

    auto cmp = [](const string &a, const string &b)
    {
        if (a.size() != b.size())
        {
            return a.size() < b.size();
        }
        return a < b;
    };

    sort(nums.begin(), nums.end(), cmp);

    for (const string &x : nums)
    {
        cout << x << "\n";
    }

    return 0;
}
