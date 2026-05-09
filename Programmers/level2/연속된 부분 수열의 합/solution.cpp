#include <string>
#include <vector>

using namespace std;

pair<bool, vector<int> >	bns(int size, int s, int e, int k, vector<int> & total) {
    int			m = (s + e) / 2;
    
    // 1. degenerate case
    if (s > e) {
        vector<int>	tmp = {s - size + 1, s};
        // s 사용
        if (total[s] - total[s - size] == k) {
            return (make_pair(true, tmp));
        }
        else {
            return (make_pair(false, tmp));
        }
    }
    
    if (total[m] - total[m - size] < k) {
        return (bns(size, m + 1, e, k, total));
    }
    else
        return (bns(size, s, m - 1, k, total));
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int>	total(sequence.size(), 0); // 누적합
    pair<bool, vector<int> >	info;
    vector<int> answer;
    
    // 0. Init
    total[0] = sequence[0];
    for (int i = 1; i < sequence.size(); i++)
        total[i] = total[i - 1] + sequence[i];
    
    // 1. Calculate
    for (int size = 1; size <= sequence.size(); size++) {
        info = bns(size, size - 1, sequence.size() - 1, k, total);
        if (info.first == true) {
            answer = info.second;
            break ;
        }
    }
    
    // 2. Return result
    return answer;
}