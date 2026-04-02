#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, K;
    if (!(cin >> N >> K))
    {
        return 0;
    }

    vector<long long> d(N);
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
    }

    long long total_cost = 1 + K;

    for (int i = 1; i < N; i++)
    {
        long long extend_cost = d[i] - d[i - 1];
        long long new_sub_cost = 1 + K;
        
        total_cost += min(extend_cost, new_sub_cost);
    }

    cout << total_cost << "\n";

    return 0;
}