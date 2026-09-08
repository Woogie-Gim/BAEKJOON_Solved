#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 1번 인덱스부터 사용. 0번은 비워둠
    vector<int> arr(n + 1, 0);
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    // 전처리 O(N)
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // 질의 처리. 각 O(1)
    for (int q = 0; q < m; q++)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << "\n";
    }

    return 0;
}