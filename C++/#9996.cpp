#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    int starPos = -1;
    int patternLen = pattern.size();

    for (int i = 0; i < patternLen; i++)
    {
        if (pattern[i] == '*')
        {
            starPos = i;
            break;
        }
    }

    string prefix = pattern.substr(0, starPos);
    string suffix = pattern.substr(starPos + 1);

    int prefixLen = prefix.size();
    int suffixLen = suffix.size();

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        int nameLen = name.size();

        bool ok = true;

        if (nameLen < prefixLen + suffixLen)
        {
            ok = false;
        }
        else
        {
            for (int j = 0; j < prefixLen; j++)
            {
                if (name[j] != prefix[j])
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                for (int j = 0; j < suffixLen; j++)
                {
                    if (name[nameLen - suffixLen + j] != suffix[j])
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok)
        {
            cout << "DA\n";
        }
        else
        {
            cout << "NE\n";
        }
    }

    return 0;
}
