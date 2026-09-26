#include <vector>

using namespace std;

// [제약] 던전 수 1~8 → 최대 8! = 40,320. 완전탐색 가능
// [상태]     k(남은 피로도), cnt(탐험한 개수), visited(사용한 던전)
// [전이]     안 간 던전 중 최소 필요도를 만족하면 → k - 소모도, cnt + 1
// [가지치기] 이미 간 던전 / k가 최소 필요도보다 작음
// [종료]     더 갈 곳이 없으면 자동 종료. 매 단계 cnt 갱신

vector<bool> visited;
int maxCount;

void rec(int k, int cnt, vector<vector<int>>& dungeons)
{
    // 끝까지 안 가도 답이 될 수 있어 매 단계 갱신
    if (cnt > maxCount)
    {
        maxCount = cnt;
    }

    for (int i = 0; i < (int)dungeons.size(); i++)
    {
        if (visited[i] == true) { continue; }
        if (k < dungeons[i][0]) { continue; }       // 최소 필요도 미달

        visited[i] = true;
        rec(k - dungeons[i][1], cnt + 1, dungeons);
        visited[i] = false;                          // 복구
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    visited.assign(dungeons.size(), false);
    maxCount = 0;

    rec(k, 0, dungeons);
    return maxCount;
}
