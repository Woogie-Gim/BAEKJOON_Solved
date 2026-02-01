#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arcs(N);
    long long total_length = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arcs[i];
        total_length += arcs[i];
    }

    if (total_length % 3 != 0)
    {
        cout << 0;
        return 0;
    }

    long long one_third = total_length / 3;
    long long two_third = one_third * 2;

    vector<long long> positions(N);
    positions[0] = 0;
    for (int i = 1; i < N; i++)
    {
        positions[i] = positions[i - 1] + arcs[i - 1];
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        long long current_pos = positions[i];
        long long target1 = (current_pos + one_third) % total_length;
        long long target2 = (current_pos + two_third) % total_length;

        bool found1 = binary_search(positions.begin(), positions.end(), target1);
        bool found2 = binary_search(positions.begin(), positions.end(), target2);

        if (found1 && found2)
        {
            count++;
        }
    }

    cout << count / 3;

    return 0;
}