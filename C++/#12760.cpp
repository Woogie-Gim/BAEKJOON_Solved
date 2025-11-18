#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector< vector<int> > cards(N, vector<int>(M));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> cards[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        sort(cards[i].begin(), cards[i].end(), greater<int>());
    }

    vector<int> score(N, 0);

    for (int round = 0; round < M; ++round)
    {
        int best = -1;

        for (int i = 0; i < N; ++i)
        {
            if (cards[i][round] > best)
            {
                best = cards[i][round];
            }
        }

        for (int i = 0; i < N; ++i)
        {
            if (cards[i][round] == best)
            {
                score[i] += 1;
            }
        }
    }

    int maxScore = 0;
    
    for (int i = 0; i < N; ++i)
    {
        if (score[i] > maxScore)
        {
            maxScore = score[i];
        }
    }

    bool first = true;
    
    for (int i = 0; i < N; ++i)
    {
        if (score[i] == maxScore)
        {
            if (!first)
            {
                cout << ' ';
            }
            cout << (i + 1);
            first = false;
        }
    }
    
    cout << '\n';

    return 0;
}
