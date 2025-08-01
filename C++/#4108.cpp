#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int result[100][100];

int di[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dj[8] = {  0,  1, 1, 1, 0, -1, -1, -1 };

string matrix[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;

    while (cin >> R >> C, R)
    {
        for (int i = 0; i < R; i++)
        {
            cin >> matrix[i];
        }

        memset(result, 0, sizeof(result));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (matrix[i][j] == '*')
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int ii = i + di[k];
                        int jj = j + dj[k];

                        if (0 <= ii && ii < R && 0 <= jj && jj < C)
                        {
                            result[ii][jj] += 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (matrix[i][j] == '*')
                {
                    cout << '*';
                }
                else
                {
                    cout << result[i][j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}