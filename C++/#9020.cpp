#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    const int MAXN = 10000;
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int p = 2; p * p <= MAXN; ++p)
    {
        if (isPrime[p])
        {
            for (int q = p * p; q <= MAXN; q += p)
            {
                isPrime[q] = false;
            }
        }
    }

    while (T--)
    {
        int n;
        cin >> n;

        int a = n / 2;
        int b = n - a;

        while (a >= 2)
        {
            if (isPrime[a] && isPrime[b])
            {
                cout << a << ' ' << b << '\n';
                break;
            }
            --a;
            ++b;
        }
    }

    return 0;
}
