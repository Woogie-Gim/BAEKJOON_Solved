#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, y;
    
    cin >> x >> y;

    while (x > 0 || y > 0)
    {
        int dx = (int)(x % 3);
        int dy = (int)(y % 3);

        if (dx == 2 || dy == 2 || dx == dy)
        {
            cout << 0 << "\n";
            return 0;
        }

        x /= 3;
        y /= 3;
    }

    cout << 1 << "\n";
    
    return 0;
}
