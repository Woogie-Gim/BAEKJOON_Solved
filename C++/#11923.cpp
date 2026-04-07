#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    if (!(cin >> N >> C))
    {
        return 0;
    }

    vector<int> w(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }

    int max_fruits = 0;

    for (int start = 0; start < N; start++)
    {
        int current_weight = 0;
        int current_count = 0;

        for (int i = start; i < N; i++)
        {
            if (current_weight + w[i] <= C)
            {
                current_weight += w[i];
                current_count++;
            }
        }

        max_fruits = max(max_fruits, current_count);
    }

    cout << max_fruits << "\n";

    return 0;
}