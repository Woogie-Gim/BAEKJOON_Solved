#include <iostream>
#include <vector>
using namespace std;

long long gcd_ll(long long a, long long b)
{
    while (b != 0)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;

    while (true)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
        {
            break;
        }

        if (k > n - k)
        {
            k = n - k;
        }

        if (k == 0)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<long long> numer;
        numer.reserve((int)k);

        for (long long x = n - k + 1; x <= n; x++)
        {
            numer.push_back(x);
        }

        for (long long d = 2; d <= k; d++)
        {
            long long denom = d;

            for (int i = 0; i < (int)numer.size() && denom > 1; i++)
            {
                long long g = gcd_ll(numer[i], denom);
                if (g > 1)
                {
                    numer[i] /= g;
                    denom /= g;
                }
            }
        }

        long long ans = 1;
        for (int i = 0; i < (int)numer.size(); i++)
        {
            ans *= numer[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
