#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string A, B;
        cin >> A >> B;

        bool ok = true;

        if (A.size() != B.size())
        {
            ok = false;
        }
        else
        {
            int cnt[26] = {0};
            for (char c : A)
            {
                cnt[c - 'a']++;
            }
            for (char c : B)
            {
                cnt[c - 'a']--;
            }
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] != 0)
                {
                    ok = false;
                    break;
                }
            }
        }

        cout << A << " & " << B << " are ";
        if (!ok)
        {
            cout << "NOT ";
        }
        cout << "anagrams.\n";
    }

    return 0;
}
