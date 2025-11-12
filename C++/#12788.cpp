#include <iostream>
#include <vector>
#include <algorithm>

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

    int M, K;
    cin >> M >> K;

    vector<int> A(N);
    long long total = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        total += A[i];
    }

    long long need = 1LL * M * K;

    if (total < need)
    {
        cout << "STRESS\n";
        return 0;
    }

    sort(A.begin(), A.end(), greater<int>());

    long long acc = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        acc += A[i];
        ++cnt;
        if (acc >= need)
        {
            cout << cnt << '\n';
            break;
        }
    }

    return 0;
}
