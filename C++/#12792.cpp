#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<int> cycle_lengths;
    vector<int> visit_state(n, 0);
    vector<int> visit_step(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visit_state[i] == 0)
        {
            int curr = i;
            int step_count = 1;
            vector<int> path;

            while (true)
            {
                visit_state[curr] = 1;
                visit_step[curr] = step_count++;
                path.push_back(curr);

                int next = a[curr];

                if (visit_state[next] == 1) 
                {
                   int len = (step_count - 1) - visit_step[next] + 1;
                    cycle_lengths.push_back(len);
                    break; 
                }
                else if (visit_state[next] == 2)
                {
                    break;
                }

                curr = next;
            }

            for (int node : path)
            {
                visit_state[node] = 2;
            }
        }
    }

    sort(cycle_lengths.begin(), cycle_lengths.end());
    cycle_lengths.erase(unique(cycle_lengths.begin(), cycle_lengths.end()), cycle_lengths.end());

    if (!cycle_lengths.empty() && cycle_lengths[0] == 1)
    {
        cout << -1;
        return 0;
    }

    vector<int> minimal_lengths;
    for (int len : cycle_lengths)
    {
        bool is_multiple = false;
        for (int min_len : minimal_lengths)
        {
            if (len % min_len == 0)
            {
                is_multiple = true;
                break;
            }
        }
        if (!is_multiple)
        {
            minimal_lengths.push_back(len);
        }
    }

    for (long long k = 2; k <= 2000000000; k++)
    {
        bool possible = true;
        for (int len : minimal_lengths)
        {
            if (k % len == 0)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << k;
            return 0;
        }
    }

    cout << -1;

    return 0;
}