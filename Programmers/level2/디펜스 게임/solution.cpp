#include <vector>
#include <queue>

using namespace std;

/*
한 라운드가 지날 때마다 pq에 담고 n을 감소시킴
n이 0이하가 되는 순간 pq를 pop하고 k를 소모하고 n을 pq.top 값만큼 증가
*/

int solution(int n, int k, vector<int> enemy) {
    int		answer = 0;
    priority_queue<int, vector<int>, less<int>>	pq;
    size_t	i = 0;
    
    // 0. Init
    
    // 1. Calculate
    while (i < enemy.size()) {
        // a. 적을 물리친 후 병사가 음수가 아닌 경우
        if (n - enemy[i] >= 0) {
            n -= enemy[i];
            pq.push(enemy[i]);
            i++;
            answer++;
        }
        // b. 남는 병사가 음수인 경우
        else {
            // 1). 무적권이 존재하는 경우
            if (k > 0) {
                pq.push(enemy[i]);
                n += pq.top();
                n -= enemy[i];
                pq.pop();
                i++;
                answer++;
                k--;
            }
            // 2). 무적권이 존재하지 않는 경우
            else
                break;
        }
    }
    
    // 2. Return Answer
    return answer;
}