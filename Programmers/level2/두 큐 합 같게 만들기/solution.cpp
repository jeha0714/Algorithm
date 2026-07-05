#include <vector>

using namespace std;

int	calc(long long s, long long e, size_t q1_s, size_t q2_s) {
    
    // 1) s와 e가 모두 q1에 있을 때
    if (e < q1_s) {
        // a) e가 q1 끝일 때
        if (e == q1_s - 1) {
            return (s);
        }
        // b) e가 q1 끝이 아닐 때
        else {
            return (e + 1 + q2_s + s);
        }
    }
    // 2) s는 q1 e는 q2
    else if (s < q1_s && e < q1_s + q2_s) {
        return (s + e + 1 - q1_s);
    }
    // 3) s와 e가 모두 q2에 있을 때
    else {
        // a) e가 q2 끝일 때
        if (e == q1_s + q2_s - 1) {
            return(s - q1_s);
        }
        // b) e가 q2 끝이 아닐 때
        else {
            return (e + 1 + s - q1_s);
        }
    }
}

int solution(vector<int> q1, vector<int> q2) {
    int answer = 2147483647;
    vector<int>	v;
    long long	aim = 0, cur;
    int	s, e, tmp;
    
    // 0. Init
    v.resize(q1.size() + q2.size());
    for(int i = 0; i < q1.size(); i++) {
        v[i] = q1[i];
        aim += q1[i];
    }
    for(int i = 0; i < q2.size(); i++) {
        v[q1.size() + i] = q2[i];
        aim += q2[i];
    }
        
    // 1. Calculate
    // a. 전체 합이 홀수 인경우 절반으로 나눌 수 없음
    if (aim % 2 == 1)
        return (-1);
    aim /= 2;
    
    // b. two pointer로 범위 알아내기
    for (s = 0, e = -1, cur = 0; e < static_cast<int>(v.size()) && s < static_cast<int>(v.size());) {
        if (cur < aim) {
            e++;
            if (e < static_cast<int>(v.size()))
                cur += v[e];
        }
        else if (cur == aim) {
            tmp = calc(s, e, q1.size(), q2.size());
            answer = min(answer, tmp);
            e++;
            if (e < static_cast<int>(v.size()))
                cur += v[e];
        }
        else { // cur > aim
            cur -= v[s];
            s++;
        }
    }
    if (cur == aim) {
        tmp = calc(s, e, q1.size(), q2.size());
        answer = min(answer, tmp);
    }
    else if (answer == 2147483647)
        answer = -1;
    
    // 2. Return Answer
    return answer;
}