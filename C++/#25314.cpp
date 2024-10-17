#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string intstr="int";
    string longstr="long ";
    string res="";
    for(int i=0;i<n/4;i++) res+=longstr;
    cout<<res<<intstr;
}