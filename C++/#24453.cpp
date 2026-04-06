#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    int M;
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector<long long> A(M + 2);
    A[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i];
    }
    A[M + 1] = N + 1;

    long long X;
    int Y;
    cin >> X >> Y;

    sort(A.begin() + 1, A.begin() + M + 1);

    int low = 0;
    int high = M;
    int min_k = M;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool possible = false;
        
        for (int i = 0; i <= M - mid; i++)
        {
            if (A[i + mid + 1] - A[i] > X)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            min_k = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    int manual_fixes = max(min_k, Y);
    int auto_fixes = M - manual_fixes;

    cout << auto_fixes << "\n";

    return 0;
}