#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> high(N);
    vector<int> low(M);

    for (int i = 0; i < N; i++)
    {
        cin >> high[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> low[i];
    }

    sort(high.begin(), high.end());
    sort(low.begin(), low.end());

    int j = 0;
    int pairs = 0;

    for (int i = 0; i < N; i++)
    {
        if (j < M && low[j] < high[i])
        {
            pairs++;
            j++;
        }
    }

    cout << (N + pairs) << '\n';
    
    return 0;
}
