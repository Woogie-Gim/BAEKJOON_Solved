#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, X;
    if (!(cin >> T >> X))
    {
        return 0;
    }

    int N;
    cin >> N;

    bool all_ok = true;

    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;

        bool found = false;
        for (int j = 0; j < K; j++)
        {
            int a;
            cin >> a;
            if (a == X)
            {
                found = true;
            }
        }

        if (!found)
        {
            all_ok = false;
        }
    }

    if (all_ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
