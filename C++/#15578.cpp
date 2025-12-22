#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long K, M;
    cin >> N >> K >> M;

    vector<long long> teams(N + 1, 0);

    long long cycleLen = 2LL * (N - 1);
    long long fullCycles = M / (cycleLen * K);

    if (fullCycles > 0)
    {
        teams[1] += fullCycles * K;
        teams[N] += fullCycles * K;

        for (int i = 2; i <= N - 1; i++)
        {
            teams[i] += fullCycles * 2 * K;
        }
    }

    long long remain = M - fullCycles * cycleLen * K;

    int pos = 1;
    int dir = 1;

    while (remain > 0)
    {
        long long give = min(K, remain);
        teams[pos] += give;
        remain -= give;

        if (pos == N)
        {
            dir = -1;
        }
        else if (pos == 1)
        {
            dir = 1;
        }

        pos += dir;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << teams[i] << ' ';
    }

    cout << '\n';
    
    return 0;
}
