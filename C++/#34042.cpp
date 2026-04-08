#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    if (!(cin >> N >> M))
    {
        return 0;
    }

    while (M--)
    {
        int zero_cnt = 0;
        vector<long long> pos;
        vector<long long> neg;

        for (int i = 0; i < N; i++)
        {
            long long x;
            cin >> x;
            if (x == 0)
            {
                zero_cnt++;
            }
            else if (x > 0)
            {
                pos.push_back(x);
            }
            else
            {
                neg.push_back(x);
            }
        }

        sort(neg.begin(), neg.end());

        long long dropped = -100;
        if (neg.size() % 2 != 0)
        {
            dropped = neg.back();
            neg.pop_back();
        }

        if (pos.empty() && neg.empty())
        {
            if (zero_cnt > 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << dropped << "\n";
            }
        }
        else
        {
            long long ans = 1;
            for (long long x : pos)
            {
                ans *= x;
            }
            for (long long x : neg)
            {
                ans *= x;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}