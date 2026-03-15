#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t))
    {
        return 0;
    }

    while (t > 0)
    {
        t--;

        int n;
        long long k;
        cin >> n >> k;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        long long min_diff = 4000000000LL;
        int count = 0;

        while (left < right)
        {
            long long sum = arr[left] + arr[right];
            long long diff = sum - k;
            
            if (diff < 0)
            {
                diff = -diff;
            }

            if (diff < min_diff)
            {
                min_diff = diff;
                count = 1;
            }
            else if (diff == min_diff)
            {
                count++;
            }

            if (sum < k)
            {
                left++;
            }
            else if (sum > k)
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }

        cout << count << "\n";
    }

    return 0;
}