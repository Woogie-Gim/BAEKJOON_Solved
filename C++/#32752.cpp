#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L, R;
    if (!(cin >> N >> L >> R))
    {
        return 0;
    }

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<long long> B = A;

    sort(B.begin() + L, B.begin() + R + 1);

    bool ok = true;
    for (int i = 1; i < N; ++i)
    {
        if (B[i] > B[i + 1])
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? 1 : 0) << '\n';

    return 0;
}
