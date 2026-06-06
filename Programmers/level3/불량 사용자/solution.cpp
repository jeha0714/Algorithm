#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;

/*
*/

bool	is_match(const string & standard, const string & comp) {
    size_t	s_len = standard.length();
    size_t	c_len = comp.length();
    
    if (s_len != c_len)
        return (false);
    for (int i = 0; i < s_len; i++) {
        if (standard[i] != '*' && standard[i] != comp[i])
            return (false);
    }
    
    return (true);
}

void	back_tracking(vector<string> & user_id, vector<string> & banned_id, int b_i, bitset<8> & v, unordered_set<unsigned long> & s) {
    // 1. Early Stop case
    if (b_i == banned_id.size()) {
        s.insert(v.to_ulong());
        return ;
    }
    
    // 2. Back tracking
    for (int i = 0; i < user_id.size(); i++) {
        if (v[i] == 0 && is_match(banned_id[b_i], user_id[i])) {
            v[i] = 1;
            back_tracking(user_id, banned_id, b_i + 1, v, s);
            v[i] = 0;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    bitset<8>	v;
    unordered_set<unsigned long>	s;
    
    // 1. Calculate
    back_tracking(user_id, banned_id, 0, v, s);
    answer = s.size();
   
    // 2. Return answer
    return answer;
}