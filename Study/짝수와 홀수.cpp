#include <iostream>
#include <string>

using namespace std;

// 제약 : 정수 num 은 int 범위의 정수
// 입력 : 정수 num 입력
// 처리 : if 조건문을 통해 정수 2와 나머지 연산 실행 후 값이 1일 경우 홀수, 0일 경우 짝수 분기 처리
// 출력 : 홀수일 경우 Odd, 짝수일 경우 Even 출력

string solution(int num) {

    string answer = "";


    if (num % 2 == 0)
    {
        answer += "Even";
    }
    else
    {
        answer += "Odd";
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num; 
    cin >> num;

    cout << solution(num);

    return 0;
}