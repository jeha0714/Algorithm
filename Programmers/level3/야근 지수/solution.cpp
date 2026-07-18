#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>>	pq;
    int	tmp;
    
    // 0. Init
    for (int i = 0; i < works.size(); i++)
        pq.push(works[i]);
    
    // 1. Calculate
    while (n > 0) {
        tmp = pq.top();
        pq.pop();
        
        tmp--;
        n--;
        
        pq.push(tmp);
    }
    while (!pq.empty()) {
        if (pq.top() > 0)
            answer += (static_cast<long long>(pq.top()) * pq.top());
        pq.pop();
    }
    
    // 2. Return Answer
    return answer;
}