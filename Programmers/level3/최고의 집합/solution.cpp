#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int tmp, remain;
    
    if (n > s)
        answer.push_back(-1);
    else {
        tmp = s / n;
        for (int i = 0; i < n; i++)
            answer.push_back(tmp);
        
        remain = s - (n * tmp);
        for (int i = answer.size() - 1; remain > 0; remain--, i--)
            answer[i]++;
    }
    
    return answer;
}