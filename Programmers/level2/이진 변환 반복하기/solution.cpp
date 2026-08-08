#include <string>
#include <vector>

using namespace std;

/*
1. 모든 0을 제거할 때 현재 s의 0, 1의 개수를 각각 파악
2. c라고 하면
*/

void	setting(int & num_zero, int & num_one) {
    int	num;
    
    // 0. Init
    num = num_one;
    num_zero = 0;
    num_one = 0;
    
    // 1. Calculate
    while (num > 1) {
        if (num % 2 == 0) num_zero++;
        else num_one++;
        num /= 2;
    }
    num_one++;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int			len;
    int			num_zero, num_one;
    
    // 0. Init
    len = s.length();
    num_zero = 0;
    num_one = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') num_zero++;
        else num_one++;
    }
        
    // 1. Calculate
    while (len != 1) {
        // a. Adding answer value
        answer[0]++;
        answer[1] += num_zero;
        
        // b. Conv
		// 현재 1의 개수로 0과 1의 개수 및 len set
        setting(num_zero, num_one);
        len = num_zero + num_one;
    }
    
    // 2. Return Answer
    return answer;
}