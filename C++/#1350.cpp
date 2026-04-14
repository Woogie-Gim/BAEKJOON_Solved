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

    vector<long long> files(N);
    for (int i = 0; i < N; i++)
    {
        cin >> files[i];
    }

    long long cluster_size;
    cin >> cluster_size;

    long long total_disk_space = 0;

    for (int i = 0; i < N; i++)
    {
        if (files[i] == 0)
        {
            continue;
        }

        long long clusters = files[i] / cluster_size;
        if (files[i] % cluster_size != 0)
        {
            clusters++;
        }

        total_disk_space += clusters * cluster_size;
    }

    cout << total_disk_space << "\n";

    return 0;
}