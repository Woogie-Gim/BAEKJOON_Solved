#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, T;
    cin >> P >> T;

    vector<int> team_masks(T, 0);
    vector<bool> team_possible(T, true);

    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;

        int mask = 0;
        int len = s.length();

        for (int j = 0; j < len; j++)
        {
            int char_idx = s[j] - 'A';

            if (char_idx >= P)
            {
                team_possible[i] = false;
                break;
            }

            if ((mask >> char_idx) & 1)
            {
                team_possible[i] = false;
                break;
            }

            mask |= (1 << char_idx);
        }

        if (team_possible[i])
        {
            team_masks[i] = mask;
        }
    }

    int max_teams = 0;
    int limit = 1 << T;

    for (int i = 0; i < limit; i++)
    {
        int current_used_mask = 0;
        int count = 0;
        bool possible = true;

        for (int j = 0; j < T; j++)
        {
            if ((i >> j) & 1)
            {
                if (!team_possible[j])
                {
                    possible = false;
                    break;
                }

                if ((current_used_mask & team_masks[j]) != 0)
                {
                    possible = false;
                    break;
                }

                current_used_mask |= team_masks[j];
                
                count++;
            }
        }

        if (possible)
        {
            if (count > max_teams)
            {
                max_teams = count;
            }
        }
    }

    cout << max_teams;

    return 0;
}