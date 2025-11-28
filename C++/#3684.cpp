#include <iostream>

using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modinv(long long a, long long m)
{
    long long x, y;
    long long g = extgcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int odd[105];
    int even_ans[105];

    for (int i = 0; i < T; i++)
    {
        cin >> odd[i];
    }

    int MOD = 10001;

    if (T == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    else if (T == 2)
    {
        int x3 = odd[1];
        cout << x3 << '\n';
        cout << x3 << '\n';
        return 0;
    }
    else
    {
        int x1 = odd[0];
        int x3 = odd[1];
        int x5 = odd[2];

        int a = -1;
        int b = -1;

        for (int cand = 0; cand < MOD; cand++)
        {
            long long left = x5 - x3;
            left %= MOD;
            if (left < 0) left += MOD;

            long long diff = x3 - x1;
            diff %= MOD;
            if (diff < 0) diff += MOD;

            long long tmp = (long long)cand * cand % MOD;
            tmp = tmp * diff % MOD;

            if ((left - tmp) % MOD != 0)
            {
                continue;
            }

            long long rhs = x3 - (long long)cand * cand % MOD * x1 % MOD;
            rhs %= MOD;
            if (rhs < 0) rhs += MOD;

            long long A = cand + 1;
            long long xg, yg;
            long long g = extgcd(A, MOD, xg, yg);

            if (rhs % g != 0)
            {
                continue;
            }

            long long A1 = A / g;
            long long M1 = MOD / g;
            long long rhs1 = rhs / g;

            long long invA1 = modinv(A1, M1);
            long long b0 = rhs1 * invA1 % M1;
            if (b0 < 0) b0 += M1;

            a = cand;
            b = (int)b0;
            break;
        }

        long long cur = x1;

        for (int i = 0; i < T; i++)
        {
            long long even = (long long)a * cur + b;
            even %= MOD;
            if (even < 0) even += MOD;
            even_ans[i] = (int)even;

            if (i + 1 < T)
            {
                long long next_odd = (long long)a * even + b;
                next_odd %= MOD;
                if (next_odd < 0) next_odd += MOD;
                cur = next_odd;
            }
        }

        for (int i = 0; i < T; i++)
        {
            cout << even_ans[i] << '\n';
        }
    }

    return 0;
}
