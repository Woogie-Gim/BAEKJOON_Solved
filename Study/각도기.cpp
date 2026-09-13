#include <iostream>
#include <string>

using namespace std;

// 제약 : 매개변수 정수 angle의 볌위 0과 180 사이
// 입력 : 정수 angle 값이 입력
// 처리 : if 분기 처리, 예각일 때 answer에 1 더하기, 직각일 때 2 더하기, 둔각일 때 3 더하기, 평각일 때 4 더하기
// 출력 : 분기 처리 되어 값이 더해진 answer 값 출력

int solution(int angle) {
    int answer = 0;

    if (0 < angle && angle < 90)
    {
        answer += 1;
    }
    else if (angle == 90)
    {
        answer += 2;
    }
    else if (90 < angle && angle < 180)
    {
        answer += 3;
    }
    else if (angle == 180)
    {
        answer += 4;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int angle;

    cin >> angle;

    cout << solution(angle);

    return 0;
}