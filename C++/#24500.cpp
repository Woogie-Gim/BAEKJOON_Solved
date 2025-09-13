#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long N;
    if (!(cin >> N))
    {
        return 0;
    }

    unsigned long long p = 1;
    while ((p << 1) <= N)
    {
        p <<= 1;
    }

    unsigned long long M = (p << 1) - 1;

    if (N == M)
    {
        cout << 1 << "\n";
        cout << N << "\n";
    }
    else
    {
        unsigned long long a = (M ^ N);
        cout << 2 << "\n";
        cout << a << "\n";
        cout << N << "\n";
    }

    return 0;
}
