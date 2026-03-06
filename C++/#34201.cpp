#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, s;
    if (!(cin >> N >> s))
    {
        return 0;
    }

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long max_pos = 0;
    long long sum_top = 0;
    long long sum_bottom = 0;

    for (int i = 0; i < N / 2; i++)
    {
        sum_bottom += A[i];
    }

    for (int i = N / 2; i < N; i++)
    {
        sum_top += A[i];
    }

    if (N % 2 == 0)
    {
        max_pos = 2 * (sum_top - sum_bottom) + s;
    }
    else
    {
        max_pos = 2 * (sum_top - sum_bottom) - s;
    }

    cout << max_pos << "\n";

    return 0;
}