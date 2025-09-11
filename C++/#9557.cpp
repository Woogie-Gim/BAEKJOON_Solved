#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<string> w(N);
        for (int i = 0; i < N; i++)
        {
            cin >> w[i];
        }

        int idx = -1;
        for (int i = 0; i < N; i++)
        {
            if (w[i][0] != '#')
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            for (int i = 0; i < N; i++)
            {
                if (i) cout << ' ';
                cout << w[i];
            }
            cout << "\n";
            continue;
        }

        bool first = true;

        for (int i = idx + 1; i < N; i++)
        {
            if (!first) cout << ' ';
            cout << w[i];
            first = false;
        }

        if (!first) cout << ' ';
        cout << w[idx];
        first = false;

        for (int i = 0; i < idx; i++)
        {
            cout << ' ' << w[i];
        }

        cout << "\n";
    }

    return 0;
}
