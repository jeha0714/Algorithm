#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int	e;
    
    // 1. Calculate
    for (int i = 0, num_not_late; i < schedules.size(); i++) {
        num_not_late = 0;
        for (int j = 0; j < 7; j++) {
            if ((startday + j) % 7 != 0 && (startday + j) % 7 != 6) {
                e = schedules[i] + 10;
                if (e % 100 >= 60) {
                    e += 100;
                    e -= 60;
                }
                if (timelogs[i][j] <= e)
                    num_not_late++;
            }
        }
        if (num_not_late == 5)
            answer++;
    }
    
    // 2. Return Answer
    return answer;
}