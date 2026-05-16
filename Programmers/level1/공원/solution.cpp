#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int	max_size = -1, tmp;
    int answer = -1;
    
    // 1. Calculate
    	// a. 전체를 순회하면 깔 수 있는 최대크기의 돗자리 max_size를 설정
    for (int r = 0; r < park.size(); r++) {
        for (int c = 0; c < park[r].size(); c++) {
            if (park[r][c].compare("-1") == 0) {
                // 1). r - 1, c - 1에 접근 가능하다면
                if ((r >= 1 && c >= 1) && (park[r - 1].size() >= c + 1)) {
                    // a) r - 1, c - 1 값이 숫자라면 그 값에 + 1
                    if (!isalpha(park[r - 1][c - 1][0]) && !isalpha(park[r - 1][c][0]) && !isalpha(park[r][c - 1][0])) {
                        tmp = min(min(stoi(park[r - 1][c - 1]), stoi(park[r - 1][c])), stoi(park[r][c - 1]));
                        park[r][c] = to_string(tmp + 1);
                    }
                    // b) 일반 돗자리라면 1로 설정
                    else
                        park[r][c] = "1";
                }
                // 2) 접근 안된다면 1로 설정
                else
                    park[r][c] = "1";
                // 3) park[r][c] 값과 max_size 비교
                max_size = max(stoi(park[r][c]), max_size);
            }
        }
    }
    
    	// b. max_size 돗자리를 필 수 있는 최대 크기를 의미
    for (int i = 0; i < mats.size(); i++) {
        if (max_size >= mats[i] && answer <= mats[i])
            answer = mats[i];
    }
    
    // 2. Return answer
    return answer;
}