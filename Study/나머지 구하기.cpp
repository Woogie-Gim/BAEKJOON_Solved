#include <iostream>

using namespace std;

// 제약 : 정수 0 < num1, num2 <= 100, int로 커버 가능
// 입력 : 정수 num1, num2
// 처리 : num1 % num2 로 나머지 연산 실행
// 출력 : 나머지 연산 실행 값 출력

int solution(int num1, int num2) 
{
    int answer = -1;

    answer = num1 % num2;

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num1, num2;

    cin >> num1 >> num2;

    cout << solution(num1, num2);

    return 0;
}