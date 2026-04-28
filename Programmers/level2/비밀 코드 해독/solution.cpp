#include <string>
#include <vector>
#include <bitset>

using namespace std;

void	backtracking(int depth, int n, bitset<30> & comb) {
    // a. degenerate case
    if (depth == 6)
        return ;
    else if (comb[n - depth] == 1)
        backtracking(depth + 1, n, comb);
    else {
        for (int i = n - depth - 1; i >= 0; i--) {
            if (comb[i] == 1) {
                comb[i] = 0;
                for (int j = 1; j <= depth; j++)
                    comb[i + j] = 1;
                for (int j = depth + 1; j < n; j++)
                    comb[i + j] = 0;
                    
                break ;
            }
        }
    }
}

void	set_cur_comb(int n, int n_test_case, bitset<30> & comb) {
    
    if (n_test_case == 1) {
        for (int i = 0; i < 5; i++)
            comb[i] = 1;
    }
    else {
        backtracking(1, n, comb);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int	total_test_case;
    bitset<30>	comb;
    bool	is_possible;
    int 	answer = 0;
    
    // 0. Init
    total_test_case = 1;
    for (int i = n; i > n - 5; i--)
        total_test_case *= i;
    for (int i = 5; i > 1; i--)
        total_test_case /= i;
    
    // 1. Calculate
    for (int test_case = 1; test_case <= total_test_case; test_case++) {
        // a. set current combination set
        set_cur_comb(n, test_case, comb);
        
        // b. check is it possible from all q with ans
        is_possible = true;
        for (int i = 0, same_count; i < q.size(); i++) {
            same_count = 0;
            for (int j = 0; j < 5; j++) {
                if (comb[q[i][j] - 1] == 1)
                    same_count++;
            }
            if (same_count != ans[i]) {
                is_possible = false;
                break ;
            }
        }
        if (is_possible)
            answer++;
    }
    
    // 2. Return answer
    return answer;
}
