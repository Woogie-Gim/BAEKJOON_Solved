#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void sieve(int limit, vector<bool> &isPrime, vector<int> &primes)
{
    isPrime.assign(limit + 1, true);
    isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;

    int root = static_cast<int>(sqrt(limit));
    for (int i = 2; i <= root; i++)
    {
        if (!isPrime[i]) continue;
        for (long long j = 1LL * i * i; j <= limit; j += i)
        {
            isPrime[(size_t)j] = false;
        }
    }

    primes.clear();
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> qs(T);
    int need = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> qs[i];
        if (qs[i] > need) need = qs[i];
    }

    int limit = 500000;
    vector<bool> isPrime;
    vector<int> primes;
    vector<int> super;

    while (true)
    {
        sieve(limit, isPrime, primes);

        super.clear();
        for (size_t i = 0; i < primes.size(); i++)
        {
            int idx = static_cast<int>(i) + 1;
            if (idx <= limit && isPrime[idx])
            {
                super.push_back(primes[i]);
                if ((int)super.size() >= need) break;
            }
        }

        if ((int)super.size() >= need) break;
        limit *= 2;
    }

    for (int i = 0; i < T; i++)
    {
        cout << super[qs[i] - 1] << '\n';
    }
    return 0;
}
