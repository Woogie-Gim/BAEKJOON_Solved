#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0;
    int e = 0;
    int total = 0;
    int cnt = 0;

    while (e <= n)
    {
        if (total == m)
        {
            cnt++;
        }

        if (total < m)
        {
            // 합을 키움. 범위 체크 먼저
            if (e == n)
            {
                break;
            }
            total = total + arr[e];
            e++;
        }
        else
        {
            // 합을 줄임
            total = total - arr[s];
            s++;
        }
    }

    cout << cnt << "\n";
    return 0;
}