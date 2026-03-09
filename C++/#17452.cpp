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

    int best_c1[26];
    int best_id1[26];
    int best2_c1[26];
    int best2_id1[26];
    
    int best_c2[26];
    int best_id2[26];
    int best2_c2[26];
    int best2_id2[26];

    for (int i = 0; i < 26; i++)
    {
        best_c1[i] = 1000000000;
        best_id1[i] = -1;
        best2_c1[i] = 1000000000;
        best2_id1[i] = -1;
        
        best_c2[i] = 1000000000;
        best_id2[i] = -1;
        best2_c2[i] = 1000000000;
        best2_id2[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;

        int len = S.length();

        for (int c = 0; c < 26; c++)
        {
            int first_idx = -1;
            int last_idx = -1;
            char ch = 'a' + c;

            for (int k = 0; k < len; k++)
            {
                if (S[k] == ch)
                {
                    if (first_idx == -1)
                    {
                        first_idx = k;
                    }
                    last_idx = k;
                }
            }

            if (first_idx != -1)
            {
                int cost1 = len - 1 - last_idx;
                int cost2 = first_idx;

                if (cost1 < best_c1[c])
                {
                    best2_c1[c] = best_c1[c];
                    best2_id1[c] = best_id1[c];
                    best_c1[c] = cost1;
                    best_id1[c] = i;
                }
                else if (cost1 < best2_c1[c])
                {
                    best2_c1[c] = cost1;
                    best2_id1[c] = i;
                }

                if (cost2 < best_c2[c])
                {
                    best2_c2[c] = best_c2[c];
                    best2_id2[c] = best_id2[c];
                    best_c2[c] = cost2;
                    best_id2[c] = i;
                }
                else if (cost2 < best2_c2[c])
                {
                    best2_c2[c] = cost2;
                    best2_id2[c] = i;
                }
            }
        }
    }

    int global_min = 1000000000;

    for (int c = 0; c < 26; c++)
    {
        if (best_id1[c] != -1 && best2_id1[c] != -1)
        {
            int current_min = 1000000000;

            if (best_id1[c] != best_id2[c])
            {
                int cost = best_c1[c] + best_c2[c];
                if (cost < current_min)
                {
                    current_min = cost;
                }
            }

            if (best_id1[c] != best2_id2[c] && best2_id2[c] != -1)
            {
                int cost = best_c1[c] + best2_c2[c];
                if (cost < current_min)
                {
                    current_min = cost;
                }
            }

            if (best2_id1[c] != best_id2[c] && best2_id1[c] != -1)
            {
                int cost = best2_c1[c] + best_c2[c];
                if (cost < current_min)
                {
                    current_min = cost;
                }
            }

            if (best2_id1[c] != best2_id2[c] && best2_id1[c] != -1 && best2_id2[c] != -1)
            {
                int cost = best2_c1[c] + best2_c2[c];
                if (cost < current_min)
                {
                    current_min = cost;
                }
            }

            if (current_min < global_min)
            {
                global_min = current_min;
            }
        }
    }

    if (global_min == 1000000000)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << global_min << "\n";
    }

    return 0;
}