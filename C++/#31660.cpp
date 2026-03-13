#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long L, R;
    if (!(cin >> L >> R))
    {
        return 0;
    }

    struct Math
    {
        long long mod_pow(long long base, long long exp)
        {
            long long res = 1;
            base %= 1000000007;
            
            while (exp > 0)
            {
                if (exp % 2 == 1)
                {
                    res = (res * base) % 1000000007;
                }
                base = (base * base) % 1000000007;
                exp /= 2;
            }
            
            return res;
        }

        long long sum_geom(long long k, long long p)
        {
            if (p == 0)
            {
                return 0;
            }

            long long num = (mod_pow(k, p) - 1 + 1000000007) % 1000000007;
            num = (num * k) % 1000000007;

            long long den = k - 1;
            long long inv_den = mod_pow(den, 1000000007 - 2);

            return (num * inv_den) % 1000000007;
        }

        long long S(long long N, long long k)
        {
            long long p = N / 2;
            long long ans = (2 * sum_geom(k, p)) % 1000000007;

            if (N % 2 != 0)
            {
                ans = (ans + mod_pow(k, p + 1)) % 1000000007;
            }

            return ans;
        }
    };

    Math math;

    long long ans5 = (math.S(R, 5) - math.S(L - 1, 5) + 1000000007) % 1000000007;
    long long ans2 = (math.S(R, 2) - math.S(L - 1, 2) + 1000000007) % 1000000007;

    long long final_ans = (ans5 + ans2) % 1000000007;

    cout << final_ans << "\n";

    return 0;
}