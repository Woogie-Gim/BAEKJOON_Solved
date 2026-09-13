#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 제약 : 배열 arr의 길이는 1 이상 100 이하, 원소는 -10,000 이상 10,000 이하인 정수
// 입력 : 정수를 담고 있는 배열 arr 입력
// 처리 : 배열을 순회 하며 원소들을 더해주고 마지막 answer에 평균 값 구해주기
// 출력 : 구한 평균 값 출력, 소수점 출력이기 때문에 나눗셈 계산 직전에 캐스팅 미리 하기

double solution(vector<int> arr) {
    double answer = 0;

    int ans = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        ans += arr[i];
    }

    answer = (double)ans / (int)arr.size();

    return answer;
}