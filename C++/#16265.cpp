#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t))
    {
        return 0;
    }

    while (t--)
    {
        unsigned long long k;
        cin >> k;

        unsigned long long block = 26ULL;
        unsigned long long cum = block;
        int L = 1;

        while (k > cum)
        {
            block *= 26ULL;
            cum += block;
            ++L;
        }

        unsigned long long before = cum - block;
        unsigned long long idx = (k - 1ULL) - before;

        string s(L, 'A');
        for (int i = L - 1; i >= 0; --i)
        {
            int d = (int)(idx % 26ULL);
            s[i] = char('A' + d);
            idx /= 26ULL;
        }

        cout << s << '\n';
    }

    return 0;
}
