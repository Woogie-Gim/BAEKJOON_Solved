#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    while (T--)
    {
        long long N, M;
        cin >> N >> M;
        cout << (N + M - 1) << "\n";
    }

    return 0;
}
