#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;

        vector<string> g(k);
        for (int i = 0; i < k; i++)
        {
            cin >> g[i];
        }

        bool horizontal = true;
        bool vertical = true;

        for (int r = 0; r < k; r++)
        {
            for (int c = 0; c < k; c++)
            {
                if (g[r][c] != g[k - 1 - r][c])
                {
                    horizontal = false;
                }
                if (g[r][c] != g[r][k - 1 - c])
                {
                    vertical = false;
                }
            }
        }

        if (horizontal && vertical)
        {
            cout << "Magnificent\n";
        }
        else if (horizontal)
        {
            cout << "Beautiful\n";
        }
        else if (vertical)
        {
            cout << "Graceful\n";
        }
        else
        {
            cout << "Useless\n";
        }
    }

    return 0;
}
