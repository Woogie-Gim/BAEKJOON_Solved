#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 제약 : arr은 1 이상인 배열, 인덱스 i != j일 경우 arr[i] != arr[j]
// 입력 : 정수 배열 arr이 입력
// 처리 : 분기 처리 먼저, 길이가 1일 경우 -1만 answer에 push_back, 길이가 1 보다 클 경우 (이상도 아님) 먼저 가장 작은 수 인덱스 순회하여 파악, 그 인덱스 continue 후에 answer에 push_back
// 출력 : 배열 answer 순회 하며 출력

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    if ((int)arr.size() == 1)
    {
        answer.push_back(-1);
    }
    else if ((int)arr.size() > 1)
    {
        int idx;
        int num = INT_MAX;

        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (arr[i] < num)
            {
                num = arr[i];
                idx = i;
            }
        }

        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (i == idx) continue;

            answer.push_back(arr[i]);
        }
    }

    return answer;
}
