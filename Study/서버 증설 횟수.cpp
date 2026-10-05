#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> mp;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for(int i=0; i<players.size(); i++) {
        if (players[i]/m > 0) {
            int tmp = players[i]/m-mp[i];
            if (tmp <= 0) continue;
            for(int j=i; j<i+k; j++) {
                mp[j]+=tmp;
            }

            answer+=tmp;
        }
    }
    
    return answer;
}