#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long T;
    if (!(cin >> N >> T))
    {
        return 0;
    }

    long long L[1005];
    long long R[1005];

    long long sum_L = 0;
    long long sum_R = 0;
    long long max_L = 0;
    long long max_R = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
        
        sum_L += L[i];
        sum_R += R[i];
        
        if (L[i] > max_L)
        {
            max_L = L[i];
        }
        if (R[i] > max_R)
        {
            max_R = R[i];
        }
    }

    if (sum_L > T || sum_R < T)
    {
        cout << -1 << "\n";
        return 0;
    }

    long long low = max_L;
    long long high = max_R;
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long current_sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (R[i] < mid)
            {
                current_sum += R[i];
            }
            else
            {
                current_sum += mid;
            }
        }

        if (current_sum >= T)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}