#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Z;
    if (!(cin >> Z))
    {
        return 0;
    }

    while (Z > 0)
    {
        Z--;
        
        string board[5];
        for (int i = 0; i < 5; i++)
        {
            cin >> board[i];
        }

        bool a_win = false;
        bool b_win = false;

        char players[2] = {'A', 'B'};

        for (int p = 0; p < 2; p++)
        {
            char target = players[p];
            bool win = false;

            for (int r = 0; r < 5; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    if (board[r][c] == target && board[r][c + 1] == target && board[r][c + 2] == target)
                    {
                        win = true;
                    }
                }
            }

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 5; c++)
                {
                    if (board[r][c] == target && board[r + 1][c] == target && board[r + 2][c] == target)
                    {
                        win = true;
                    }
                }
            }

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    if (board[r][c] == target && board[r + 1][c + 1] == target && board[r + 2][c + 2] == target)
                    {
                        win = true;
                    }
                }
            }

            for (int r = 0; r < 3; r++)
            {
                for (int c = 2; c < 5; c++)
                {
                    if (board[r][c] == target && board[r + 1][c - 1] == target && board[r + 2][c - 2] == target)
                    {
                        win = true;
                    }
                }
            }

            if (target == 'A')
            {
                a_win = win;
            }
            else
            {
                b_win = win;
            }
        }

        if (a_win && !b_win)
        {
            cout << "A wins\n";
        }
        else if (!a_win && b_win)
        {
            cout << "B wins\n";
        }
        else
        {
            cout << "draw\n";
        }
    }

    return 0;
}