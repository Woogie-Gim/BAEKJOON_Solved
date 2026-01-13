#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, k;
    cin >> a >> k;

    if (k == 0)
    {
        cout << a << '\n';
        return 0;
    }

    if (a % 2 == 0)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << a << '\n';
    }

    return 0;
}
