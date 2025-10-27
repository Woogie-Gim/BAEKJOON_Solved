#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int cnt12 = 0;        // 1~2학년: 성별 구분 없음 (통합)
    int cnt34[2] = {0, 0}; // 3~4학년: [여0, 남1]
    int cnt56[2] = {0, 0}; // 5~6학년: [여0, 남1]

    for (int i = 0; i < N; ++i)
    {
        int s, y;
        cin >> s >> y; // s: 0(여),1(남), y: 1~6

        if (y <= 2)
        {
            cnt12 += 1;
        }
        else if (y <= 4)
        {
            cnt34[s] += 1;
        }
        else
        {
            cnt56[s] += 1;
        }
    }

    int rooms = 0;
    rooms += (cnt12 + K - 1) / K;
    rooms += (cnt34[0] + K - 1) / K;
    rooms += (cnt34[1] + K - 1) / K;
    rooms += (cnt56[0] + K - 1) / K;
    rooms += (cnt56[1] + K - 1) / K;

    cout << rooms << '\n';
    
    return 0;
}
