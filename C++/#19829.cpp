#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    if (!(cin >> n >> k))
    {
        return 0;
    }

    int prev, cur;
    int best = 1, len = 1;

    cin >> prev;
    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        if (cur != prev)
        {
            len++;
        }
        else
        {
            if (len > best)
            {
                best = len;
            }
            len = 1;
        }
        prev = cur;
    }
    if (len > best)
    {
        best = len;
    }

    cout << best << "\n";
    
    return 0;
}
