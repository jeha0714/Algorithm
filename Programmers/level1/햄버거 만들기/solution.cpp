#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int>	st;
    int	top;
    
    
    // 0. Init
    if (ingredient[0] == 1) st.push(2);
    else st.push(-1);
    
    // 1. Calculate
    for (int i = 1; i < ingredient.size(); i++) {
        if (!st.empty()) top = st.top();
        else top = -1;
        
        // a. 빵인 경우
        if (ingredient[i] == 1) {
            // 1) 마지막 빵인 경우
            if (top == 1) {
                answer++;
                st.pop(); st.pop(); st.pop();
            }
            // 2) 시작 빵인 경우
            else st.push(2);
        }
        // b. 그 외(야채, 고기)의 경우
        else {
            // 1) 정상적으로 쌓인 경우
            if (top == ingredient[i]) {
                if (ingredient[i] == 2)
                    st.push(3);
                else if (ingredient[i] == 3)
                    st.push(1);
            }
            // 2) 비정상적으로 쌓인 경우
            else
                st.push(-1);
        }
    }
    
    // 2. Return Answer
    return answer;
}