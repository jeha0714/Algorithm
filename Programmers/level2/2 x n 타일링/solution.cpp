using namespace std;

#define MOD 1000000007

/*
점화식이 있지 않을까?
n	answer
1	1
2	2
3	3
4	5
5	8
6	13
7	21
8	1 + 7 + 15 + 1 + 10 = 34
*/
int solution(int n) {
    int			answer = 0;
    long long	cur, prev, pprev, ppprev;
    
    // 0. Init
    	// a. Degenerate Case
    if (n == 1) return (1);
    else if (n == 2) return (2);
    else if (n == 3) return (3);
    	// b. Set variable
    ppprev = 1;
    pprev = 2;
    prev = 3;
    
    // 1. Calculate
    for (int i = 4; i <= n; i++) {
        if (prev * 2 - ppprev >= 0) cur = prev * 2 - ppprev;
        else cur = prev * 2 - ppprev + MOD;
        ppprev = pprev;
        pprev = prev;
        prev = cur;
        cur %= MOD;
        prev %= MOD;
        pprev %= MOD;
        ppprev %= MOD;
    }
    answer = cur;
    
    // 2. Return Answer
    return answer;
}