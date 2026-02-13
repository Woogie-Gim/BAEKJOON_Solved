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

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;

        vector<int> P(N);
        int total_senators = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> P[i];
            total_senators += P[i];
        }

        cout << "Case #" << t << ":";

        while (total_senators > 0)
        {
            int max_val = 0;
            for (int i = 0; i < N; i++)
            {
                if (P[i] > max_val)
                {
                    max_val = P[i];
                }
            }

            int max_count = 0;
            vector<int> max_indices;

            for (int i = 0; i < N; i++)
            {
                if (P[i] == max_val)
                {
                    max_count++;
                    max_indices.push_back(i);
                }
            }

            cout << " ";

            if (max_count % 2 != 0)
            {
                int idx = max_indices[0];
                cout << (char)('A' + idx);
                P[idx]--;
                total_senators--;
            }
            else
            {
                int idx1 = max_indices[0];
                int idx2 = max_indices[1];
                cout << (char)('A' + idx1) << (char)('A' + idx2);
                P[idx1]--;
                P[idx2]--;
                total_senators -= 2;
            }
        }
        cout << "\n";
    }

    return 0;
}