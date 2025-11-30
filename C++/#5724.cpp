#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        long long N;
        if (!(cin >> N))
        {
            return 0;
        }
        if (N == 0)
        {
            break;
        }

        long long answer = N * (N + 1) * (2 * N + 1) / 6;
        cout << answer << '\n';
    }

    return 0;
}
