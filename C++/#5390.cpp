#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        vector<int> firstGenome(N + 1);
        vector<int> secondGenome(N + 1);

        for (int i = 1; i <= N; i++)
        {
            cin >> firstGenome[i];
        }

        for (int i = 1; i <= N; i++)
        {
            cin >> secondGenome[i];
        }

        vector<int> diff(N + 1, 0);
        int nonZeroCount = 0;

        int segmentStart = 1;
        vector<int> segmentL;
        vector<int> segmentR;

        for (int i = 1; i <= N; i++)
        {
            int x = firstGenome[i];
            int before = diff[x];
            diff[x] = diff[x] + 1;
            if (before == 0 && diff[x] != 0)
            {
                nonZeroCount++;
            }
            if (before != 0 && diff[x] == 0)
            {
                nonZeroCount--;
            }

            int y = secondGenome[i];
            before = diff[y];
            diff[y] = diff[y] - 1;
            if (before == 0 && diff[y] != 0)
            {
                nonZeroCount++;
            }
            if (before != 0 && diff[y] == 0)
            {
                nonZeroCount--;
            }

            if (nonZeroCount == 0)
            {
                segmentL.push_back(segmentStart);
                segmentR.push_back(i);
                segmentStart = i + 1;
            }
        }

        for (int i = 0; i < (int)segmentL.size(); i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << segmentL[i] << "-" << segmentR[i];
        }
        cout << "\n";
    }

    return 0;
}
