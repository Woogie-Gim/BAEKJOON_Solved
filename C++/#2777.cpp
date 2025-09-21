#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        if (N == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        int cnt = 0;
        for (int d = 9; d >= 2; d--)
        {
            while (N % d == 0)
            {
                N /= d;
                cnt++;
            }
        }

        if (N != 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << cnt << "\n";
        }
    }

    return 0;
}
