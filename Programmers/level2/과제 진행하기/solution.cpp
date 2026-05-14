#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool	asc_time(const vector<string> & a, const vector<string> & b)
{
    for (int i = 0; i < 5; i++) {
        if (a[1][i] != b[1][i])
            return (a[1][i] < b[1][i]);
    }
    return (false);
}

class myasc
{
    public:
        bool operator() (const vector<string> & a, const vector<string> & b)
        {
            for (int i = 0; i < 5; i++) {
                if (a[1][i] != b[1][i])
                    return (a[1][i] < b[1][i]);
            }
            return (false);
        }
};

int	minus_time(string & s2, string & s1) {
    int	s2_h = stoi(s2);
    int	s1_h = stoi(s1);
    int	s2_m = stoi(s2.c_str() + 3);
    int	s1_m = stoi(s1.c_str() + 3);
    int	h, m;
    
    h = s2_h - s1_h;
    m = s2_m - s1_m;
    if (m < 0) {
        h--;
        m += 60;
    }
    return (h * 60 + m);
}

bool	is_le_time(string & s, string & t, string & e) {
    int ss, tt, ee;
    int	range = minus_time(e, s);
    
    return (stoi(t) <= range);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<vector<string>, vector<vector<string>>, myasc> pq;
    int remain_time;
    vector<string>	tmp;
    
    // 0. Init plans
    sort(plans.begin(), plans.end(), asc_time);
    
    // 1. Calculate
    	// a. 예정된 시간에 하기로 했던 작업부터 수행
    for (int i = 0; i < plans.size() - 1; i++) {
        // 1). 현재 작업이 다음 작업보다 일찍 혹은 딱 맞게 끝나는 경우
        if (is_le_time(plans[i][1], plans[i][2], plans[i + 1][1])) {
            answer.push_back(plans[i][0]);
            remain_time = minus_time(plans[i + 1][1], plans[i][1]) - stoi(plans[i][2]);
            
            // a). 다음작업까지 시간이 남는 경우 남은 작업들 계속 수행
            while (remain_time > 0 && !pq.empty()) {
                tmp = pq.top();
                pq.pop();
                
                // 남은 작업 시간이 충분한 경우
                if (remain_time >= stoi(tmp[2])) {
                    remain_time -= stoi(tmp[2]);
                    answer.push_back(tmp[0]);
                }
                // 남은 작업 시간이 부족한 경우
                else {
                    tmp[1] = plans[i + 1][1];
                    tmp[2] = to_string(stoi(tmp[2]) - remain_time);
                    pq.push(tmp);
                    remain_time = 0;
                }
            }
        }
        // 3). 현재 작업이 다음 작업보다 늦게 끝나는 경우
        else {
            plans[i][2] = to_string(stoi(plans[i][2]) - minus_time(plans[i + 1][1], plans[i][1]));
            plans[i][1] = plans[i + 1][1];
            pq.push(plans[i]);
        }
    }
    	// b. 마지막 작업은 interrupt 발생할 일이 없음
    answer.push_back(plans[plans.size() - 1][0]);
    	// c. 남은 작업들 수행
    while (!pq.empty()) {
        answer.push_back(pq.top()[0]);
        pq.pop();
    }
    
    // 2. Return answer
    return answer;
}