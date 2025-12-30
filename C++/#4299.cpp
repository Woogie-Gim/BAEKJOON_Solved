#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S, D;
    cin >> S >> D;

    if ((S + D) % 2 != 0 || S < D)
    {
        cout << -1;
        return 0;
    }

    int x = (S + D) / 2;
    int y = (S - D) / 2;

    if (y < 0)
    {
        cout << -1;
        return 0;
    }

    cout << x << " " << y;
}
