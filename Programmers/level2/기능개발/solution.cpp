#include <vector>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int	standard, num_commit;
    int	tmp;
    
    // 0. Init
    standard = (100 - progresses[0]) % speeds[0] == 0 ? (100 - progresses[0]) / speeds[0] : (100 - progresses[0]) / speeds[0] + 1;
    num_commit = 1;
    
    // 1. 전체 순회
    for (int i = 1; i < progresses.size(); i++) {
    	tmp = (100 - progresses[i]) % speeds[i] == 0 ? (100 - progresses[i]) / speeds[i] : (100 - progresses[i]) / speeds[i] + 1;
    	// a. 현재 기준 점이 걸리는 시간보다 일찍 끝나거나 같게 끝난다면 +1
        if (tmp <= standard)
            num_commit++;
        // b. 현재 기준 점보다 늦게 끝난다면 answer에 push 후 초기화
        else {
            standard = tmp;
            answer.push_back(num_commit);
            num_commit = 1;
        }
    }
    answer.push_back(num_commit);
    
    // 2. Return answer
    return answer;
}