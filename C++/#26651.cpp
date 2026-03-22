#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long X;
    if (!(cin >> X))
    {
        return 0;
    }

    if (X == 0)
    {
        cout << "GBSISTHEBEST\n";
        return 0;
    }

    while (X > 0)
    {
        long long low = 1;
        long long high = 31622;
        long long B = 1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            
            if (mid * mid <= X)
            {
                B = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        long long A = X / B;

        for (long long i = 0; i < A; i++)
        {
            cout << 'A';
        }

        for (char c = 'B'; c <= 'Y'; c++)
        {
            cout << c;
        }

        for (long long i = 0; i < B; i++)
        {
            cout << 'Z';
        }

        X = X - (A * B);
    }

    cout << "\n";

    return 0;
}