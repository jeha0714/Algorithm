#include <string>
#include <vector>

using namespace std;

void	mv(int & x, int & y, const char c) {
    if (c == 'U') y++;
    else if (c == 'D') y--;
    else if (c == 'R') x++;
    else if (c == 'L') x--;
    
    if (x < 0) x++;
    else if (x > 20) x--;
    else if (y < 0) y++;
    else if (y > 20) y--;
}

int solution(string dirs) {
    int answer = 0;
    vector<vector<bool>>	is_visit(21, vector<bool>(21, false));
    int	x, y;
    
    // 0. Init
    	// a. 원점 설정
    x = 10;
    y = 10;
    is_visit[x][y] = true;
    
    // 1. Calculate
    for (int i = 0; i < dirs.length(); i++) {
        // a. mv to path
        mv(x, y, dirs[i]);
        if (is_visit[x][y] == false) {
            is_visit[x][y] = true;
            answer++;
        }
        
        // b. mv to spot
        mv(x, y, dirs[i]);
        if (is_visit[x][y] == false)
            is_visit[x][y] = true;
    }
    
    // 2. Return Answer
    return answer;
}