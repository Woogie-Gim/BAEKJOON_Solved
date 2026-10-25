#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = 0;  
    int count = -1;  
    int attack_count = 0;
    int hp = health;
    int end_t = attacks[attacks.size() - 1][0];

    while (t <= end_t) {
        int attack_time = attacks[attack_count][0];
        
        //. 몬스터 공격 감지
        if (attack_time == t) {
            int damage = attacks[attack_count][1];
            hp = hp - damage;

            if (hp <= 0) return -1;

            attack_time = attacks[attack_count][0];
            count = 0;
            attack_count++;
        }
        else {
            hp = min(hp + bandage[1], health);
            count++;

            if (count == bandage[0]){
                hp = min(hp + bandage[2], health);
                count = 0;
            } 
        }

        t++;
    }

    return hp;
}