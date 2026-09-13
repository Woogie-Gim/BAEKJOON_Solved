#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 제약 : arr은 자연수를 담은 배열, 인덱스 i != j일 경우 arr[i] != arr[j], divisor는 자연수, array는 길이 1 이상인 배열
// 입력 : 자연수 배열 arr 입력, divisor 입력
// 처리 : array의 각 요소들을 나누어 떨어지는 값을 순회하여 answer에 push_back 후 오름차순 정렬, 출력 직전에 분기 하나를 두고 size()가 0일 경우 -1 push_back
// 출력 : 반드시 오름차순 처리 후에 배열 출력

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
        else continue;
    }

    if ((int)answer.size() == 0)
    {
        answer.push_back(-1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}