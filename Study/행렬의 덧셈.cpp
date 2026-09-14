// [제약] arr1, arr2 의 길이는 500을 넘지 않는다
// [입력] 행과 열 크기가 같은 두 행렬 arr1, arr2 입력
// [처리] 2개의 행렬 arr1, arr2 각 요소를 덧셈 결과를 answer에 입력, 2차원 배열이기 때문에 2중 for문으로 풀어내기
// [반환] 덧셈 결과가 입력된 answer 배열 출력

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    vector<vector<int>> answer;

    for (int i = 0; i < (int)arr1.size(); i++)
    {
        vector<int> row;                    // 이번 행을 담을 그릇

        for (int j = 0; j < (int)arr1[i].size(); j++)
        {
            row.push_back(arr1[i][j] + arr2[i][j]);
        }

        answer.push_back(row);              // 행 하나를 통째로 추가
    }

    return answer;
}