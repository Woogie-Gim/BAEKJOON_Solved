#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Log
{
    long long t; 
    int s;
    int i;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, C, K;
    if (!(cin >> X >> C >> K))
    {
        return 0;
    }

    vector<Log> logs;
    logs.reserve(K);

    for (int k = 0; k < K; k++)
    {
        long long T;
        int S, I;
        cin >> T >> S >> I; 
        logs.push_back({T, S, I});
    }

    sort(logs.begin(), logs.end(),
        [](const Log &a, const Log &b)
        {
            return a.t < b.t;
        });

    vector<int> assign(X + 1, 0);
    vector<char> seat_taken(C + 1, 0);

    for (const auto &e : logs)
    {
        int s = e.s;
        int i = e.i;

        if (s < 1 || s > C || i < 1 || i > X)
        {
            continue;
        }

        if (seat_taken[s])
        {
            continue;
        }

        if (assign[i] != 0)
        {
            seat_taken[assign[i]] = 0;
        }

        assign[i] = s;
        seat_taken[s] = 1;
    }

    for (int i = 1; i <= X; i++)
    {
        if (assign[i] != 0)
        {
            cout << i << " " << assign[i] << "\n";
        }
    }

    return 0;
}
