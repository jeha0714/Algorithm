#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int	n_drop; // 남은 버려야 하는 수
    int	i_cur; // str number의 index
    int	i_most_big; // 현재 구간에서 가장 큰 index
    
    // 0. Init
    answer.reserve(number.size() - k);
    n_drop = k;
    i_cur = 0;
    i_most_big = 0;
    
    // 1. Calculate
    while (n_drop != 0) {
        //cout << i_cur << "\n";
        // a. 현재 구간(남은 삭제 수 + 1)에서 가장큰 값을 가지는 index를 찾는다
        for (int i = i_cur; i - i_cur < n_drop + 1; i++) {
            if (number[i_most_big] < number[i])
                i_most_big = i;
        }
        
        // b. i_most_big 가장 큰 값을 확인 후 해당 index 앞 모두 삭제
        n_drop -= (i_most_big - i_cur);
        answer.push_back(number[i_most_big]);
        i_cur = i_most_big + 1;
        i_most_big = i_cur;
        
        // c.i_cur 이상 남은 수가 n_drop보다 같다면
        if (number.length() - i_cur == n_drop) {
            i_cur = number.length();
            n_drop = 0;
        }
    }
    for (; i_cur < number.length(); i_cur++)
        answer.push_back(number[i_cur]);

    // 2. Return answer
    return answer;
}