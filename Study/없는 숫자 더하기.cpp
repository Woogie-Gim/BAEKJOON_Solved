#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 제약 : numbers의 길이는 1 이상 9 이하, numbers의 모든 원소는 0 이상 9 이하, 모든 원소는 다른 값
// 입력 : 정수 배열 numbers가 입력
// 처리 : 임의의 크기가 10인 배열의 인덱스에 1씩 더해주고 최종 answer 값에 arr[i]의 값이 0인 경우 그 인덱스를 순회하며 더해주기
// 출력 : 순회하며 더해진 최종 값을 출력

int solution(vector<int> numbers) {
    int answer = 0;

    int arr[10] = { 0 };

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        arr[numbers[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 0)
        {
            answer += i;
        }
    } 

    return answer;
}