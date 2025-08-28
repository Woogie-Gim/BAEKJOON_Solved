#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; tc++)
    {
        long long M, D, W;
        cin >> M >> D >> W;

        long long rows = 0;
        long long start = 0;

        for (long long m = 0; m < M; m++)
        {
            rows += (start + D + W - 1) / W;

            long long last_col = (start + D - 1) % W;
            start = (last_col + 1) % W;
        }

        cout << "Case #" << tc << ": " << rows << "\n";
    }
    return 0;
}
