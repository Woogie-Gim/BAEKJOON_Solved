#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<bool> used(n, false);
    string left_part = "";
    string right_part = "";
    string mid_part = "";

    for (int i = 0; i < n; i++)
    {
        if (used[i])
        {
            continue;
        }

        string rev = s[i];
        reverse(rev.begin(), rev.end());

        for (int j = i + 1; j < n; j++)
        {
            if (!used[j] && s[j] == rev)
            {
                left_part += s[i];
                right_part = s[j] + right_part;
                used[i] = true;
                used[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            string rev = s[i];
            reverse(rev.begin(), rev.end());
            if (s[i] == rev)
            {
                mid_part = s[i];
                break;
            }
        }
    }

    string ans = left_part + mid_part + right_part;
    
    cout << ans.length() << "\n";
    cout << ans << "\n";

    return 0;
}