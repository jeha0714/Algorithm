#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
terms -> unordered _map
privacies는 순회
*/

bool	is_valid(const vector<int> & t, const string & s_p,  unordered_map<char, int> & terms) {
    vector<int>	p;
    
    // a. convert
    p.push_back(atoi(s_p.c_str()));
    p.push_back(atoi(s_p.c_str() + 5));
    p.push_back(atoi(s_p.c_str() + 8));
    
    
    // b. Calculate
    p[2] -= 1;
    if (p[2] == 0) {
        p[1]--;
        p[2] = 28;
    }
    p[1] += terms[s_p[11]];
    if (p[1] > 12) {
        if (p[1] % 12 == 0) {
            p[0] += (p[1] / 12 - 1);
            p[1] = 12;
        }
        else {
            p[0] += (p[1] / 12);
            p[1] %= 12;
        }
    }
    
    
    // c. Compare
    if (t[0] > p[0])
        return (false);
    else if (t[0] == p[0] && t[1] > p[1])
        return (false);
    else if (t[0] == p[0] && t[1] == p[1] && t[2] > p[2])
        return (false);
    return (true);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int>	terms_map;
    vector<int>	v_today;
    
    // 0. Init
    for (int i = 0; i < terms.size(); i++)
        terms_map[terms[i][0]] = atoi(terms[i].c_str() + 2);
    v_today.push_back(atoi(today.c_str()));
    v_today.push_back(atoi(today.c_str() + 5));
    v_today.push_back(atoi(today.c_str() + 8));
    
    // 1. Calculate
    for (int i = 0; i < privacies.size(); i++) {
        if (!is_valid(v_today, privacies[i], terms_map))
            answer.push_back(i + 1);
    }
    
    // 2. Return Answer
    return answer;
}