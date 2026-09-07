#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // (n+1) x (n+1). 0행 0열은 비워둠
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 전처리 O(N^2)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] = prefix[i - 1][j]
                         + prefix[i][j - 1]
                         - prefix[i - 1][j - 1]
                         + arr[i][j];
        }
    }

    // 질의 처리. 각 O(1)
    for (int q = 0; q < m; q++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = prefix[x2][y2]
                - prefix[x1 - 1][y2]
                - prefix[x2][y1 - 1]
                + prefix[x1 - 1][y1 - 1];

        cout << sum << "\n";
    }

    return 0;
}