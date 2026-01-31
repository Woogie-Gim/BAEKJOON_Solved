#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> men(N);
    for (int i = 0; i < N; i++)
    {
        cin >> men[i];
    }

    vector<string> women(N);
    for (int i = 0; i < N; i++)
    {
        cin >> women[i];
    }

    vector<int> indices(N);
    for (int i = 0; i < N; i++)
    {
        indices[i] = i;
    }

    int max_score = 0;

    while (true)
    {
        int current_total_score = 0;

        for (int i = 0; i < N; i++)
        {
            int score = 0;
            for (int k = 0; k < 4; k++)
            {
                if (men[i][k] != women[indices[i]][k])
                {
                    score++;
                }
            }
            current_total_score += score;
        }

        if (current_total_score > max_score)
        {
            max_score = current_total_score;
        }

        if (!next_permutation(indices.begin(), indices.end()))
        {
            break;
        }
    }

    cout << max_score;

    return 0;
}