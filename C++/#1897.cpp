#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d;
    string start_word;

    if (!(cin >> d >> start_word))
    {
        return 0;
    }

    vector<string> dict_by_len[81];

    for (int i = 0; i < d; i++)
    {
        string s;
        cin >> s;
        if (s.length() <= 80)
        {
            dict_by_len[s.length()].push_back(s);
        }
    }

    vector<string> valid_words[81];

    int start_len = start_word.length();
    valid_words[start_len].push_back(start_word);

    string max_word = start_word;

    for (int len = start_len + 1; len <= 80; len++)
    {
        for (int i = 0; i < (int)dict_by_len[len].size(); i++)
        {
            string candidate = dict_by_len[len][i];
            bool possible = false;

            for (int j = 0; j < (int)valid_words[len - 1].size(); j++)
            {
                string parent = valid_words[len - 1][j];
                
                int p_idx = 0;
                int c_idx = 0;
                
                while (p_idx < (int)parent.length() && c_idx < (int)candidate.length())
                {
                    if (parent[p_idx] == candidate[c_idx])
                    {
                        p_idx++;
                    }
                    c_idx++;
                }

                if (p_idx == (int)parent.length())
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
            {
                valid_words[len].push_back(candidate);
                max_word = candidate;
            }
        }
    }

    cout << max_word;

    return 0;
}