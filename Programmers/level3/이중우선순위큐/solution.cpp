#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>>	apq; // ascending
    priority_queue<int, vector<int>, less<int>>	dpq; // descending
	unordered_map<int, int>	um;
    int	tmp;
    
    // 1. Calculate
    for (int i = 0; i < operations.size(); i++) {
        tmp = atoi(operations[i].c_str() + 1);
        
        if (operations[i][0] == 'I') {
            if (um.find(tmp) == um.end())
                um.insert(make_pair(tmp, 1));
            else
                um[tmp] = um[tmp] + 1;
            apq.push(tmp);
            dpq.push(tmp);
        }
        else if (operations[i][0] == 'D') {
            if (tmp == -1) {
                while (!apq.empty() && um[apq.top()] == 0)
                    apq.pop();
                if (!apq.empty()) {
                    tmp = apq.top();
                    apq.pop();
                    um[tmp] = um[tmp] - 1;
                }
            }
            else if (tmp == 1) {
                while (!dpq.empty() && um[dpq.top()] == 0)
                    dpq.pop();
                if (!dpq.empty()) {
                    tmp = dpq.top();
                    dpq.pop();
                    um[tmp] = um[tmp] - 1;
                }
            }
        }
    }
    while (!apq.empty() && um[apq.top()] == 0)
        apq.pop();
    while (!dpq.empty() && um[dpq.top()] == 0)
        dpq.pop();
    
    // 2. Return answer
    if (apq.size() != 0) {
        answer.push_back(dpq.top());
        answer.push_back(apq.top());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}