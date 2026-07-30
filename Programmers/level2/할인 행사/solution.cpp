#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1. want string과 index를 매핑 -> unordered_map
2. discount를 순회하면서 누적합 -> vector
*/

bool	is_possible(const vector<int> & number, const vector<int> & hold) {
    for (int i = 0; i < number.size(); i++) {
        if (number[i] != hold[i])
            return (false);
    }
    return (true);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int>	um;
    vector<int>	hold(want.size(), 0);
    int	day, index;
    
    // 0. Init
    for (int i = 0; i < want.size(); i++)
        um[want[i]] = i;
    for (day = 1; day <= 10; day++) {
        if (um.find(discount[day - 1]) != um.end()) {
            index = um[discount[day - 1]];
            hold[index]++;
        }
    }
    
    // 1. Calculate
    for (day = 11; day <= discount.size(); day++) {
        if (is_possible(number, hold))
            answer++;
        
        if (um.find(discount[day - 11]) != um.end()) {
            index = um[discount[day - 11]];
            hold[index]--;
        }
        
        if (um.find(discount[day - 1]) != um.end()) {
            index = um[discount[day - 1]];
            hold[index]++;
        }
    }
    if (is_possible(number, hold))
        answer++;
    
    // 2. Return Answer
    return answer;
}