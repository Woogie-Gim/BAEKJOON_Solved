#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 제약 : num1, 2의 범위 -50000 <= num <=50000, int로 커버 가능
// 입력 : 정수 num1, num2 입력
// 처리 : 입력 받은 num1, num2 를 뺄셈
// 반환 : 뺀 값을 반환 및 출력


int solution(int num1, int num2)
{
	int answer = 0;

	answer = num1 - num2;

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
