#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    // 순서 유지 불필요 → 정렬부터
    sort(arr.begin(), arr.end());

    int s = 0;
    int e = n - 1;
    int cnt = 0;

    while (s < e)
    {
        int sum = arr[s] + arr[e];

        if (sum == x)
        {
            cnt++;
            s++;            // 둘 중 아무거나
        }
        else if (sum < x)
        {
            s++;            // 크게 만들기
        }
        else
        {
            e--;            // 작게 만들기
        }
    }

    cout << cnt << "\n";
    return 0;
}