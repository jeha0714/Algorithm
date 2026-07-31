#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
1. n을 k진수로 string으로 변환
2. 0이 나올때까지 index를 늘려나가면서 long long에 저장
10^6 -> 약 3^(12~14)
3. 소수 여부 판단 후 맞다면 조건에 맞는지 판단
*/

bool	is_prime(long long num) {
    long long	standard;
    
    standard = static_cast<long long>(sqrt(static_cast<double>(num)));
    
    if (num < 2)
        return (false);
    for (long long i = 2; i <= standard; i++) {
        if (num % i == 0)
            return (false);
    }
    
    return (true);
}

int solution(int n, int k) {
    int answer = 0;
    string		conv_n;
    long long	num;
    
    // 0. Init
    	// a. k진수 이상일 때 계속 쪼개기
    while (n >= k) {
        conv_n.push_back(n % k + '0');
        n /= k;
    }
    conv_n.push_back(n % k + '0');
    
    // 1. Calculate
    for (int i = static_cast<int>(conv_n.length()) - 1; i >= 0; i--) {
        // a. 0이 나올때까지 index를 늘려나가면서 long long에 저장
        if (conv_n[i] != '0') {
            num = 0;
            // 1). num 먼저 set
            while (i >= 0 && conv_n[i] != '0') {
                num *= 10;
                num += (conv_n[i] - '0');
                i--;
            }
            
            // 2). num이 소수인지 판단 -> 소수라면 answer 증가
            if (is_prime(num))
                answer++;
        }
        // b. if conv_n[i] == 0 -> PASS
    }
    
    // 2. Return Answer
    return answer;
}