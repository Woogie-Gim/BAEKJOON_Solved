#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char nn[4 * n - 3][4 * n - 3];
    fill(&nn[0][0], &nn[4 * n - 3 - 1][4 * n - 3], ' ');

    int a = 0;
    int b = 4 * n - 4;
    for (int q = 0; q < n; q++)
    {
        for (int i = a; i <= b; i++)
        {
            nn[a][i] = nn[i][a] = nn[i][b] = nn[b][i] = '*';
        }
        a += 2;
        b -= 2;
    }

    for (int i = 0; i < 4 * n - 3; i++)
    {
        for (int j = 0; j < 4 * n - 3; j++)
        {
            cout << nn[i][j];
        }
        cout << "\n";
    }
}