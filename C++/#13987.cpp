#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
    vector<int> first_die(6), second_die(6);
    
    int p = 0, q = 0;

    for (int i = 0; i < 6; i++)
        cin >> first_die[i];
    for (int i = 0; i < 6; i++)
        cin >> second_die[i];

    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            if (first_die[i] > second_die[j])
                p++;
            else if (first_die[i] == second_die[j])
                q++;
        }
    }

    double result = static_cast<double>(p) / (36 - q);
    
    cout << fixed << setprecision(5) << result << "\n";

    return 0;
}
