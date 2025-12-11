#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> words(n);
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        int len = (int)words[i].size();
        if (len > maxLen)
        {
            maxLen = len;
        }
    }

    for (int pos = 0; pos < maxLen; pos++)
    {
        int freq[26];
        for (int i = 0; i < 26; i++)
        {
            freq[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if ((int)words[i].size() > pos)
            {
                char ch = words[i][pos];
                int index = ch - 'a';
                freq[index]++;
            }
        }

        int maxFreq = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > maxFreq)
            {
                maxFreq = freq[i];
            }
        }

        cout << (pos + 1) << ":";
        bool firstPrinted = false;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == maxFreq && maxFreq > 0)
            {
                if (!firstPrinted)
                {
                    cout << " ";
                    firstPrinted = true;
                }
                else
                {
                    cout << " ";
                }
                char ch = (char)('a' + i);
                cout << ch;
            }
        }

        cout << "\n";
    }

    return 0;
}
