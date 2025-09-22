#include <iostream>
#include <vector>

using namespace std;

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
        int N;
        cin >> N;

        vector<int> p(N + 1);
        for (int i = 1; i <= N; i++)
        {
            cin >> p[i];
        }

        vector<int> visited(N + 1, 0);
        int cycles = 0;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i])
            {
                continue;
            }

            int cur = i;
            while (!visited[cur])
            {
                visited[cur] = 1;
                cur = p[cur];
            }
            cycles++;
        }

        cout << cycles << "\n";
    }

    return 0;
}
