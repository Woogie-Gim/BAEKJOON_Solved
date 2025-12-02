#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k;
    cin >> n >> k;

    vector<long long> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    long long currentSum = 0;
    for (int i = 0; i < k; i++)
    {
        currentSum += numbers[i];
    }

    long long maxSum = currentSum;

    for (int i = k; i < n; i++)
    {
        currentSum -= numbers[i - k];
        currentSum += numbers[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    cout << maxSum;

    return 0;
}
