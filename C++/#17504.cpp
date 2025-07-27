#include <iostream>
#include <vector>

using namespace std;

using P = pair<long long, long long>;

int N;
vector<int> number;
P ans = {1, 1};

long long Uclid(long long x, long long y)
{
    while (y != 0)
    {
        long long tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

P Add(int x, P y)
{
    if (x >= 1)
    {
        y.first += (x * y.second);
    }
    else
    {
        y.first = (-x * y.second) - y.first;
    }

    long long div = Uclid(y.first, y.second);
    y.first /= div;
    y.second /= div;

    return y;
}

P Reverse(P x)
{
    return {x.second, x.first};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        number.push_back(x);
    }

    ans.second = number[N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        ans = Add(number[i], ans);
        ans = Reverse(ans);
    }

    ans = Add(-1, ans);

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
