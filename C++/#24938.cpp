#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    
    if (!(cin >> N))
    {
        return 0;
    }

    vector<long long> A(N);
    
    long long total_sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        total_sum += A[i];
    }

    long long avg = total_sum / N;

    long long current_balance = 0;
    long long total_cost = 0;

    for (int i = 0; i < N - 1; i++)
    {
        current_balance += (A[i] - avg);
        
        if (current_balance < 0)
        {
            total_cost += -current_balance;
        }
        else
        {
            total_cost += current_balance;
        }
    }

    cout << total_cost << "\n";

    return 0;
}