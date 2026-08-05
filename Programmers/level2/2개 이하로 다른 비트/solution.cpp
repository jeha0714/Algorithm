#include <vector>
#include <bitset>

using namespace std;

/*
x보다 크면서 가장 작은 수를 만드는 법
가장 좌측 1을 찾는다
1. 가장 좌측 1과 가장 우측 사이에 0이 있다면 가장 우측의 0을 1로 비트 전환 시킨다.
2. 가장 좌측 1과 가장 우측 사이에 0이 없다면
	a. 가장 좌측 1을 0비트로 바꾸고 그 좌측의 비트를 1로 벼환

10^15 ~= (2^3)^15 ~= 2^50
*/

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    bitset<51>	bit;
    int	l, r;
        
    // 1. Calculate
    for (int i = 0; i < numbers.size(); i++) {
        // a. init number to bit
        bit.reset();
        bit = bitset<51>(numbers[i]);
        
        // 실제 저장되는 비트는 역방향
        // b. most right side 1 
        for (r = 50; r >= 0; r--)
            if (bit[r] == 1) break ;
        
        // c. most left side 1 
        for (l = 0; l <= 50; l++)
            if (bit[l] == 0) break ;
        
        // d. Condition
        	// 1) if l < r
        if (l < r) {
            bit[l] = 1;
            for (r = l - 1; r >= 0; r--)
                if (bit[r] == 1) break;
            if (r >= 0)
                bit[r] = 0;
        }
        	// 2) if l > r
        else if (l > r) {
            bit[r] = 0;
            bit[l] = 1;
        }
        answer.push_back(static_cast<long long>(bit.to_ullong()));
    }
    
    // 2. Return Answer
    return answer;
}