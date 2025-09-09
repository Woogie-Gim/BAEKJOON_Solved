#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int totalMinutes = 24 * 60;

    int currentMinutes = (long long)M * totalMinutes / N;

    int hour = currentMinutes / 60;
    int minute = currentMinutes % 60;

    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute << "\n";

    return 0;
}
