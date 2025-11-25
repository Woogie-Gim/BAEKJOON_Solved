#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> cnt(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        cnt[b]++;
    }

    bool ok = true;

    for (int j = 2; j <= N; j++)
    {
        if (cnt[j] != 0 && cnt[j] != j - 1)
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << -1;
        return 0;
    }

    string result;
    result.reserve(N - 1);

    for (int j = 2; j <= N; j++)
    {
        if (cnt[j] == 0)
        {
            result.push_back('N');
        }
        else
        {
            result.push_back('E');
        }
    }

    cout << result;

    return 0;
}
