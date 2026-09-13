#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 제약 : 정수 배열 numbers의 원소 0이상 1,000이하 값, 배열 numbers의 길이 1이상 100 이하, 정답의 소수 부분이 .0 or .5인 케이스만 입력으로
// 입력 : 정수 배열 vecotr numbers가 입력, 각 요소들이 존재하기 때문에 배열 순회 하며 push_back
// 처리 : 정수 배열을 순회 하면서 각 요소들 값을 더해주고 나눗셈 처리
// 출력 : 소수점 값을 출력해야 하기 때문에 double을 사용하여 출력

double solution(vector<int> numbers) {
    double answer = 0;

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        answer += numbers[i];
    }

    answer = answer / numbers.size();

    return answer;
}
