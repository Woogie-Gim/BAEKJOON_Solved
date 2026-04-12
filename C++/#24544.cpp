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

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long total_sum = 0;
    long long unregistered_sum = 0;

    for (int i = 0; i < N; i++)
    {
        int b;
        cin >> b;
        
        total_sum += A[i];
        if (b == 0)
        {
            unregistered_sum += A[i];
        }
    }

    cout << total_sum << "\n";
    cout << unregistered_sum << "\n";

    return 0;
}