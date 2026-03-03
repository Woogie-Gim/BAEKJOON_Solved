#include <iostream>
#include <vector>

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

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int max_len = 1;
    int inc_len = 1;
    int dec_len = 1;

    for (int i = 1; i < N; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            inc_len++;
        }
        else
        {
            inc_len = 1;
        }

        if (arr[i] <= arr[i - 1])
        {
            dec_len++;
        }
        else
        {
            dec_len = 1;
        }

        if (inc_len > max_len)
        {
            max_len = inc_len;
        }

        if (dec_len > max_len)
        {
            max_len = dec_len;
        }
    }

    cout << max_len << "\n";

    return 0;
}