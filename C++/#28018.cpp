#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<int> count(1000005, 0);

    for (int i = 0; i < N; i++)
    {
        int S, E;
        cin >> S >> E;
        count[S]++;
        count[E + 1]--;
    }

    for (int i = 1; i <= 1000000; i++)
    {
        count[i] += count[i - 1];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int time;
        cin >> time;
        cout << count[time] << "\n";
    }

    return 0;
}