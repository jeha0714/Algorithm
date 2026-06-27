#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long	x1, x2, rr1, rr2;
    
    // 0. Init
    x1 = r1;
    x2 = r2;
    rr1 = (long long)r1 * r1;
    rr2 = (long long)r2 * r2;
    
    // 1. Calculate
    	// a. 1사분면 + 1사분면 x축 계산
    for (long long y = 0, yy; x2 != 0 && y < r2; y++) {
        yy = y * y;
        /* x^2 + y^2 = r^2 */
        	// 1) 원의 내부에서 가장 인접한 x값 구하기
        for (; x1 != 0 && x1 * x1 + yy >= rr1; x1--) ;
        	// 2) 원의 외곽 및 내부를 포함한 외곽에서 가장 인접한 x값 구하기
        for (; x2 * x2 + yy > rr2; x2--) ;
        
        answer += (x2 - x1);
    }
    
    	// b. * 4 
    answer *= 4;
   
    // 2. Return Answer
    return answer;
}