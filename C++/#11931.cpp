#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<int> arr(k);

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    // 내림차순 정렬
    sort(arr.begin(), arr.end(), greater<int>());

    // 출력
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}
