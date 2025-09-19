#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y, M;
    cin >> X >> Y >> M;

    int best = 0;

    for (int a = 0; a * X <= M; a++)
    {
        int remain = M - a * X;
        int b = remain / Y;
        int val = a * X + b * Y;
        if (val > best)
        {
            best = val;
        }
    }

    cout << best << "\n";
    
    return 0;
}
