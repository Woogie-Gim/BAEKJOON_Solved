#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string expr;
    cin >> expr;

    long long result = 0;
    long long currentNumber = 0;
    char lastOp = 0;
    bool hasResult = false;
    bool hasNumber = false;
    bool printed = false;

    int length = (int)expr.size();

    for (int i = 0; i < length; i++)
    {
        char ch = expr[i];

        if (ch >= '0' && ch <= '9')
        {
            currentNumber = currentNumber * 10 + (long long)(ch - '0');
            hasNumber = true;
        }
        else
        {
            if (hasNumber)
            {
                if (!hasResult)
                {
                    result = currentNumber;
                    hasResult = true;
                }
                else
                {
                    if (lastOp == 'S')
                    {
                        result = result - currentNumber;
                    }
                    else if (lastOp == 'M')
                    {
                        result = result * currentNumber;
                    }
                    else if (lastOp == 'U')
                    {
                        result = result / currentNumber;
                    }
                    else if (lastOp == 'P')
                    {
                        result = result + currentNumber;
                    }
                }

                currentNumber = 0;
                hasNumber = false;
            }

            if (ch == 'C')
            {
                if (printed)
                {
                    cout << ' ';
                }
                cout << result;
                printed = true;
            }
            else
            {
                lastOp = ch; // S, M, U, P
            }
        }
    }

    if (!printed)
    {
        cout << "NO OUTPUT";
    }

    return 0;
}
