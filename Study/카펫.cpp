#include <vector>

using namespace std;

// [제약] brown 8~5000, yellow 1~2,000,000 / 가로 >= 세로
// [처리] 전체 넓이의 약수 쌍을 세로 기준으로 훑으며
//        안쪽 (w-2)*(h-2) 가 yellow 와 맞는지 확인
// [반환] {가로, 세로}

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int total = brown + yellow;

    // 가로 >= 세로 이므로 세로는 제곱근 이하
    for (int h = 1; h * h <= total; h++)
    {
        if (total % h != 0) { continue; }

        int w = total / h;

        if ((w - 2) * (h - 2) != yellow) { continue; }

        answer.push_back(w);
        answer.push_back(h);
        break;
    }

    return answer;
}