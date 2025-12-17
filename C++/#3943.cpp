#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        long long n;
        cin >> n;

        long long current = n;
        long long maxValue = n;

        while (current != 1)
        {
            if (current % 2 == 0)
            {
                current /= 2;
            }
            else
            {
                current = current * 3 + 1;
            }

            if (current > maxValue)
            {
                maxValue = current;
            }
        }

        cout << maxValue << '\n';
    }

    return 0;
}
