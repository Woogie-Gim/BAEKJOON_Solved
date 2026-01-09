#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int M;
        cin >> M;

        if (M == 1)
        {
            string s;
            cin >> s;

            vector<unsigned long long> parts;
            unsigned long long cur = 0;

            for (int i = 0; i < (int)s.size(); i++)
            {
                if (s[i] == '.')
                {
                    parts.push_back(cur);
                    cur = 0;
                }
                else
                {
                    cur = cur * 10 + (unsigned long long)(s[i] - '0');
                }
            }
            parts.push_back(cur);

            unsigned long long value = 0;
            for (int i = 0; i < 8; i++)
            {
                value = value * 256ULL + parts[i];
            }

            cout << value << '\n';
        }
        else
        {
            unsigned long long N;
            cin >> N;

            unsigned long long a[8];

            for (int i = 7; i >= 0; i--)
            {
                a[i] = N % 256ULL;
                N /= 256ULL;
            }

            for (int i = 0; i < 8; i++)
            {
                if (i > 0) cout << '.';
                cout << a[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
