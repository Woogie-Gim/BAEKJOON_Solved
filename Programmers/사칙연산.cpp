#include <vector>
#include <string>
#include <climits>
using namespace std;

int solution(vector<string> arr) {
    // 숫자와 연산자 분리
    vector<long long> nums;
    vector<char> ops;
    for (auto& s : arr) {
        if (s == "+" || s == "-") ops.push_back(s[0]);
        else nums.push_back(stoll(s));
    }

    int n = nums.size();
    // mx[i][j], mn[i][j]: 구간 i~j의 최대/최소값
    vector<vector<long long>> mx(n, vector<long long>(n, LLONG_MIN));
    vector<vector<long long>> mn(n, vector<long long>(n, LLONG_MAX));

    // 길이 1 구간 초기화
    for (int i = 0; i < n; i++)
        mx[i][i] = mn[i][i] = nums[i];

    // 구간 길이 늘려가며 병합
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) { // ops[k]로 분할
                if (ops[k] == '+') {
                    mx[i][j] = max(mx[i][j], mx[i][k] + mx[k+1][j]);
                    mn[i][j] = min(mn[i][j], mn[i][k] + mn[k+1][j]);
                } else {
                    mx[i][j] = max(mx[i][j], mx[i][k] - mn[k+1][j]);
                    mn[i][j] = min(mn[i][j], mn[i][k] - mx[k+1][j]);
                }
            }
        }
    }

    return (int)mx[0][n-1];
}