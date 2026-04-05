#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    if (!(cin >> N >> K))
    {
        return 0;
    }

    vector<int> A(N + 1);
    vector<int> V(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        V[i] = A[i];
    }

    sort(V.begin() + 1, V.end());

    vector<int> A_rank(N + 1);
    vector<int> pos(N + 1);

    for (int i = 1; i <= N; i++)
    {
        A_rank[i] = lower_bound(V.begin() + 1, V.end(), A[i]) - V.begin();
        pos[A_rank[i]] = i;
    }

    int swap_count = 0;

    for (int last = N; last >= 2; last--)
    {
        int target_rank = last;
        int idx = pos[target_rank];

        if (idx != last)
        {
            swap(A_rank[idx], A_rank[last]);
            swap(A[idx], A[last]);

            pos[A_rank[idx]] = idx;
            pos[A_rank[last]] = last;

            swap_count++;

            if (swap_count == K)
            {
                for (int i = 1; i <= N; i++)
                {
                    cout << A[i] << (i == N ? "" : " ");
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}