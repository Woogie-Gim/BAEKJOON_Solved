#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [제약] 배열 numbers의 원소 -10,000 이상, 10,000이하, numbers의 길이 1 이상 1,000이하
// [입력] 정수 배열 numbers 매개변수
// [처리] numbers의 각 원소를 2배 처리 for 문 순환 후 각각 *2 후에 answer에 저장
// [반환] 각 원소 *2 한 answer 배열 출력

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        int n;
        n = numbers[i] * 2;

        answer.push_back(n);
    }

    return answer;
}