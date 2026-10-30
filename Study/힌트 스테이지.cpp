#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int n = cost.size();
    int m = hint.size();
    long long min_cost = LLONG_MAX;
    
    for (int mask = 0; mask < (1 << m); mask++) {
        vector<int> hints_count(n + 1, 0);
        long long current_total = 0;
        
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                current_total += hint[i][0]; 
                for (size_t j = 1; j < hint[i].size(); j++) {
                    int target_stage = hint[i][j];
                    if (target_stage <= n) {
                        hints_count[target_stage]++;
                    }
                }
            }
        }
        
        for (int stage = 0; stage < n; stage++) {
            int h_count = hints_count[stage + 1];
            int usable = min(h_count, (int)cost[stage].size() - 1);
            current_total += cost[stage][usable];
        }
        
        if (current_total < min_cost) {
            min_cost = current_total;
        }
    }
    
    return min_cost;
}