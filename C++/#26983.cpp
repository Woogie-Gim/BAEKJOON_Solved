#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<string> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    auto merge_str = [&](const string& a, const string& b) {
        int max_overlap = 0;
        int limit = min(a.length(), b.length());
        for (int k = 1; k <= limit; k++)
        {
            bool ok = true;
            for (int i = 0; i < k; i++)
            {
                if (a[a.length() - k + i] != b[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                max_overlap = k;
            }
        }
        return a + b.substr(max_overlap);
    };

    int min_len = 1e9;

    do
    {
        string current = arr[0];
        for (int i = 1; i < N; i++)
        {
            current = merge_str(current, arr[i]);
        }
        if (current.length() < min_len)
        {
            min_len = current.length();
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << min_len << "\n";

    return 0;
}