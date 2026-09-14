#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [제약] 행과 열 길이 2~100, 원소는 -10~20, 곱셈 가능한 크기 보장
// [입력] arr1 (n×k), arr2 (k×m)
// [처리] answer[i][j] = arr1의 i행과 arr2의 j열을 짝지어 곱한 합
// [반환] n×m 크기의 2차원 배열

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    int n = (int)arr1.size();       // arr1의 행 개수
    int k = (int)arr1[0].size();    // arr1의 열 개수 = arr2의 행 개수
    int m = (int)arr2[0].size();    // arr2의 열 개수

    for (int i = 0; i < n; i++)
    {
        vector<int> row;            // i번째 행을 담을 그릇

        for (int j = 0; j < m; j++)
        {
            int sum = 0;

            // arr1의 i행과 arr2의 j열을 짝지어 곱하며 누적
            for (int x = 0; x < k; x++)
            {
                sum = sum + arr1[i][x] * arr2[x][j];
            }

            row.push_back(sum);     // 한 칸 완성
        }

        answer.push_back(row);      // 한 행 완성
    }

    return answer;
}