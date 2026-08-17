using namespace std;

/*
(0, 0)에서 (w, h)를 있는 직선의 방정식 l을 떠올린다.
y = l일 때 y가 정수값일 때의 x들을 구한다.
	1. x가 정수라면 answer += w - x
    2. x가 정수가 아니라면 ansewr += (w - 올림(x))
    
직선의 방정식은 기울기가 -> h/w
직선의 방정식은 y = (h/w)x
y가 정수일때를 구한다면 for문을 세우고
i * (w/h) = x를 만족하는 x를 구하면 된다.
*/

long long solution(int w,int h) {
    long long answer = 0;
    long long	lw, lh, x;
    
    // 0. Init
    lw = static_cast<long long>(w);
    lh = static_cast<long long>(h);
    
    // 1. Calculate
    for (int i = 1; i < h; i++) {
        x = i * lw / lh;
        if (i * lw == lh * x)
            answer += w - x;
        else
            answer += (w - x - 1);
    }
    answer *= 2;
    
    // 2. Return Anwer
    return answer;
}