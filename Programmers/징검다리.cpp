#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int lo = 1, hi = distance;
    while (lo <= hi) {
        int mid = (lo + hi) / 2; // 후보 최소 거리
        int removed = 0, prev = 0;

        // 간격이 mid 미만이면 해당 바위 제거
        for (int rock : rocks) {
            if (rock - prev < mid) removed++;
            else prev = rock;
        }
        if (distance - prev < mid) removed++; // 도착점 처리

        // 제거 수가 n 이하면 mid 달성 가능 -> 더 크게 시도
        if (removed <= n) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return answer;
}