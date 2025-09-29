#include <iostream>
#include <string>

using namespace std;

int n_global, k_global;
string cur;

inline void dfs(int pos, int ones_left)
{
    if (pos == n_global)
    {
        cout << cur << "\n";
        return;
    }

    int rem = n_global - pos; // 남은 자리 수

    if (ones_left > 0 && ones_left - 1 <= rem - 1)
    {
        cur[pos] = '1';
        dfs(pos + 1, ones_left - 1);
    }

    if (ones_left <= rem - 1)
    {
        cur[pos] = '0';
        dfs(pos + 1, ones_left);
    }
}

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
        int n, k;
        cin >> n >> k;

        cout << "The bit patterns are\n";

        n_global = n;
        k_global = k;
        cur.assign(n, '0');

        dfs(0, k);

        if (T)
        {
            cout << "\n";
        }
    }

    return 0;
}
