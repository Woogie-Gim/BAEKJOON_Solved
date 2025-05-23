#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int to_minutes(const string& time_str) 
{
    stringstream ss(time_str);
    string h, m;
    getline(ss, h, ':');
    getline(ss, m);
    return stoi(h) * 60 + stoi(m);
}

int main() 
{
    vector<string> days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string sA, sB, sC, sD;

    getline(cin, sA);
    getline(cin, sB);
    getline(cin, sC);
    getline(cin, sD);

    int A = to_minutes(sA);
    int B = to_minutes(sB);
    int C = to_minutes(sC);
    int D = to_minutes(sD);

    for (int i = 0; i < 1440; ++i) 
    {
        if (A == B) 
        {
            cout << days[(A / 1440) % 7] << endl;
            printf("%02d:%02d\n", (A / 60) % 24, A % 60);
            return 0;
        }
        if (A < B) 
        {
            A += C;
        } 
        else if (A > B) 
        {
            B += D;
        }
    }

    cout << "Never" << "\n";
    
    return 0;
}
