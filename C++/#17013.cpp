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

    int h = 0, v = 0;
    for (char c : s)
    {
        if (c == 'H')
        {
            h ^= 1;
        }
        else if (c == 'V')
        {
            v ^= 1;
        }
    }

    int a = 1, b = 2, c1 = 3, d = 4;

    if (h)
    {
        swap(a, c1);
        swap(b, d);
    }
    if (v)
    {
        swap(a, b);
        swap(c1, d);
    }

    cout << a << ' ' << b << '\n';
    cout << c1 << ' ' << d << '\n';

    return 0;
}
