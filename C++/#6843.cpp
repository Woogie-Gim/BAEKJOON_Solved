#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    int cnt[26] = {0};

    for (char ch : s1)
    {
        if (ch != ' ')
        {
            cnt[ch - 'A'] += 1;
        }
    }

    for (char ch : s2)
    {
        if (ch != ' ')
        {
            cnt[ch - 'A'] -= 1;
        }
    }

    bool isAnagram = true;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] != 0)
        {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram)
    {
        cout << "Is an anagram.\n";
    }
    else
    {
        cout << "Is not an anagram.\n";
    }

    return 0;
}
