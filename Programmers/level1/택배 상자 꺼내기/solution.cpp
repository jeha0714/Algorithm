using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int	nums_floor, nums_loc;
    int	remain_floor, remain_loc, s, e;
    
    // 1. num의 현재 위치 구하기
    nums_floor = num / w;
    if (num % w != 0)
        nums_floor++;
    
    // 2. nums_floor위에 몇 층이 존재하는지 구하기
    	// a. 완전한 층이 몇 층인지 구하기
    answer = n / w - nums_floor;
    	// b. 불완전한 층이 위에 포함되는지 구하기
    remain_loc = n % w;
    if (remain_loc != 0) {
        // 1) 불완전한 층 구하기
        remain_floor = n / w + 1;
        if (remain_floor % 2 == 1) {
            s = 1;
            e = remain_loc;
        }
        else {
            s = w - remain_loc + 1;
            e = w;
        }
        
        // 2) num의 위치 구하기
        nums_loc = num % w;
        if (nums_loc == 0)
            nums_loc += w;
        
        // 3) 짝수층은 거꾸로 뒤집힘
        if (nums_floor % 2 == 0) {
            nums_loc = w + 1 - nums_loc;
            if (s <= nums_loc && nums_loc <= e)
                answer++;
        }
        else {
            if (s <= nums_loc && nums_loc <= e)
                answer++;
        }
    }
    	// c. 자신층 포함시키기
    answer++;
    
    // 3. Return answer
    return answer;
}