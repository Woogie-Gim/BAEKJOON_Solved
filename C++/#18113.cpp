#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long K, M;
    cin >> N >> K >> M;

    vector<long long> len;
    len.resize(N);

    long long maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        long long L;
        cin >> L;

        long long R = 0;
        if (L <= K)
        {
            R = 0;
        }
        else if (L < 2 * K)
        {
            R = L - K;
        }
        else
        {
            R = L - 2 * K;
        }

        len[i] = R;
        if (R > maxLen)
        {
            maxLen = R;
        }
    }

    long long totalPiecesAt1 = 0;
    for (int i = 0; i < N; i++)
    {
        totalPiecesAt1 += len[i];
        if (totalPiecesAt1 >= M)
        {
            break;
        }
    }

    if (totalPiecesAt1 < M || maxLen == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    long long lo = 1;
    long long hi = maxLen;
    long long ans = 1;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;

        long long cnt = 0;
        for (int i = 0; i < N; i++)
        {
            cnt += (len[i] / mid);
            if (cnt >= M)
            {
                break;
            }
        }

        if (cnt >= M)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
