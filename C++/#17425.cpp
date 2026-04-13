#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int MAX_N = 1000000;
    vector<long long> f(MAX_N + 1, 0);
    vector<long long> g(MAX_N + 1, 0);

    for (int i = 1; i <= MAX_N; i++)
    {
        for (int j = 1; i * j <= MAX_N; j++)
        {
            f[i * j] += i;
        }
        g[i] = g[i - 1] + f[i];
    }

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;
            cout << g[n] << "\n";
        }
    }

    return 0;
}