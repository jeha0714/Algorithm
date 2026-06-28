#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int>	st;
    
    // 0. Init
    answer.resize(numbers.size());
    
    // 1. Calculate
    for (int i = numbers.size() - 1; i >= 0; i--) {
        
        while (!st.empty()) {
            if (st.top() > numbers[i])
                break ;
            else
                st.pop();
        }
        if (st.empty())
            answer[i] = -1;
        else
            answer[i] = st.top();
        
        st.push(numbers[i]);
        
    }
    
    // 2. Return answer
    return answer;
}