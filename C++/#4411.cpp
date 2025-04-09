#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;

    while (true) 
    {
        cin >> n;
        if (n == 0) break;

        vector<double> student(n);
        double sum = 0.0;

        for (int i = 0; i < n; ++i) 
        {
            cin >> student[i];
            sum += student[i];
        }

        int avg_cents = (int)((sum * 100 / n) + 0.5);
        
        double average = avg_cents / 100.0;

        double ans1 = 0.0, ans2 = 0.0;
        
        for (int i = 0; i < n; ++i) 
        {
            double diff = student[i] - average;
            if (diff > 0)
                ans1 += diff;
            else
                ans2 -= diff;
        }

        int result_cents = (int)((min(ans1, ans2) * 100) + 0.5); 
        int dollars = result_cents / 100;
        int cents = result_cents % 100;

        cout << "$" << dollars << ".";
        if (cents < 10) cout << "0"; 
        cout << cents << "\n";
    }

    return 0;
}
