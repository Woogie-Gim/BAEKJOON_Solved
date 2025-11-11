#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int current = 0;
    int best = 0;

    for (int i = 0; i < 4; ++i)
    {
        int outCnt, inCnt;
        cin >> outCnt >> inCnt;

        current -= outCnt;
        current += inCnt;

        if (current > best)
        {
            best = current;
        }
    }

    cout << best << '\n';
    return 0;
}
