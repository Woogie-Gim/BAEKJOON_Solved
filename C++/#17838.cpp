#include<iostream>

using namespace std;

int CorrectCommand(string strTmp)
{
    if(strTmp.length() != 7)
        return 0;

    if( strTmp[0] == strTmp[1] &&
        strTmp[0] == strTmp[4] &&
        strTmp[6] == strTmp[2] &&
        strTmp[6] == strTmp[3] &&
        strTmp[6] == strTmp[5] &&
        strTmp[0] != strTmp[6])  
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main ()
{
    int nT = 0;

    cin >> nT;
    for(int t = 0; t < nT; t++)
    {
        string strTmp;
        cin >> strTmp;
        cout << CorrectCommand(strTmp) << "\n";
    }

    return 0;
}