#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 0);
    long long	start;
    
    // 0. Init
    
    // 1. Calculate
    for (long long i = 10000000; i >= 1; i--) {
        
        // a. begin보다 같거나 큰 i의 배수 start를 설정
        if (begin % i == 0)
            start = begin;
        else
            start = begin + i - (begin % i);
        
        // b. end보다 같거나 작은 경우를 순회하며 answer 설정
        for (; start <= end; start += i) {
            if (start != i
                && answer[start - begin] == 0)
                answer[start - begin] = i;
        }
    }
    
    // 2. Return Answer
    return answer;
}