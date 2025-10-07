#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector<vector<int>> a(N, vector<int>(M));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    long long area = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int h = a[i][j];
            if (h == 0)
            {
                continue;
            }

            area += 2;

            int up = (i == 0) ? 0 : a[i - 1][j];
            
            if (h > up)
            {
                area += h - up;
            }

            int down = (i == N - 1) ? 0 : a[i + 1][j];
            
            if (h > down)
            {
                area += h - down;
            }

            int left = (j == 0) ? 0 : a[i][j - 1];
            
            if (h > left)
            {
                area += h - left;
            }

            int right = (j == M - 1) ? 0 : a[i][j + 1];
            
            if (h > right)
            {
                area += h - right;
            }
        }
    }

    cout << area << "\n";
    
    return 0;
}
