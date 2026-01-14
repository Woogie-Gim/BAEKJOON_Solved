#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    for (int classIdx = 1; classIdx <= K; classIdx++)
    {
        int N;
        cin >> N;

        vector<int> scores(N);
        for (int i = 0; i < N; i++)
        {
            cin >> scores[i];
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int mx = scores[0];
        int mn = scores[N - 1];

        int largestGap = 0;
        for (int i = 0; i + 1 < N; i++)
        {
            int gap = scores[i] - scores[i + 1];
            if (gap > largestGap)
            {
                largestGap = gap;
            }
        }

        cout << "Class " << classIdx << '\n';
        cout << "Max " << mx << ", Min " << mn << ", Largest gap " << largestGap << '\n';
    }

    return 0;
}
