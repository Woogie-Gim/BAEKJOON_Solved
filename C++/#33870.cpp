#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    vector<int> B(M + 1);
    for (int d = 1; d <= M; d++)
    {
        cin >> B[d];
    }

    vector<int> lastBrushed(N + 1, 0);
    vector<bool> tangled(N + 1, false);

    for (int day = 1; day <= M; day++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (!tangled[i] && day - lastBrushed[i] >= A[i] + 1)
            {
                tangled[i] = true;
            }
        }

        int k = B[day];
        if (tangled[k])
        {
            if (lastBrushed[k] == day - 1)
            {
                tangled[k] = false;
            }
            lastBrushed[k] = day;
        }
        else
        {
            lastBrushed[k] = day;
        }
    }

    int day = M + 1;
    for (int i = 1; i <= N; i++)
    {
        if (!tangled[i] && day - lastBrushed[i] >= A[i] + 1)
        {
            tangled[i] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (tangled[i])
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
