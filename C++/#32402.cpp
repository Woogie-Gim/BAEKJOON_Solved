#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    int px = 0;
    int py = 0;
    int cx = 0;
    int cy = -1;

    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "MR")
        {
            int vx = cx - px;
            int vy = cy - py;
            
            cx = px + vy;
            cy = py - vx;
        }
        else if (cmd == "ML")
        {
            int vx = cx - px;
            int vy = cy - py;
            
            cx = px - vy;
            cy = py + vx;
        }
        else
        {
            int fx = px - cx;
            int fy = py - cy;
            
            int dx = 0;
            int dy = 0;

            if (cmd == "W")
            {
                dx = fx;
                dy = fy;
            }
            else if (cmd == "S")
            {
                dx = -fx;
                dy = -fy;
            }
            else if (cmd == "D")
            {
                dx = fy;
                dy = -fx;
            }
            else if (cmd == "A")
            {
                dx = -fy;
                dy = fx;
            }

            px += dx;
            py += dy;
            cx += dx;
            cy += dy;
        }

        cout << px << " " << py << " " << cx << " " << cy << "\n";
    }

    return 0;
}