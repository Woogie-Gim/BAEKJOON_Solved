#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row[26];
    int col[26];

    row['Q' - 'A'] = 0; col['Q' - 'A'] = 0;
    row['W' - 'A'] = 0; col['W' - 'A'] = 1;
    row['E' - 'A'] = 0; col['E' - 'A'] = 2;
    row['R' - 'A'] = 0; col['R' - 'A'] = 3;
    row['T' - 'A'] = 0; col['T' - 'A'] = 4;
    row['Y' - 'A'] = 0; col['Y' - 'A'] = 5;
    row['U' - 'A'] = 0; col['U' - 'A'] = 6;
    row['I' - 'A'] = 0; col['I' - 'A'] = 7;
    row['O' - 'A'] = 0; col['O' - 'A'] = 8;
    row['P' - 'A'] = 0; col['P' - 'A'] = 9;

    row['A' - 'A'] = 1; col['A' - 'A'] = 0;
    row['S' - 'A'] = 1; col['S' - 'A'] = 1;
    row['D' - 'A'] = 1; col['D' - 'A'] = 2;
    row['F' - 'A'] = 1; col['F' - 'A'] = 3;
    row['G' - 'A'] = 1; col['G' - 'A'] = 4;
    row['H' - 'A'] = 1; col['H' - 'A'] = 5;
    row['J' - 'A'] = 1; col['J' - 'A'] = 6;
    row['K' - 'A'] = 1; col['K' - 'A'] = 7;
    row['L' - 'A'] = 1; col['L' - 'A'] = 8;

    row['Z' - 'A'] = 2; col['Z' - 'A'] = 0;
    row['X' - 'A'] = 2; col['X' - 'A'] = 1;
    row['C' - 'A'] = 2; col['C' - 'A'] = 2;
    row['V' - 'A'] = 2; col['V' - 'A'] = 3;
    row['B' - 'A'] = 2; col['B' - 'A'] = 4;
    row['N' - 'A'] = 2; col['N' - 'A'] = 5;
    row['M' - 'A'] = 2; col['M' - 'A'] = 6;

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    for (int t = 0; t < T; t++)
    {
        string s;
        cin >> s;

        int time = s.length();

        for (int i = 0; i < (int)s.length() - 1; i++)
        {
            int r1 = row[s[i] - 'A'];
            int c1 = col[s[i] - 'A'];
            int r2 = row[s[i + 1] - 'A'];
            int c2 = col[s[i + 1] - 'A'];

            int dr = r1 - r2;
            int dc = c1 - c2;

            int abs_dr = dr > 0 ? dr : -dr;
            int abs_dc = dc > 0 ? dc : -dc;
            int sum_d = dr + dc;
            int abs_sum = sum_d > 0 ? sum_d : -sum_d;

            int max_dist = abs_dr;
            if (abs_dc > max_dist)
            {
                max_dist = abs_dc;
            }
            if (abs_sum > max_dist)
            {
                max_dist = abs_sum;
            }

            time += max_dist * 2;
        }

        cout << time << "\n";
    }

    return 0;
}