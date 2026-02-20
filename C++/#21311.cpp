#include <iostream>
#include <string>

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

    int first_seen[26];
    int count[26];

    for (int i = 0; i < 26; i++)
    {
        first_seen[i] = -1;
        count[i] = 0;
    }

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        int char_idx = s[i] - 'a';
        count[char_idx]++;

        if (count[char_idx] == 1)
        {
            first_seen[char_idx] = i;
        }
        else if (count[char_idx] == 2)
        {
            int diff = i - first_seen[char_idx];
            
            if (diff % 2 == 0)
            {
                cout << "NO\n";
                return 0;
            }
        }
        else if (count[char_idx] > 2)
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}