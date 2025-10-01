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
    long long sum = 0;
    bool hasZero = false;

    for (char c : s)
    {
        int d = c - '0';
        cnt[d]++;
        sum += d;
        if (d == 0)
        {
            hasZero = true;
        }
    }

    if (!hasZero || (sum % 3 != 0))
    {
        cout << -1 << "\n";
        return 0;
    }

    for (int d = 9; d >= 0; d--)
    {
        for (int k = 0; k < cnt[d]; k++)
        {
            cout << d;
        }
    }
    cout << "\n";

    return 0;
}
