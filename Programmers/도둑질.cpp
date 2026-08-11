#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 선형 구간 [start, end] 도둑질 최댓값
int robLinear(vector<int>& money, int start, int end) {
    int prev = 0, curr = 0; // prev: i-2, curr: i-1
    for (int i = start; i <= end; i++) {
        int take = prev + money[i]; // 현재 집 털기
        int skip = curr;            // 현재 집 건너뛰기
        prev = curr;
        curr = max(take, skip);
    }
    return curr;
}

int solution(vector<int> money) {
    int n = money.size();
    // 첫 집 포함(마지막 제외) vs 마지막 집 포함(첫 집 제외)
    int case1 = robLinear(money, 0, n - 2);
    int case2 = robLinear(money, 1, n - 1);
    return max(case1, case2);
}