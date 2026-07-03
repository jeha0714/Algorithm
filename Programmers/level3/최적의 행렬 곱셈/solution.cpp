#include <vector>
#include <cmath>

using namespace std;

#define INTMAX 2147483647

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int	v_s = matrix_sizes.size();
    vector<vector<int>>	dp(v_s, vector<int>(v_s, INTMAX));
    
    // 0. Init
    for (int r = 0; r <= v_s - 1; r++)
        dp[r][r] = 0;
    
    // 1. Calculate
    for (int r = v_s - 2; r >= 0; r--) {
        for (int c = r + 1; c <= v_s - 1; c++) {
            for (int cmp_r = r + 1; cmp_r <= c; cmp_r++) {
                // a. 끝이거나
                if (cmp_r == r + 1) {
                    dp[r][c] = min(dp[r][c], dp[cmp_r][c] + matrix_sizes[r][0] * matrix_sizes[cmp_r][0] * matrix_sizes[c][1]);
                    
                }
                else if (cmp_r == c) {
                    dp[r][c] = min(dp[r][c], dp[r][c - 1] + matrix_sizes[r][0] * matrix_sizes[cmp_r][0] * matrix_sizes[cmp_r][1]);
                }
                // b. 중간이거나
                else {
                    dp[r][c] = min(dp[r][c], dp[r][cmp_r - 1] + dp[cmp_r][c] + matrix_sizes[r][0] * matrix_sizes[cmp_r][0] * matrix_sizes[c][1]);
                }
            }
        }
    }
    	// Set Answer
    answer = dp[0][v_s - 1];
    
    // 2. Retrun Answer
    return answer;
}