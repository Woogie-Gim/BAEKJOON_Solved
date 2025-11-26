#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int planCount;
    cin >> planCount;

    long long sumStudyHours = 0;
    for (int i = 0; i < planCount; i++)
    {
        int timeNeeded;
        cin >> timeNeeded;
        sumStudyHours += timeNeeded;
    }

    long long totalHours = sumStudyHours;
    if (planCount > 1)
    {
        totalHours += 8LL * (planCount - 1);
    }

    long long days = totalHours / 24;
    long long hours = totalHours % 24;

    cout << days << " " << hours << '\n';

    return 0;
}
