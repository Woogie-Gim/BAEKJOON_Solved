#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    if (!(cin >> k))
    {
        return 0;
    }

    int rowLast[11] = {0};
    int colLast[11] = {0};

    for (int w = 1; w <= k; ++w)
    {
        int r[3], c[3];
        cin >> r[0] >> r[1] >> r[2] >> c[0] >> c[1] >> c[2];

        rowLast[r[0]] = w;
        rowLast[r[1]] = w;
        rowLast[r[2]] = w;

        colLast[c[0]] = w;
        colLast[c[1]] = w;
        colLast[c[2]] = w;
    }

    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            int last = rowLast[i];
            if (colLast[j] > last)
            {
                last = colLast[j];
            }
            int h = 1 + (k - last);
            if (j > 1) cout << ' ';
            cout << h;
        }
        cout << '\n';
    }

    return 0;
}
