#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long my_gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    long long X;
    cin >> X;

    long long cnt = 0;
    long long sum = 0;

    for (int i = 0; i < N; ++i)
    {
        if (my_gcd(A[i], X) == 1)
        {
            sum += A[i];
            cnt += 1;
        }
    }

    double ans = static_cast<double>(sum) / static_cast<double>(cnt);
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
