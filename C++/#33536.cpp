#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        size_t pos = s.find('-');
        a[i] = stoi(s.substr(0, pos));
        b[i] = stoi(s.substr(pos + 1));
    }

    int host_wins = 0;
    int guest_wins = 0;

    for (int i = 0; i < n; i++)
    {
        if (host_wins >= 3 || guest_wins >= 3)
        {
            cout << "INCONSISTENT\n";
            return 0;
        }

        int mx = a[i] > b[i] ? a[i] : b[i];
        int mn = a[i] < b[i] ? a[i] : b[i];

        bool valid = true;
        if (mx > 11)
        {
            if (mn < 10)
            {
                valid = false;
            }
            if (mx - mn > 2)
            {
                valid = false;
            }
        }

        if (!valid)
        {
            cout << "INCONSISTENT\n";
            return 0;
        }

        bool finished = false;
        if (mx == 11 && mn <= 9)
        {
            finished = true;
        }
        if (mx > 11 && mx - mn == 2)
        {
            finished = true;
        }

        if (i < n - 1 && !finished)
        {
            cout << "INCONSISTENT\n";
            return 0;
        }

        if (finished)
        {
            if (a[i] > b[i])
            {
                host_wins++;
            }
            else
            {
                guest_wins++;
            }
        }
    }

    int game_idx = n;
    int initial_server = (game_idx % 2 != 0) ? 1 : 0;
    int p = a[n - 1] + b[n - 1];
    int current_server = 0;

    if (p < 20)
    {
        int turn = p / 2;
        if (turn % 2 == 0)
        {
            current_server = initial_server;
        }
        else
        {
            current_server = 1 - initial_server;
        }
    }
    else
    {
        int turn = p - 20;
        if (turn % 2 == 0)
        {
            current_server = initial_server;
        }
        else
        {
            current_server = 1 - initial_server;
        }
    }

    if (current_server == 1)
    {
        cout << "GUEST\n";
    }
    else
    {
        cout << "HOST\n";
    }

    return 0;
}