#include <iostream>
#include <vector>

using namespace std;

enum {
    NONE,
    BLACK,
    WHITE,
};

bool    is_end(int cur_color, int r, int c, vector<vector<int> > & go_board) {
    int cur_r, cur_c;
    int num_forward, num_backward;
    pair<int, int>  dir_fwd[4] = {make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1)};
    pair<int, int>  dir_bwd[4] = {make_pair(1, 0), make_pair(1, -1), make_pair(0, -1), make_pair(-1, -1)};


    for (int i = 0; i < 4; i++) {
        cur_r = r;
        cur_c = c;
        num_forward = 0;
        while (1) {
            cur_r += dir_fwd[i].first;
            cur_c += dir_fwd[i].second;
            if (!(1 <= cur_r && cur_r <= 19 && 1 <= cur_c && cur_c <= 19))
                break ;
            if (go_board[cur_r][cur_c] == cur_color)
                num_forward++;
            else
                break ; 
        }

        cur_r = r;
        cur_c = c;
        num_backward = 0;
        while (1) {
            cur_r += dir_bwd[i].first;
            cur_c += dir_bwd[i].second;
            if (!(1 <= cur_r && cur_r <= 19 && 1 <= cur_c && cur_c <= 19))
                break ;
            if (go_board[cur_r][cur_c] == cur_color)
                num_backward++;
            else
                break ; 
        }

        if (num_forward + num_backward + 1 == 5)
            return (true);
    }

    return (false);
}

int main(void) {
    int                     N;
    vector<pair<int, int> > loc;
    int                     i, cur;
    int                     r, c;
    int                     forward, backward;
    vector<vector<int> >    go_board(20, vector<int>(20, NONE));
    
    // 0. Init
    cin >> N;
    loc.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> r >> c;
        loc[i] = make_pair(r, c);
    }

    // 1. Calculate
    for (i = 1; i <= N; i++) {
        r = loc[i].first;
        c = loc[i].second;
        
        // Black turn
        if (i % 2 == 1) cur = BLACK;
        // White turn
        else cur = WHITE;
        go_board[r][c] = cur;

        // Check precisely 5
        if (is_end(cur, r, c, go_board))
            break ;
    }


    // 2. Print result
        // a. impossible
    if (i > N)
        cout << "-1\n";
        // b. possible
    else
        cout << i << "\n";

    return (0);
}