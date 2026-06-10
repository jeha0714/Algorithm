#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int>	um;
    string	get_ahead, fall_behind;
    int		rank_get_ahead;
    
    // 0. Init
    for (int i = 0; i < players.size(); i++) {
        um[players[i]] = i + 1;
    }
    
    // 1. Calculate
    for (int i = 0; i < callings.size(); i++) {
        // a. set varialbe
        get_ahead = callings[i];
        rank_get_ahead = um[get_ahead];
        fall_behind = players[rank_get_ahead - 2];
        
        // b. Change player
        players[rank_get_ahead - 2] = get_ahead;
        players[rank_get_ahead - 1] = fall_behind;
        
        // c. Change um
        um[get_ahead] = rank_get_ahead - 1;
        um[fall_behind] = rank_get_ahead;
    }
    
    // 2. Return answer
    return players;
}