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

    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        long long A, B;
        cin >> N >> A >> B;

        for (int i = 0; i < N; ++i)
        {
            long long u, v;
            cin >> u >> v;
        }

        cout << "Material Management " << tc << '\n';
        cout << "Classification ---- End!" << '\n';
    }

    return 0;
}
