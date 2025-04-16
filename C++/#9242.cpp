#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr0[15] = {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1};
int arr1[15] = {0,0,1,0,0,1,0,0,1,0,0,1,0,0,1};
int arr2[15] = {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1};
int arr3[15] = {1,1,1,0,0,1,1,1,1,0,0,1,1,1,1};
int arr4[15] = {1,0,1,1,0,1,1,1,1,0,0,1,0,0,1};
int arr5[15] = {1,1,1,1,0,0,1,1,1,0,0,1,1,1,1};
int arr6[15] = {1,1,1,1,0,0,1,1,1,1,0,1,1,1,1};
int arr7[15] = {1,1,1,0,0,1,0,0,1,0,0,1,0,0,1};
int arr8[15] = {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1};
int arr9[15] = {1,1,1,1,0,1,1,1,1,0,0,1,1,1,1};

int tmparr[15];

string input;
string num;

int main()
{
     
    getline(cin, input, '$');
    int numcount = input.length() / 5; 
    
    for(int i=0; i<input.length()/20; i++)
    {
        int index=0;
        
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<3; k++)
            {
                char c = input[i * 4 + j * numcount + k];
                if(c == '*')
                {
                    tmparr[index] = 1;
                }
                else
                {
                    tmparr[index] = 0;
                }
                index++;
            }
        }
        
        bool isnumber = false;
        
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr0[j] == tmparr[j])
            {
                num += '0';
                isnumber = true;
            }
            if(arr0[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr1[j] == tmparr[j])
            {
                num += '1';
                isnumber = true;
            }
            if(arr1[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr2[j] == tmparr[j])
            {
                num += '2';
                isnumber = true;
            }
            if(arr2[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr3[j] == tmparr[j])
            {
                num+='3';
                isnumber = true;
            }
            if(arr3[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr4[j] == tmparr[j])
            {
                num += '4';
                isnumber = true;
            }
            if(arr4[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr5[j] == tmparr[j])
            {
                num += '5';
                isnumber = true;
            }
            if(arr5[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr6[j] == tmparr[j])
            {
                num += '6';
                isnumber = true;
            }
            if(arr6[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr7[j] == tmparr[j])
            {
                num += '7';
                isnumber = true;
            }
            if(arr7[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr8[j] == tmparr[j])
            {
                num += '8';
                isnumber = true;
            }
            if(arr8[j] == tmparr[j]) continue;
            else break;
        }
        for(int j = 0; j < 15; j++)
        {
            if(j == 14 && arr9[j] == tmparr[j])
            {
                num += '9';
                isnumber = true;
            }
            if(arr9[j] == tmparr[j]) continue;
            else break;
        }
        if(!isnumber)
        {
            cout << "BOOM!!";
            return 0;
        }
    }
    
    int tmp = stoi(num);
    
    if(tmp%6 == 0)
    {
        cout << "BEER!!";
    }
    else{
        cout << "BOOM!!";
    }
    
    return 0;
}