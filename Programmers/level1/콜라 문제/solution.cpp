using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int	cur;
    
    // 1. Calculate
    while (n >= a) {
        cur = (n / a * b);
        answer += cur;
        n %= a;
        n += cur;
    }
    
    // 2. Return Answer
    return answer;
}