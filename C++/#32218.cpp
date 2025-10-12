#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}
    void reset(int m)
    {
        n = m;
        bit.assign(n + 1, 0);
    }
    void add(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
        {
            bit[idx] += val;
        }
    }
    int sum(int idx) const
    {
        int r = 0;
        for (; idx > 0; idx -= idx & -idx)
        {
            r += bit[idx];
        }
        return r;
    }
    int total() const
    {
        return sum(n);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long limit = 1LL * n * (n - 1) / 2 + 5;
    long long runs = 0;

    Fenwick fw;

    while (true)
    {
        runs++;

        // 좌표압축
        vector<long long> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto rank_of = [&](long long x) -> int
        {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        };

        fw.reset((int)vals.size());

        vector<long long> b(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int r = rank_of(a[i]);
            int leq = fw.sum(r);        
            int gt = fw.total() - leq; 
            b[i] = gt;
            fw.add(r, 1);
        }

        if (b == a)
        {
            cout << runs << "\n";
            break;
        }

        a.swap(b);

        if (runs > limit)
        {
            cout << -1 << "\n";
            break;
        }
    }

    return 0;
}
