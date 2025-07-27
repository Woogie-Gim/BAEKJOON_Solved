#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string words, target;
    int ans = 0;

    cin >> N;
    cin >> words;
    cin >> M;
    cin >> target;

    int idx = N - 1;
    int turn = 0;
    int tidx = 0;

    while (true)
    {
        if (tidx == M)
        {
            break;
        }

        turn++;
        idx++;

        if (idx == N)
        {
            idx = 0;
        }

        if (words[idx] == target[tidx])
        {
            tidx++;
            ans += turn;
            turn = 0;
        }

        if (turn >= N)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
