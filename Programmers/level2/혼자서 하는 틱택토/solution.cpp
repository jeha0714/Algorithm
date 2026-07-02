#include <string>
#include <vector>

using namespace std;

bool	is_bingo(vector<string> & b) {
    // horizontal
    for (int r = 0; r < 3; r++) {
        if (b[r][0] != '.' && b[r][0] == b[r][1] && b[r][1] == b[r][2])
            return (true);
    }
    
    // vertical
    for (int c = 0; c < 3; c++) {
        if (b[0][c] != '.' && b[0][c] == b[1][c] && b[1][c] == b[2][c])
            return (true);
    }
    
    // diagonal
    if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return (true);
    if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return (true);
    
    return (false);
}

int backtracking(int turn, vector<pair<int, int>> & v_o, vector<pair<int, int>> & v_x, vector<string> & b) {
    // finish case
    if (turn == v_o.size() + v_x.size()) {
        return (1);
    }
    else if (is_bingo(b)) {
        return (0);
    }
    
    // O가 둘 차례
    if (turn % 2 == 0) {
        for (int i = 0; i < v_o.size(); i++) {
            if (b[v_o[i].first][v_o[i].second] == '.') {
                b[v_o[i].first][v_o[i].second] = 'O';
                if (backtracking(turn + 1, v_o, v_x, b) == 1)
                    return (1);
                b[v_o[i].first][v_o[i].second] = '.';
            }
        }
    }
    // X가 둘 차례
    else {
        for (int i = 0; i < v_x.size(); i++) {
            if (b[v_x[i].first][v_x[i].second] == '.') {
                b[v_x[i].first][v_x[i].second] = 'X';
                if (backtracking(turn + 1, v_o, v_x, b) == 1)
                    return (1);
                b[v_x[i].first][v_x[i].second] = '.';
            }
        }
    }
    return (0);
}

int solution(vector<string> board) {
    int answer = 1;
    int	num_o, num_x;
    vector<pair<int, int>>	v_o;
    vector<pair<int, int>>	v_x;
    vector<string>			b(3, "...");
    
    // 0. Init
    num_o = 0;
    num_x = 0;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == 'O') {
                num_o++;
                v_o.push_back(make_pair(r, c));
            }
            else if (board[r][c] == 'X') {
                num_x++;
                v_x.push_back(make_pair(r, c));
            }
        }
    }
    
    // 1. Calculate
    	// a. num_O와 num_x는 같거나 num_o가 1커야함
    if (!(num_o == num_x || num_o == num_x + 1)) {
        answer = 0;
        return (answer);
    }
    
    	// b. 개수는 올바르다
    	// -> but 진작에 끝났어야 하는 경우
    	// 모든 경우의 수를 둬보며 진작에 끝나는지 판단
    answer = backtracking(0, v_o, v_x, b);
    
    // 2. Return Answer
    return answer;
}