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

    int cnt[10] = {0};
    for (char c : s)
    {
        cnt[c - '0']++;
    }

    for (int d = 1; d <= 9; d++)
    {
        if (cnt[d] == 0)
        {
            cout << d << '\n';
            return 0;
        }
    }

    int m = 1;
    for (int d = 2; d <= 9; d++)
    {
        if (cnt[d] < cnt[m])
        {
            m = d;
        }
    }

    if (cnt[0] < cnt[m])
    {
        cout << 1;
        for (int i = 0; i < cnt[0] + 1; i++)
        {
            cout << 0;
        }
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < cnt[m] + 1; i++)
        {
            cout << m;
        }
        cout << '\n';
    }

    return 0;
}
