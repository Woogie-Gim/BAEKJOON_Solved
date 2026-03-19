#include <iostream>

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

    for (int t = 1; t <= T; t++)
    {
        int board[9][9];
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> board[i][j];
            }
        }

        bool is_valid = true;

        for (int i = 0; i < 9; i++)
        {
            int check[10];
            for (int k = 1; k <= 9; k++)
            {
                check[k] = 0;
            }

            for (int j = 0; j < 9; j++)
            {
                check[board[i][j]]++;
            }

            for (int k = 1; k <= 9; k++)
            {
                if (check[k] != 1)
                {
                    is_valid = false;
                }
            }
        }

        for (int j = 0; j < 9; j++)
        {
            int check[10];
            for (int k = 1; k <= 9; k++)
            {
                check[k] = 0;
            }

            for (int i = 0; i < 9; i++)
            {
                check[board[i][j]]++;
            }

            for (int k = 1; k <= 9; k++)
            {
                if (check[k] != 1)
                {
                    is_valid = false;
                }
            }
        }

        for (int r = 0; r < 9; r += 3)
        {
            for (int c = 0; c < 9; c += 3)
            {
                int check[10];
                for (int k = 1; k <= 9; k++)
                {
                    check[k] = 0;
                }

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        check[board[r + i][c + j]]++;
                    }
                }

                for (int k = 1; k <= 9; k++)
                {
                    if (check[k] != 1)
                    {
                        is_valid = false;
                    }
                }
            }
        }

        cout << "Case " << t << ": ";
        if (is_valid)
        {
            cout << "CORRECT\n";
        }
        else
        {
            cout << "INCORRECT\n";
        }
    }

    return 0;
}