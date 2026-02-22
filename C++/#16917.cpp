#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans1 = A * X + B * Y;

    long long min_req = X < Y ? X : Y;
    long long ans2 = 2 * C * min_req + A * (X - min_req) + B * (Y - min_req);

    long long max_req = X > Y ? X : Y;
    long long ans3 = 2 * C * max_req;

    long long final_ans = ans1;

    if (ans2 < final_ans)
    {
        final_ans = ans2;
    }

    if (ans3 < final_ans)
    {
        final_ans = ans3;
    }

    cout << final_ans << "\n";

    return 0;
}