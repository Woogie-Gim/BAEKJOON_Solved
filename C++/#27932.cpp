#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    if (n <= 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> d(n - 1);
    long long maxDiff = 0;

    for (int i = 0; i < n - 1; i++)
    {
        long long diff = h[i + 1] - h[i];
        if (diff < 0) diff = -diff;
        d[i] = diff;
        if (diff > maxDiff) maxDiff = diff;
    }

    auto ok = [&](long long H) -> bool
    {
        long long tired = 0;

        if (d[0] > H)
        {
            tired++;
            if (tired > k) return false;
        }

        for (int i = 1; i <= n - 2; i++)
        {
            if (d[i - 1] > H || d[i] > H)
            {
                tired++;
                if (tired > k) return false;
            }
        }

        if (d[n - 2] > H)
        {
            tired++;
            if (tired > k) return false;
        }

        return true;
    };

    long long lo = -1;
    long long hi = maxDiff;

    while (lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2;
        if (ok(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    cout << hi << '\n';
    
    return 0;
}
