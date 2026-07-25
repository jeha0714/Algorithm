#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool>	v_skip('z' - 'a' + 1, false);
    
    // 0. Init
    for (int i = 0; i < skip.length(); i++)
        v_skip[skip[i] - 'a'] = true;
    
    // 1. Calculate
    for (int i = 0, c; i < s.length(); i++) {
        c = s[i];
        for (int jump = 0; jump < index;) {
            c++;
            if (c > 'z')
                c = (c - 'z' - 1) + 'a'; 
            
            if (!v_skip[c - 'a'])
                jump++;
        }
        answer.push_back(c);
    }
    
    // 2. Return Answer
    return answer;
}