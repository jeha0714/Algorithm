#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    int	aimX, aimY;
    double	dist1, dist2;
    
    // 0. Init
    answer.resize(balls.size());
    
    // 1. Calculate
    for (int test_case = 0; test_case < balls.size(); test_case++) {
        aimX = balls[test_case][0];
        aimY = balls[test_case][1];
        
        // a. x축이 같은 경우
        if (startX == aimX) {
            // 1) x = 0
            dist1 = static_cast<double>(abs(startY - aimY)) / 2;
            answer[test_case] = static_cast<int>(round(4 * (dist1 * dist1 + startX * startX)));
            
            // 2) x = m
            dist1 = m - startX;
            dist2 = static_cast<double>(abs(startY - aimY)) / 2;
            answer[test_case] = min(answer[test_case], static_cast<int>(round(4 * (dist1 * dist1 + dist2 * dist2))));
            
            // 3) x = startX
            if (startY < aimY)
                answer[test_case] = min(answer[test_case], (startY + aimY) * (startY + aimY));
            else if (startY > aimY)
                answer[test_case] = min(answer[test_case], (n - startY + n - aimY) * (n - startY + n - aimY));
        }
        // b. y축이 같은 경우
        else if (startY == aimY) {
            // 1) y = 0
            dist1 = static_cast<double>(abs(startX - aimX)) / 2;
            answer[test_case] = static_cast<int>(round(4 * (dist1 * dist1 + startY * startY)));
            
            // 2) y = n
            dist1 = n - startY;
            dist2 = static_cast<double>(abs(startX - aimX)) / 2;
            answer[test_case] = min(answer[test_case], static_cast<int>(round(4 * (dist1 * dist1 + dist2 * dist2))));
        
            // 3) y = startY
            if (startX < aimX)
                answer[test_case] = min(answer[test_case], (startX + aimX) * (startX + aimX));
            else if (startX > aimX)
                answer[test_case] = min(answer[test_case], (m - startX + m - aimX) * (m - startX + m - aimX));
        }
        
        // c. x, y축이 전혀 다른 경우
        else {
            // 1) x = 0;
            dist1 = abs(startY - aimY);
            dist2 = dist1 * aimX / (startX + aimX);
            dist1 = dist1 * startX / (startX + aimX);
            dist1 = sqrt(dist1 * dist1 + startX * startX);
            dist2 = sqrt(dist2 * dist2 + aimX * aimX);
            answer[test_case] = static_cast<int>(round((dist1 + dist2) * (dist1 + dist2)));
                
            // 2) x = m;
            dist1 = abs(startY - aimY);
            dist2 = dist1 * (m - aimX) / (2 * m - (startX + aimX));
            dist1 = dist1 * (m - startX) / (2 * m - (startX + aimX));
            dist1 = sqrt(dist1 * dist1 + (m - startX) * (m - startX));
            dist2 = sqrt(dist2 * dist2 + (m - aimX) * (m - aimX));
            answer[test_case] = min(answer[test_case], static_cast<int>(round(((dist1 + dist2) * (dist1 + dist2)))));
                
            // 3) y = 0;
            dist1 = abs(startX - aimX);
            dist2 = dist1 * aimY / (startY + aimY);
            dist1 = dist1 * startY / (startY + aimY);
            dist1 = sqrt(dist1 * dist1 + startY * startY);
            dist2 = sqrt(dist2 * dist2 + aimY * aimY);
            answer[test_case] = min(answer[test_case], static_cast<int>(round(((dist1 + dist2) * (dist1 + dist2)))));
                
            // 4) y = n;
            dist1 = abs(startX - aimX);
            dist2 = dist1 * (n - aimY) / (2 * n - (startY + aimY));
            dist1 = dist1 * (n - startY) / (2 * n - (startY + aimY));
            dist1 = sqrt(dist1 * dist1 + (n - startY) * (n - startY));
            dist2 = sqrt(dist2 * dist2 + (n - aimY) * (n - aimY));
            answer[test_case] = min(answer[test_case], static_cast<int>(round(((dist1 + dist2) * (dist1 + dist2)))));
        }
    }
    
    // 2. Return Answer
    return answer;
}