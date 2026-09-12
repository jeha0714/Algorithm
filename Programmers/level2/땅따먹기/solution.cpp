#include <vector>

using namespace std;

/*
dp로 해결하기
*/
int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>>	dp(2, vector<int>(4, 0));

    // 0. Init
    for (size_t i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    
    // 1. Calculate
        // a. 행을 하나씩 올라가면서
    for (size_t r = 1; r < land.size(); r++) {
        // b. 각 열을 판단
        for (size_t c = 0; c < 4; c++) {
            for (size_t i = 0; i < 4; i++) {
                // 1). 현재 계산 할 행이 홀수 라면
                if (r % 2 == 1) {
                    if (c != i && dp[1][c] < dp[0][i] + land[r][c])
                        dp[1][c] = dp[0][i] + land[r][c];
                }
                // 2). 현재 계산 할 행이 짝수 라면
                else {
                    if (c != i && dp[0][c] < dp[1][i] + land[r][c])
                        dp[0][c] = dp[1][i] + land[r][c];
                }
            }
        }
    }
    	// c. 마지막 항 중 가장 큰 값 찾기
    if (land.size() % 2 == 0) {
        for (size_t i = 0; i < 4; i++)
            answer = answer > dp[1][i] ? answer : dp[1][i];
    }
    else {
        for (size_t i = 0; i < 4; i++)
            answer = answer > dp[0][i] ? answer : dp[0][i];
    }

    // 2. Return Answer
    return answer;
}