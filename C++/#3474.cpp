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

        long long ans = 0;
        for (long long p = 5; p <= N; p *= 5)
        {
            ans += N / p;
        }

        cout << ans << '\n';
    }

    return 0;
}
