#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long C;
    if (!(cin >> N >> C))
    {
        return 0;
    }

    vector<long long> vals;
    vector<int> counts;
    vector<int> first_idxs;

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        bool found = false;
        for (int j = 0; j < (int)vals.size(); j++)
        {
            if (vals[j] == num)
            {
                counts[j]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            vals.push_back(num);
            counts.push_back(1);
            first_idxs.push_back(i);
        }
    }

    int unique_count = vals.size();

    for (int i = 0; i < unique_count - 1; i++)
    {
        for (int j = 0; j < unique_count - 1 - i; j++)
        {
            bool swap_needed = false;
            
            if (counts[j] < counts[j + 1])
            {
                swap_needed = true;
            }
            else if (counts[j] == counts[j + 1])
            {
                if (first_idxs[j] > first_idxs[j + 1])
                {
                    swap_needed = true;
                }
            }

            if (swap_needed)
            {
                long long temp_val = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = temp_val;

                int temp_count = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp_count;

                int temp_idx = first_idxs[j];
                first_idxs[j] = first_idxs[j + 1];
                first_idxs[j + 1] = temp_idx;
            }
        }
    }

    bool first_print = true;
    for (int i = 0; i < unique_count; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            if (!first_print)
            {
                cout << " ";
            }
            cout << vals[i];
            first_print = false;
        }
    }
    cout << "\n";

    return 0;
}