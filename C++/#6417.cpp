#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        long long N;
        cin >> N;

        if (N == -1)
        {
            break;
        }

        int bestK = -1;

        for (int K = 2; K <= 50; K++)
        {
            long long x = N;
            bool ok = true;

            for (int i = 0; i < K; i++)
            {
                if (x % K != 1)
                {
                    ok = false;
                    break;
                }

                x -= 1;
                long long share = x / K;
                x -= share;
            }

            if (ok && x % K == 0)
            {
                bestK = K;
            }
        }

        if (bestK == -1)
        {
            cout << N << " coconuts, no solution\n";
        }
        else
        {
            cout << N << " coconuts, " << bestK << " people and 1 monkey\n";
        }
    }

    return 0;
}
