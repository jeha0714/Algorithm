#include <vector>
#include <bitset>

using namespace std;

/*

1-1. 점수를 뺐으려면 해당 점수판에 더많이 사용해야함.
1-2. 점수를 뺐지 않으려면 해당 점수판에 하나라도 꽂으면 안됨

모든 경우의 수는 2^11 
-> 여기서 불가능한 경우의 수도 존재할 수 있다.

*/

int	calc_peach(const vector<int> & info, const bitset<11> & mem) {
    int	score = 0;
    
    for (int i = 0; i <= 10; i++) {
        if (mem[i] == 0 && info[i] >= 1)
            score += (10 - i);
    }
    return (score);
}

int	calc_lion(const bitset<11> & mem) {
	int	score = 0;
    
    for (int i = 0; i <= 10; i++) {
        if (mem[i] == 1)
            score += (10 - i);
    }
    return (score);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    bitset<11>	mem;
    int	score_lion, score_peach;
    int	score_gap, prev_score_lion;
    
    // 0. Init
    answer.resize(1);
    answer[0] = -1;
    score_gap = -1;
    prev_score_lion = -1;
    
    // 1. Calculate
    for (int num = 1, left_n; num < (2 << 10); num++) {
        mem = bitset<11>(num);
        left_n = n;
        
        
        // a. 현재 mem의 조건인 경우 left_n이 모자르지는 않는지
        for (int i = 0; i <= 10; i++)
            if (mem[i]) left_n -= (info[i] + 1);
        if (left_n < 0)
            continue ;
        
        // b. 가능 한 경우 (n이 남았을 수도 0일 수도 있음)
            // 1) 현재 peach 점수 계산
        score_peach = calc_peach(info, mem);

            // 2) 현재 lion 점수를 계산
        score_lion = calc_lion(mem);

            // 3) 현재 lion점수가 현재 peach점수보다 크고 score_gap보다 크다면 저장
        if (score_peach < score_lion) {
            if ((score_gap < score_lion - score_peach)
                || (score_gap == score_lion - score_peach && prev_score_lion < score_lion)) {
                score_gap = score_lion - score_peach;
                prev_score_lion = score_lion;

                if (answer.size() == 1)
                    answer.resize(11);
                for (int i = 0; i <= 10; i++) {
                    if (mem[i])
                        answer[i] = info[i] + 1;
                    else
                        answer[i] = 0;
                }
                // a) 남은 화살은 가장 작은 배점에 배치
                answer[10] = left_n;
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}