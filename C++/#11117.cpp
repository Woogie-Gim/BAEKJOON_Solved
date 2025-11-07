#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    while (T--)
    {
        string box;
        cin >> box;

        int base[26] = {0};
        for (char ch : box)
        {
            base[ch - 'A'] += 1;
        }

        int W;
        cin >> W;
        while (W--)
        {
            string word;
            cin >> word;

            int need[26] = {0};
            for (char ch : word)
            {
                need[ch - 'A'] += 1;
            }

            bool ok = true;
            for (int i = 0; i < 26; ++i)
            {
                if (need[i] > base[i])
                {
                    ok = false;
                    break;
                }
            }

            cout << (ok ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
