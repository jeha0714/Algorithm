#include <string>
#include <vector>
#include <cmath>

using namespace std;

int	conv_time(string time) {
    int	ret = 0;
    
    for (int i = 4; i > 2; i--) {
        ret += ((time[i] - '0') * pow(10, 4 - i));
    }
    for (int i = 1; i >= 0 ; i--) {
        ret += ((time[i] - '0') * pow(10, 3 - i));
    }
    ret = (ret % 100) + (ret / 100 * 60);
    
    return (ret);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int v_len, p, op_s, op_e;
    
    // 0. Init
    v_len = conv_time(video_len);
    p = conv_time(pos);
    op_s = conv_time(op_start);
    op_e = conv_time(op_end);
    if (op_s <= p && p < op_e)
        p = op_e;
    
    // 1. Calculate
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i].compare("prev") == 0)
            p -= 10;
        else if (commands[i].compare("next") == 0)
            p += 10;
        
        if (p < 0)
            p = 0;
        if (p > v_len)
            p = v_len;
        if (op_s <= p && p < op_e)
            p = op_e;
    }
    answer.push_back(p / 60 / 10 + '0');
    answer.push_back(p / 60 % 10 + '0');
    answer.push_back(':');
    answer.push_back(p % 60 / 10 + '0');
    answer.push_back(p % 60 % 10 + '0');
    
    // 2. Return Answer
    return answer;
}