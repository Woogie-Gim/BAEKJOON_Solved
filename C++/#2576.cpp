#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int mn = 101;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 1)
        {
            sum += x;
            if (x < mn)
            {
                mn = x;
            }
        }
    }

    if (sum == 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << sum << "\n" << mn << "\n";
    }
    return 0;
}
