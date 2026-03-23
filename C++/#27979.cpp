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

    vector<int> A(N);
    vector<int> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        S[i] = A[i];
    }

    sort(S.begin(), S.end());

    int p1 = N - 1;
    int p2 = N - 1;

    while (p1 >= 0 && p2 >= 0)
    {
        if (A[p1] == S[p2])
        {
            p2--;
        }
        p1--;
    }

    cout << p2 + 1 << "\n";

    return 0;
}