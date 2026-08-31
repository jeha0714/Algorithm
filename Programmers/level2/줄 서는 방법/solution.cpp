#include <vector>

using namespace std;

/*
k를 바탕으로 각 단계 가장 앞의 수가 정해진다.
*/
vector<int> solution(int n, long long k) {
    vector<int>			answer;
    vector<long long>	factorial(n + 1);
    vector<bool>		is_used(n + 1, false);
    int					i, tmp;
    
    // 0. Init
    	// a. answer의 capacity 고정
    answer.reserve(n);
    	// b. factorial 초기화
    factorial[0] = 1;
    for (int i = 1; i < n; i++)
        factorial[i] = factorial[i - 1] * i;
    
    // 1. Calculate
    i = n - 1;
    while (answer.size() != n) {
        // a. 가장 앞에 들어갈 수를 찾는다.
        tmp = (k - 1) / factorial[i];
        k = k - tmp * factorial[i];
        
        // b. is_used가 안된 수 중 tmp번째 수를 찾는다.
        for (int j = 1, nth = 1; j <= n; j++) {
            if (is_used[j] == false) {
                if (nth == tmp + 1) {
                    answer.push_back(j);
                    i--;
                    is_used[j] = true;
                    break ;
                }
                else nth++;
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}