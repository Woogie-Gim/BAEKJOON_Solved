#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int countArr[1001];
    int i;

    for (i = 0; i <= 1000; i++)
    {
        countArr[i] = 0;
    }

    for (i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        sum += x;
        countArr[x]++;
    }

    int average = sum / 10;

    int mode = 0;
    int maxCount = 0;
    for (i = 0; i <= 1000; i++)
    {
        if (countArr[i] > maxCount)
        {
            maxCount = countArr[i];
            mode = i;
        }
    }

    cout << average << '\n';
    cout << mode << '\n';

    return 0;
}
