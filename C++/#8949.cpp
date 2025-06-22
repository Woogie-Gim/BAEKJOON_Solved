#include<iostream>
#include<string>


using namespace std;

int swipe(string &a, string &b) 
{
    string temp;

    if (a.size() >= b.size())
    {
        return 1;
    }

    temp = b;
    b = a;
    a = temp;

    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input1;
    string input2;

    int answer[20];

    cin >> input1 >> input2;

    swipe(input1, input2);

    int dif = input1.size() - input2.size();

    for (int i = 0; i < input1.size(); i++) 
    {
        if (i - dif >=0) 
        {
            answer[i] = input1[i] + input2[i - dif] - '0' - '0';
        }
        else 
        {
            answer[i] = input1[i]-'0';

        }
    }

    for(int i = 0; i < input1.size(); i++)
    {
        cout << answer[i];
    }
}