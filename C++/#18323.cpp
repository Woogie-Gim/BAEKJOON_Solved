#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> b(N);
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> b[i];
    }

    vector<int> best;
    bool hasBest = false;

    for (int start = 1; start <= N; start++)
    {
        vector<int> a(N + 1, 0);
        vector<int> used(N + 1, 0);

        a[1] = start;
        bool ok = true;

        if (a[1] < 1 || a[1] > N)
        {
            ok = false;
        }
        else
        {
            used[a[1]] = 1;
        }

        for (int i = 1; i <= N - 1 && ok; i++)
        {
            a[i + 1] = b[i] - a[i];

            if (a[i + 1] < 1 || a[i + 1] > N)
            {
                ok = false;
                break;
            }
            if (used[a[i + 1]] == 1)
            {
                ok = false;
                break;
            }
            used[a[i + 1]] = 1;
        }

        if (!ok)
        {
            continue;
        }

        vector<int> cand(N);
        for (int i = 1; i <= N; i++)
        {
            cand[i - 1] = a[i];
        }

        if (!hasBest)
        {
            best = cand;
            hasBest = true;
        }
        else
        {
            bool smaller = false;
            for (int i = 0; i < N; i++)
            {
                if (cand[i] < best[i])
                {
                    smaller = true;
                    break;
                }
                else if (cand[i] > best[i])
                {
                    break;
                }
            }
            if (smaller)
            {
                best = cand;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << ' ';
        cout << best[i];
    }
    cout << "\n";

    return 0;
}
