#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<long long> current_level;
    current_level.push_back(1);

    for (int i = 1; i < N; i++)
    {
        vector<long long> next_level;
        
        for (int j = 0; j < (int)current_level.size(); j++)
        {
            long long V = current_level[j];

            next_level.push_back(V * 2);

            if ((V - 1) % 3 == 0)
            {
                long long cand = (V - 1) / 3;
                
                if (cand > 1 && cand % 2 == 1)
                {
                    next_level.push_back(cand);
                }
            }
        }
        
        current_level = next_level;
    }

    sort(current_level.begin(), current_level.end());

    cout << current_level.size() << "\n";

    for (int i = 0; i < (int)current_level.size(); i++)
    {
        cout << current_level[i] << "\n";
    }

    return 0;
}