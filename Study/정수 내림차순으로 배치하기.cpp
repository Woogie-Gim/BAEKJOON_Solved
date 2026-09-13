#include <string>
#include <algorithm>

using namespace std;

// [제약] n은 1 이상 8,000,000,000 이하 → int 초과. long long 필수
// [입력] long long n
// [처리] 문자열로 바꿔 내림차순 정렬
// [반환] 정렬된 문자열을 long long으로

long long solution(long long n)
{
    string str = to_string(n);

    // 문자 '0'~'9'는 아스키 순서와 숫자 순서가 같음
    sort(str.begin(), str.end(), greater<char>());

    return stoll(str);
}