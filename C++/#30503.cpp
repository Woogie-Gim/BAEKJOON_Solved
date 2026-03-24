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

    vector<long long> arr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            long long k;
            cin >> l >> r >> k;

            int count = 0;
            for (int i = l; i <= r; i++)
            {
                if (arr[i] == k)
                {
                    count++;
                }
            }
            cout << count << "\n";
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;

            for (int i = l; i <= r; i++)
            {
                arr[i] = 0;
            }
        }
    }

    return 0;
}