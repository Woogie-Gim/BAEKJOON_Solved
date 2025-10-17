#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> cubes;
    
    for (long long i = 1;; i++)
    {
        long long c = i * i * i;
        if (c > 2000000000LL)
        {
            break;
        }
        cubes.push_back(c);
    }

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    for (int tc = 1; tc <= T; tc++)
    {
        long long A, B;
        cin >> A >> B;

        long long cnt =
            upper_bound(cubes.begin(), cubes.end(), B)
            - lower_bound(cubes.begin(), cubes.end(), A);

        cout << "Case #" << tc << ": " << cnt << "\n";
    }

    return 0;
}
