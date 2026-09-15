#include <vector>

using namespace std;

// [상태]     n(옮길 개수), from(출발), to(목표), via(보조)
// [전이]     n-1개를 via로 → 1개를 to로 → n-1개를 via에서 to로
// [가지치기] 없음
// [종료]     n == 0 이면 아무것도 안 함

vector<vector<int>> answer;

void hanoi(int n, int from, int to, int via)
{
    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, from, via, to);    // 목표와 보조를 바꿔서
    answer.push_back({from, to});   // 실제로 옮기는 건 여기뿐
    hanoi(n - 1, via, to, from);    // 출발과 보조를 바꿔서
}

vector<vector<int>> solution(int n)
{
    answer.clear();
    hanoi(n, 1, 3, 2);
    return answer;
}