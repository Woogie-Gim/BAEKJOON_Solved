#include <iostream>
using namespace std;

int main()
{
    int N, tempOne, tempTwo, ball = 1;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tempOne >> tempTwo;
        if (tempOne == ball)
        {
            ball = tempTwo;
        }
        else if (tempTwo == ball)
        {
            ball = tempOne;
        }
    }
    cout << ball;
    return 0;
}