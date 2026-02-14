#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char lighter_start;
    cin >> lighter_start;

    string smallant_input;
    cin >> smallant_input;

    int n = smallant_input.length();
    int limit = 1 << n;
    long long valid_count = 0;

    for (int i = 1; i < limit; i++)
    {
        string sub_seq = "";
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                sub_seq += smallant_input[j];
            }
        }

        bool possible = true;
        char current_lighter = lighter_start;
        bool prev_lighter_win = false;

        for (int k = 0; k < (int)sub_seq.length(); k++)
        {
            char current_smallant = sub_seq[k];
            bool is_draw = false;
            bool lighter_wins = false;

            if (current_lighter == current_smallant)
            {
                is_draw = true;
            }
            else
            {
                if (current_lighter == 'R')
                {
                    if (current_smallant == 'S')
                    {
                        lighter_wins = true;
                    }
                }
                else if (current_lighter == 'S')
                {
                    if (current_smallant == 'P')
                    {
                        lighter_wins = true;
                    }
                }
                else if (current_lighter == 'P')
                {
                    if (current_smallant == 'R')
                    {
                        lighter_wins = true;
                    }
                }
            }

            if (prev_lighter_win && is_draw)
            {
                possible = false;
                break;
            }

            prev_lighter_win = lighter_wins;
            current_lighter = current_smallant;
        }

        if (possible)
        {
            valid_count++;
            valid_count %= 1000000007;
        }
    }

    cout << valid_count;

    return 0;
}