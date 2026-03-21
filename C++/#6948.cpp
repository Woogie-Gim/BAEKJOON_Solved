#include <iostream>
#include <string>

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

    bool appears[26];
    bool elements[26][26];
    bool contains_set[26][26];

    for (int i = 0; i < 26; i++)
    {
        appears[i] = false;
        for (int j = 0; j < 26; j++)
        {
            elements[i][j] = false;
            contains_set[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        string X_str, contains_str, S_str;
        cin >> X_str >> contains_str >> S_str;

        char X = X_str[0];
        char S = S_str[0];

        int x_idx = X - 'A';
        appears[x_idx] = true;

        if (S >= 'A' && S <= 'Z')
        {
            int s_idx = S - 'A';
            appears[s_idx] = true;
            contains_set[x_idx][s_idx] = true;
        }
        else if (S >= 'a' && S <= 'z')
        {
            int e_idx = S - 'a';
            elements[x_idx][e_idx] = true;
        }
    }

    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (contains_set[i][j])
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (elements[j][k] && !elements[i][k])
                        {
                            elements[i][k] = true;
                            changed = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (appears[i])
        {
            cout << (char)('A' + i) << " = {";
            bool first = true;
            for (int k = 0; k < 26; k++)
            {
                if (elements[i][k])
                {
                    if (!first)
                    {
                        cout << ",";
                    }
                    cout << (char)('a' + k);
                    first = false;
                }
            }
            cout << "}\n";
        }
    }

    return 0;
}