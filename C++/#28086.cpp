#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_octal_digit(char c)
{
    return '0' <= c && c <= '7';
}

long long parse_octal(const string &s)
{
    // s는 (+/- 없는) 순수 8진수 숫자 문자열이라고 가정
    long long v = 0;
    for (char c : s)
    {
        v = v * 8 + (c - '0');
    }
    return v;
}

string to_octal(long long x)
{
    if (x == 0)
    {
        return "0";
    }
    bool neg = (x < 0);
    if (neg)
    {
        x = -x;
    }
    string t;
    while (x > 0)
    {
        int d = int(x % 8);
        t.push_back(char('0' + d));
        x /= 8;
    }
    // 뒤집기
    for (int i = 0, j = (int)t.size() - 1; i < j; i++, j--)
    {
        char tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    if (neg)
    {
        return "-" + t;
    }
    return t;
}

long long floor_div(long long a, long long b)
{
    long long q = a / b;
    long long r = a % b;
    if (r != 0 && ((a < 0) ^ (b < 0)))
    {
        q--; // 음수 방향으로 한 칸 더
    }
    return q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    if (!(cin >> s))
    {
        return 0;
    }

    int n = (int)s.size();

    // 1) A 파싱
    int i = 0;
    bool negA = false;
    if (i < n && s[i] == '-')
    {
        negA = true;
        i++;
    }
    int startA = i;
    while (i < n && is_octal_digit(s[i]))
    {
        i++;
    }
    if (startA == i || i >= n)
    {
        cout << "invalid\n";
        return 0;
    }

    string strA = s.substr(startA, i - startA);
    char op = s[i]; // 연산자
    if (!(op == '+' || op == '-' || op == '*' || op == '/'))
    {
        cout << "invalid\n";
        return 0;
    }
    i++;

    // 2) B 파싱
    bool negB = false;
    if (i < n && s[i] == '-')
    {
        negB = true;
        i++;
    }
    int startB = i;
    while (i < n && is_octal_digit(s[i]))
    {
        i++;
    }
    if (startB == i || i != n)
    {
        cout << "invalid\n";
        return 0;
    }
    string strB = s.substr(startB, n - startB);

    // 3) 8진수 -> 10진수 정수
    long long A = parse_octal(strA);
    if (negA) A = -A;
    long long B = parse_octal(strB);
    if (negB) B = -B;

    // 4) 계산
    if (op == '/' && B == 0)
    {
        cout << "invalid\n";
        return 0;
    }

    long long R = 0;
    if (op == '+')
    {
        R = A + B;
    }
    else if (op == '-')
    {
        R = A - B;
    }
    else if (op == '*')
    {
        R = A * B;
    }
    else // '/'
    {
        R = floor_div(A, B); // ⌊A/B⌋
    }

    // 5) 8진수로 출력
    cout << to_octal(R) << "\n";
    return 0;
}
