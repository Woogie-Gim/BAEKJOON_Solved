#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    if (!(cin >> n >> x >> y))
    {
        return 0;
    }

    struct Solver
    {
        int n;
        int count;
        int seq[30];
        bool used[15];

        void dfs(int num)
        {
            if (num == 0)
            {
                count++;
                return;
            }

            if (used[num])
            {
                dfs(num - 1);
                return;
            }

            for (int i = 1; i <= 2 * n - num - 1; i++)
            {
                if (seq[i] == 0 && seq[i + num + 1] == 0)
                {
                    seq[i] = num;
                    seq[i + num + 1] = num;
                    used[num] = true;

                    dfs(num - 1);

                    used[num] = false;
                    seq[i] = 0;
                    seq[i + num + 1] = 0;
                }
            }
        }
    };

    Solver solver;
    solver.n = n;
    solver.count = 0;

    for (int i = 0; i < 30; i++)
    {
        solver.seq[i] = 0;
    }

    for (int i = 0; i < 15; i++)
    {
        solver.used[i] = false;
    }

    int target_num = y - x - 1;
    solver.seq[x] = target_num;
    solver.seq[y] = target_num;
    solver.used[target_num] = true;

    solver.dfs(n);

    cout << solver.count << "\n";

    return 0;
}