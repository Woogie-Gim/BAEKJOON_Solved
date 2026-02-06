#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

        vector<int> skills(N);
        int total_skill = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> skills[i];
            total_skill += skills[i];
        }

        int min_diff = 2147483647;
        int limit = 1 << N;

        for (int i = 0; i < limit; i++)
        {
            int current_skill = 0;
            int count = 0;

            for (int j = 0; j < N; j++)
            {
                if ((i >> j) & 1)
                {
                    current_skill += skills[j];
                    count++;
                }
            }

            if (count == N / 2)
            {
                int other_skill = total_skill - current_skill;
                int diff = abs(current_skill - other_skill);

                if (diff < min_diff)
                {
                    min_diff = diff;
                }
            }
        }

        cout << "Case #" << t << ": " << min_diff << "\n";
    }

    return 0;
}