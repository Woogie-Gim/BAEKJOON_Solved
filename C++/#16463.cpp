#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int year = 2019;
    int day_of_week = 2; // 2019년 1월 1일은 화요일 (0=일, 1=월, 2=화)
    int result = 0;

    while (year <= n)
    {
        for (int m = 1; m <= 12; m++)
        {
            int dow_13 = (day_of_week + 12) % 7;
            if (dow_13 == 5) // 금요일
            {
                result++;
            }

            int days_in_month;
            if (m == 2)
            {
                bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
                days_in_month = leap ? 29 : 28;
            }
            else if (m == 4 || m == 6 || m == 9 || m == 11)
            {
                days_in_month = 30;
            }
            else
            {
                days_in_month = 31;
            }

            day_of_week = (day_of_week + days_in_month) % 7;
        }

        year++;
    }

    cout << result << '\n';
    return 0;
}
