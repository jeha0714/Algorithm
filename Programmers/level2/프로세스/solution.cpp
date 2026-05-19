#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int>	num_p(10, 0);
    int	cur_p, cur_i;
    
    // 0. Init
   	for (int i = 0; i < priorities.size(); i++)
        num_p[priorities[i]]++;
    cur_p = 9;
    while (num_p[cur_p] == 0)
        cur_p--;
    
    // 1. Calculate
    for (cur_i = 0; cur_i != location || cur_p != priorities[location]; cur_i == priorities.size() - 1 ? cur_i = 0 : cur_i += 1) {
        if (priorities[cur_i] == cur_p) {
            num_p[cur_p]--;
            while (num_p[cur_p] == 0)
                cur_p--;
            answer++;
        }
    }
	answer++;
    
    // 2. Return answer
    return answer;
}