#include <string>
#include <set>
#include <vector>

using namespace std;

// [제약] dirs 길이 1~500 / 좌표 범위 -5 ~ 5
// [반환] 처음 걸어본 길의 개수
//
// [조건 목록]
// 1. U D L R 에 따라 좌표 이동
// 2. 범위(-5~5)를 벗어나면 이동 무시 (명령 자체를 건너뜀)
// 3. 길은 양방향. A→B 와 B→A 는 같은 길
// 4. 이미 걸어본 길은 세지 않음

int solution(string dirs)
{
    set<vector<int>> used;      // {시작x, 시작y, 끝x, 끝y}
    int x = 0;
    int y = 0;

    for (int i = 0; i < (int)dirs.size(); i++)
    {
        int nx = x;
        int ny = y;

        if (dirs[i] == 'U') { ny = y + 1; }
        else if (dirs[i] == 'D') { ny = y - 1; }
        else if (dirs[i] == 'L') { nx = x - 1; }
        else { nx = x + 1; }

        // 조건 2. 범위 밖이면 이동 자체를 무시
        if (nx < -5 || nx > 5 || ny < -5 || ny > 5) { continue; }

        // 조건 3. 양방향 둘 다 기록
        used.insert({x, y, nx, ny});
        used.insert({nx, ny, x, y});

        x = nx;
        y = ny;
    }

    return (int)used.size() / 2;    // 양방향으로 넣었으니 절반
}
