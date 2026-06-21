#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int	hp;
    int	cur_time, remain;
    
    // 0. Init
    hp = health;
    cur_time = attacks[0][0];
    
    // 1. Calculate
    for (int i = 0; i < attacks.size(); i++) {
        // a. Calc Recover info
        remain = attacks[i][0] - cur_time;
        if (remain < bandage[0]) {
            hp += (remain * bandage[1]);
        }
        else {
            hp += (remain * bandage[1]);
            hp += (remain / bandage[0] * bandage[2]);
        }
        hp = min(hp, health);
        
        // b. Calc Attack info
        hp -= attacks[i][1];
        cur_time = attacks[i][0] + 1;
        
        // c. Check Character Dead
        if (hp <= 0) {
            hp = -1;
            break ;
        }
    }
    
    answer = hp;
    
    // 2. Return answer
    return answer;
}