#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int acount = 0;
    int bcount = 0;
    int atime = 0;
    int btime = 0;
    string last = "00:00";
    int stime;
    int ltime;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        stime = ((((s[0] - '0') * 10) + (s[1] - '0')) * 60) + (((s[3] - '0') * 10) + (s[4] - '0'));
        ltime = ((((last[0] - '0') * 10) + (last[1] - '0')) * 60) + (((last[3] - '0') * 10) + (last[4] - '0'));
        if (acount > bcount)
            atime += stime - ltime;
        else if (acount < bcount)
            btime += stime - ltime;
        last = s;
        if (a == 1)
            acount++;
        else if (a == 2)
            bcount++;
    }
    if (acount > bcount)
        atime += 2880 - (((((last[0] - '0') * 10) + (last[1] - '0')) * 60) + (((last[3] - '0') * 10) + (last[4] - '0')));
    else if (acount < bcount)
        btime += 2880 - (((((last[0] - '0') * 10) + (last[1] - '0')) * 60) + (((last[3] - '0') * 10) + (last[4] - '0')));
    cout.width(2);
    cout.fill('0');
    cout << atime / 60 << ":";
    cout.width(2);
    cout << atime % 60 << "\n";
    cout.width(2);
    cout << btime / 60 << ":";
    cout.width(2);
    cout << btime % 60;
}