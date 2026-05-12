#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // 0. Init
    
    // 1. Calculate
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0)
                triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
            else if (j == triangle[i].size() - 1)
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            else {
                triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
            }
            
            answer = max(triangle[i][j], answer);
        }
    }
    
    // 2. Return answer
    return answer;
}