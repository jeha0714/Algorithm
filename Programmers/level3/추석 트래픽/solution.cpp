#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

int	power(const int base, const int exp) {
    int	ret = 1;
    for (int i = 1; i <= exp; i++) {
        ret *= base;
    }
    
    return (ret);
}

pair<int, int>	set_time(const string & s) {
    const char	*	str;
    int	start_time, end_time;
    int	t, sec, ms;
    
    str = s.c_str();
    // index 11부터 time 값
    end_time = atoi(str + 11);
    end_time = end_time * 60 + atoi(str + 14);
    end_time = end_time * 60 + atoi(str + 17);
    end_time = end_time * 1000 + atoi(str + 20);
    
    // index 24부터 처리시간 값
    sec = atoi(str + 24) * 1000;
    ms = 0;
    for (int i = 26; isdigit(s[i]) && i < 29; i++) {
        ms += ((s[i] - '0') * power(10, 28 - i));
    }
    t = sec + ms;
    start_time = end_time - t + 1;
    
    return (make_pair(start_time, end_time));
}

bool	compare(const pair<int, int> & a, const pair<int, int> & b) {
    if (a.first == b.first) {
        return (a.second < b.second);
    }
    else
        return (a.first < b.first);
}

class compare_pq {
public:
    bool operator()(const pair<int, int> & a, const pair<int, int> & b) {
        return (a.second > b.second);
    }
};

int solution(vector<string> lines) {
    int answer = 0;
    // [0] start time [1] end time
    vector<pair<int, int>>	info(lines.size());
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pq>	pq;
    
    // 0. Init
    for (int i = 0; i < lines.size(); i++) {
        info[i] = set_time(lines[i]);
    }
        // 시작시간이 이른 순으로
    sort(info.begin(), info.end(), compare);
    
    // 1. Calculate
    for (int i = 0; i < info.size(); i++) {
        // a. pq가 비었으면 push
        if (pq.empty()) {
            pq.push(info[i]);
        }
        // b. pq가 하나 이상 값이 있는 경우
        else {
            // 1) pq.top의 end_time이 new의 start_time보다 늦는 경우 push
            if (info[i].first < pq.top().second + 1000) {
                pq.push(info[i]);
            }
            // 2) pq.top의 end_time이 new의 start_time보다 이른 경우
            	// 늦을 때까지 pq를 pop
            else {
                while (!pq.empty() && info[i].first >= pq.top().second + 1000) {
                    pq.pop();
                }
                pq.push(info[i]);
            }
        }
        answer = max(answer, static_cast<int>(pq.size()));
    }
   
    // 2. Return Answer
    return answer;
}