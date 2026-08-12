#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long maxTime = *max_element(times.begin(), times.end());
    long long lo = 1;
    long long hi = maxTime * n;   // 가장 느린 심사관 혼자 n명 처리
    long long answer = hi;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        long long people = 0;
        for (int t : times) {
            people += mid / t;
            if (people >= n) break;   // 오버플로 방지 겸 조기 종료
        }

        if (people >= n) {
            answer = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return answer;
}