#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int max_money = 0;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int money = 0;

        if (a == b && b == c)
        {
            money = 10000 + a * 1000;
        }
        else if (a == b || a == c)
        {
            money = 1000 + a * 100;
        }
        else if (b == c)
        {
            money = 1000 + b * 100;
        }
        else
        {
            int max_face = a;
            if (b > max_face)
            {
                max_face = b;
            }
            if (c > max_face)
            {
                max_face = c;
            }
            money = max_face * 100;
        }

        if (money > max_money)
        {
            max_money = money;
        }
    }

    cout << max_money;

    return 0;
}