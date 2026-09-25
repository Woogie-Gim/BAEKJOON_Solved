#include <vector>

using namespace std;

// [제약] n 1~200. computers는 n×n 인접 행렬
// [상태]     현재 컴퓨터 번호 (좌표 아님)
// [전이]     computers[now][i] == 1 인 i로 이동
// [가지치기] 이미 방문한 컴퓨터
// [종료]     연결된 곳 다 돌면 자동 종료 (반환값 없음)

vector<bool> visited;

void dfs(int now, vector<vector<int>>& computers)
{
    visited[now] = true;

    for (int i = 0; i < (int)computers.size(); i++)
    {
        if (visited[i] == true) { continue; }
        if (computers[now][i] == 0) { continue; }

        dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    visited.assign(n, false);
    int answer = 0;

    // 아직 방문 안 된 컴퓨터 = 새 네트워크
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            answer++;
            dfs(i, computers);      // 이 덩어리 전부 방문 처리
        }
    }

    return answer;
}
