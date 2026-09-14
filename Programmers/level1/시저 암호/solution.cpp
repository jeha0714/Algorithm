#include <string>
#include <ctype.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    // 1. Calculate
    answer.resize(s.length());
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') answer[i] = ' ';
        else if (isupper(s[i])) {
            if (s[i] + n > 'Z') answer[i] = 'A' + s[i] + n - 'Z' - 1;
            else answer[i] = s[i] + n;
        }
        else {
            if (s[i] + n > 'z') answer[i] = 'a' + s[i] + n - 'z' - 1;
            else answer[i] = s[i] + n;
        }
    }
    
    // 2. Return Answer
    return answer;
}