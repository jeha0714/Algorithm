#include <iostream>
#include <vector>

using namespace std;

bool    is_valid(int N, int M, vector<vector<int> > & board) {
    // 오른쪽과 아래만 검사

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            // a. c == M - 1 && r == N - 1이면 pass
            if (c == M - 1 && r == N - 1)
                continue ; 
            // b. c == M - 1 아래만 검사
            else if (c == M - 1) {
                if (board[r][c] == board[r + 1][c])
                    return (true);
            }
            // c. r == N - 1이면 오른쪽만 검사 
            else if (r == N - 1) {
                if (board[r][c] == board[r][c + 1])
                    return (true);
            }
            // d. 그 외 모두 검사
            else {
                if (board[r][c] == board[r + 1][c])
                    return (true);
                if (board[r][c] == board[r][c + 1])
                    return (true);
            }
        }
    }

    return (false);
}

/*
< 모든 카드를 없앨 수 있는 조건 >
1. 0과 1의 수가 모두 짝수개여야 함.
2. 한 쌍을 지울 수 있으면 모두 지울 수 있음
*/
int main(void) {
    int                     N, M;
    int                     num_zero = 0, num_one = 0;
    vector<vector<int> >    board;
    int                     result;

    // 0. Init
    cin >> N >> M;
    board.resize(N);
    for (int r = 0; r < N; r++) {
        board[r].resize(M);
        for (int c = 0; c < M; c++) {
            cin >> board[r][c];
            if (board[r][c]) num_one++;
            else num_zero++;
        }
    }

    // 1. Calculate
    if (num_zero % 2 == 0 && num_one % 2 == 0) {
        if (is_valid(N, M, board))
            result = 1;
        else
            result = -1;
    }
    else
        result = -1;

    // 2. Print result
    cout << result << "\n";

    return (0);
}