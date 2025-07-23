#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    v.push_back(0);
    v.push_back(K);

    sort(v.begin(), v.end());

    vector<long long> u;

    for (int i = 1; i < v.size(); i++)
    {
        u.push_back(max(0LL, (long long)(v[i] - v[i - 1] - 1)));
    }

    long long ans = LLONG_MAX;
    long long l = 1, r = K;

    while (l <= r)
    {
        long long m = (l + r) / 2;

        long long sum = 0;

        for (int i = 0; i < u.size(); i++)
        {
            sum += u[i] / m;
        }

        if (sum <= M)
        {
            ans = min(ans, m);
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
