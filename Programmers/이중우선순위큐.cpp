#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> pq;

    for (const string& op : operations) {
        char cmd = op[0];
        int num = stoi(op.substr(2));

        if (cmd == 'I') {
            // 삽입
            pq.insert(num);
        } else {
            if (pq.empty()) continue;
            if (num == 1) {
                // 최댓값 삭제
                pq.erase(prev(pq.end()));
            } else {
                // 최솟값 삭제
                pq.erase(pq.begin());
            }
        }
    }

    if (pq.empty()) return {0, 0};
    return {*pq.rbegin(), *pq.begin()};
}