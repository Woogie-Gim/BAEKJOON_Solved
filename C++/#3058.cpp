#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    while (T--)
    {
        int sum = 0;
        int min_even = 101;

        for (int i = 0; i < 7; i++)
        {
            int num;
            cin >> num;

            if (num % 2 == 0)
            {
                sum += num;
                min_even = min(min_even, num);
            }
        }

        cout << sum << " " << min_even << "\n";
    }

    return 0;
}