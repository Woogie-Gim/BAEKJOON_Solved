#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// [제약] s는 공백으로 구분된 정수들. 음수와 여러 자리 수 가능
// [입력] 문자열 s
// [처리] 공백 단위로 잘라 정수로 변환 후 최대·최소 찾기
// [반환] "최솟값 최댓값" 형태의 문자열

string solution(string s)
{
    stringstream ss(s);
    vector<int> v;

    int x;
    while (ss >> x)             // 공백 단위로 하나씩 읽음
    {
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int mn = v[0];
    int mx = v[(int)v.size() - 1];

    return to_string(mn) + " " + to_string(mx);
}