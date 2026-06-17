#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*

0. 각 도형의 위치를 찾아야 함

1. 해당 공간의 크기가 현재 블록의 크기와 같은가

2. 공간의 모양과 현재 블록의 모양이 동일한가
- 이걸 어케알지 음

*/

pair<pair<int, int>, int>	find_shape(int r, int c, vector<vector<int>> & board, int standard) {
    // bfs를 수행하면서 현재 도형의 0의 값을 2로 설정한다 -> visited를 의미
    // 도형에서 가장 좌측 상단에 위치한 값을 반환
    queue<pair<int, int> >	q;
    pair<int, int>	tmp, ret;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int	sizes;
    
    q.push(make_pair(r, c));
    ret.first = r;
    ret.second = c;
    board[r][c] = 2;
    sizes = 0;
    
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        sizes++;
        
        for (int i = 0; i < 4; i++) {
            if ((0 <= tmp.first + dr[i] && tmp.first + dr[i] < board.size())
                && (0 <= tmp.second + dc[i] && tmp.second + dc[i] < board[r].size())
               && board[tmp.first + dr[i]][tmp.second + dc[i]] == standard) {
                q.push(make_pair(tmp.first + dr[i], tmp.second + dc[i]));
				board[tmp.first + dr[i]][tmp.second + dc[i]] = 2;
                
                if (tmp.first + dr[i] < ret.first) {
                    ret.first = tmp.first + dr[i];
                    ret.second = tmp.second + dc[i];
                }
                else if (tmp.first + dr[i] == ret.first && tmp.second + dc[i] < ret.second) {
                    ret.first = tmp.first + dr[i];
                    ret.second = tmp.second + dc[i];
                }
            }
        }
    }
    return (make_pair(ret, sizes));
}

void	move_t(int rotate, pair<int, int> & t, vector<vector<int>> & table) {
    pair<int, int>	tmp, new_t;
    set<pair<int, int>>	s;
    queue<pair<int, int>>	q;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    new_t = t;
    q.push(t);

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

         for (int i = 0; i < 4; i++) {
            if ((0 <= tmp.first + dr[i] && tmp.first + dr[i] < table.size())
               && (0 <= tmp.second + dc[i] && tmp.second + dc[i] < table[0].size())
               && table[tmp.first + dr[i]][tmp.second + dc[i]] == 2
               && s.count(make_pair(tmp.first + dr[i], tmp.second + dc[i])) == 0) {
                q.push(make_pair(tmp.first + dr[i], tmp.second + dc[i]));
                s.insert(make_pair(tmp.first + dr[i], tmp.second + dc[i]));

                // 우측 상단
                if (rotate == 1) {
                    if (tmp.second + dc[i] > new_t.second) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }
                    else if (tmp.second + dc[i] == new_t.second && tmp.first + dr[i] < new_t.first) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }
                }
                // 우측 하단
                else if (rotate == 2) {
                    if (tmp.first + dr[i] > new_t.first) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }
                    else if (tmp.first + dr[i] == new_t.first && tmp.second + dc[i] > new_t.second) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }                       
                }
                // 좌측 하단
                else if (rotate == 3) {
                    if (tmp.second + dc[i] < new_t.second) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }
                    else if (tmp.second + dc[i] == new_t.second && tmp.first + dr[i] > new_t.first) {
                        new_t.first = tmp.first + dr[i];
                        new_t.second = tmp.second + dc[i];
                    }
                }
            }
        }           
    }
    t = new_t;
}

/*
1. 회전 4번 동안에 table의 shape에 가장 좌측 상단의 location을 잡는다
2. 비교한다.
*/
bool	is_match(pair<int, int> t, vector<vector<int>> & table, 
                 pair<int, int>	b, vector<vector<int>> & board) {
    int t_dr[4][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}, {1, 0, -1, 0}, {0, -1, 0, 1}};
    int t_dc[4][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}, {0, -1, 0, 1}, {-1, 0, 1, 0}};
    int b_dr[4] = {-1, 0, 1, 0};
    int b_dc[4] = {0, 1, 0, -1};
    queue<pair<int, int> >	t_q, b_q;
    pair<int, int>	t_tmp, b_tmp;
    set<pair<int, int>>	s;
    int flag;
    
    for (int rotate = 0; rotate < 4; rotate++) {
        move_t(rotate, t, table);
        
        while (!b_q.empty()) b_q.pop();
        while (!t_q.empty()) t_q.pop();
        s.clear();
        flag = 0;
        
        b_q.push(b);
        s.insert(make_pair(b.first, b.second));
        t_q.push(t);
        
        while (!b_q.empty() && flag == 0) {
            b_tmp = b_q.front();
            t_tmp = t_q.front();
            b_q.pop();
            t_q.pop();
            
            for (int i = 0; i < 4; i++) {
                if ((0 <= b_tmp.first + b_dr[i] && b_tmp.first + b_dr[i] < board.size())
                    && (0 <= b_tmp.second + b_dc[i] && b_tmp.second + b_dc[i] < board[0].size())
                    && board[b_tmp.first + b_dr[i]][b_tmp.second + b_dc[i]] == 2
                    && s.count(make_pair(b_tmp.first + b_dr[i], b_tmp.second + b_dc[i])) == 0) {
                    
                    if ((0 <= t_tmp.first + t_dr[rotate][i] && t_tmp.first + t_dr[rotate][i] < table.size())
                        && (0 <= t_tmp.second + t_dc[rotate][i] && t_tmp.second + t_dc[rotate][i] < table[0].size())
                        && table[t_tmp.first + t_dr[rotate][i]][t_tmp.second + t_dc[rotate][i]] == 2) {

                        b_q.push(make_pair(b_tmp.first + b_dr[i], b_tmp.second + b_dc[i]));
                        t_q.push(make_pair(t_tmp.first + t_dr[rotate][i], t_tmp.second + t_dc[rotate][i]));
                        s.insert(make_pair(b_tmp.first + b_dr[i], b_tmp.second + b_dc[i]));
                    }
                    else {
                        flag = 1;
                        break ;
                    }
                }
            }
        }
        if (b_q.empty() && flag == 0)
            return (true);
    }
    
    return (false);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<pair<pair<int, int>, int> >	shape_in_board;
    vector<pair<pair<int, int>, int> >	shape_in_table;
    vector<bool>			is_used;
    
    // 0. Init
    	// a. game_board에서의 도형 위치를 찾는다
    for (int r = 0; r < game_board.size(); r++) {
        for (int c = 0; c < game_board[r].size(); c++) {
            if (game_board[r][c] == 0) {
                shape_in_board.push_back(find_shape(r, c, game_board, 0));
            }
        }
    }
    	// b. table에서 도형 위치를 찾는다
     for (int r = 0; r < table.size(); r++) {
        for (int c = 0; c < table[r].size(); c++) {
            if (table[r][c] == 1) {
                shape_in_table.push_back(find_shape(r, c, table, 1));
            }
        }
    }       
    	// c. game_board의 위치가 사용중인지 판단하는 is_used 초기화
    is_used.resize(shape_in_board.size());
    for (int i = 0; i < is_used.size(); i++)
        is_used[i] = false;
    
    // 1. Calculate
    for (int i = 0; i < shape_in_table.size(); i++) {
        for (int j = 0; j < shape_in_board.size(); j++) {
            if (!is_used[j]) {
                // 두 도형이 매칭이 된다면 answer에 shape의 크기만큼 추가
                if (shape_in_table[i].second == shape_in_board[j].second
                    && is_match(shape_in_table[i].first, table, shape_in_board[j].first, game_board)) {
                    answer += shape_in_board[j].second;
                    is_used[j] = true;
                    break ;
                }
            }
        }
    }
    
    // 2. Print Answer
    return answer;
}