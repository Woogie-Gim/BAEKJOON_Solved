#include <iostream>
#include <string>

using namespace std;

// s(>=0, decimal string)에 0..7의 작은 정수 k를 더해 결과를 반환
string addSmall(const string &s, int k)
{
    if (k == 0)
    {
        return s;
    }

    string t = s;
    int i = (int)t.size() - 1;
    int carry = k;

    while (i >= 0 && carry > 0)
    {
        int d = (t[i] - '0') + carry;
        t[i] = char('0' + (d % 10));
        carry = d / 10;
        i--;
    }
    if (carry > 0)
    {
        t.insert(t.begin(), char('0' + carry));
    }
    return t;
}

// 문자열 s의 값을 8로 나눈 나머지
int mod8(const string &s)
{
    int r = 0;
    for (char c : s)
    {
        r = (r * 10 + (c - '0')) & 7; // %8 대신 비트 연산
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string h0;
    if (!(cin >> h0))
    {
        return 0;
    }

    int r = mod8(h0);                // h0 % 8
    int dTo0 = (8 - r) % 8;          // 나머지를 0으로 만드는 최소 증가분
    int dTo5 = (5 - r + 8) % 8;      // 나머지를 5로 만드는 최소 증가분

    int k = dTo0;
    if (dTo5 < k)
    {
        k = dTo5;
    }

    // r가 0 또는 5면 k는 0이 되어 h0 그대로 출력
    cout << addSmall(h0, k) << "\n";
    
    return 0;
}
