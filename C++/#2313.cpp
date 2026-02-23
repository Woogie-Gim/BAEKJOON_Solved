#include <iostream>
#include <vector>

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

    long long total_sum = 0;
    vector<pair<int, int>> selections(n);

    for (int i = 0; i < n; i++)
    {
        int L;
        cin >> L;

        long long global_max = -1000000000000000000LL;
        int b_st = -1;
        int b_len = -1;

        long long current_sum = -1000000000000000000LL;
        int c_st = -1;

        for (int j = 1; j <= L; j++)
        {
            long long val;
            cin >> val;

            if (current_sum <= 0)
            {
                current_sum = val;
                c_st = j;
            }
            else
            {
                current_sum += val;
            }

            int c_len = j - c_st + 1;

            if (current_sum > global_max)
            {
                global_max = current_sum;
                b_st = c_st;
                b_len = c_len;
            }
            else if (current_sum == global_max)
            {
                if (c_len < b_len)
                {
                    b_st = c_st;
                    b_len = c_len;
                }
            }
        }

        total_sum += global_max;
        selections[i].first = b_st;
        selections[i].second = b_st + b_len - 1;
    }

    cout << total_sum << "\n";
    
    for (int i = 0; i < n; i++)
    {
        cout << selections[i].first << " " << selections[i].second << "\n";
    }

    return 0;
}