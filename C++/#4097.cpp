#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        long long cur = 0;
        long long best = 0;
        bool first = true;

        for (int i = 0; i < N; ++i)
        {
            long long x;
            cin >> x;

            if (first)
            {
                cur = x;
                best = x;
                first = false;
            }
            else
            {
                if (cur + x > x)
                {
                    cur = cur + x;
                }
                else
                {
                    cur = x;
                }

                if (cur > best)
                {
                    best = cur;
                }
            }
        }

        cout << best << '\n';
    }

    return 0;
}
