#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        vector <int> junMop;
        vector <int> beeMop;

        int jun, bee;
        cin >> jun >>bee;
        
        for(int j = 0 ; j < jun ; j ++)
        {
            int jHp;
            cin >> jHp;
            junMop.push_back(jHp);
        }

        
        for(int b = 0 ; b < bee ; b ++)
        {
            int bHp;
            cin >> bHp;
            beeMop.push_back(bHp);
        }

        sort(junMop.begin(),junMop.end());
        sort(beeMop.begin(),beeMop.end());
        
        while(true)
        {
            if(junMop[0] > beeMop[0])
            {
                beeMop.erase(beeMop.begin() + 0);
            }
            else if(junMop[0] < beeMop[0])
            {
                junMop.erase(junMop.begin() + 0);
            }
            else if(junMop[0] == beeMop[0])
            {
                int lastJHp = junMop.back();
                int lastBHp = beeMop.back(); 
                
                if(lastJHp > lastBHp)
                {
                    beeMop.erase(beeMop.begin() + 0);
                }
                else if(lastJHp < lastBHp)
                {
                    junMop.erase(junMop.begin() + 0);
                }
                else
                {
                    beeMop.erase(beeMop.begin() + 0);
                }
            }
            
            
            if(junMop.size() == 0) 
            {
                cout << "B"<< "\n";
                break;   
            }
            
            if(beeMop.size() == 0) 
            {
                cout << "S"<< "\n";
                break;
            }
        }
    }    
}