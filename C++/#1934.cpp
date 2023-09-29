#include <iostream>
using namespace std;

int A, B;

int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {

    return (a * b) / gcd(a, b);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A >> B;
        cout << lcm(A, B) << "\n";
    }

    return 0;
}