#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    for (int i = 1; i <= num; i++)
    {
        double sides;
        cin >> sides;
        cout << fixed << setprecision(10) << sides / 6 << "\n";
    }
    
    return 0;
}