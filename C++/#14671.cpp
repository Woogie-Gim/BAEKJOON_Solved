#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    if (!(cin >> N >> M >> K))
    {
        return 0;
    }

    bool check[2][2] = {false, false, false, false};

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        check[x % 2][y % 2] = true;
    }

    if (check[0][0] && check[0][1] && check[1][0] && check[1][1])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}