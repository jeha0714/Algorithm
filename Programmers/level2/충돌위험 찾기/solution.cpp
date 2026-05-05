#include <string>
#include <vector>

using namespace std;

typedef struct {
    int	cur_task_i;
    pair<int, int> cur_loc;
} robot;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<vector<int> >	odd(101, vector<int>(101, 0));
    vector<vector<int> >	even(101, vector<int>(101, 0));
    vector<robot>			robots(routes.size());
    bool					is_someone_move = false;
    int						task;
    pair<int, int>			loc, next;
    int 					answer = 0;
    
    // 0. init
    for (int i = 0; i < routes.size(); i++) {
        robots[i].cur_loc.first = points[routes[i][0] - 1][0];
        robots[i].cur_loc.second = points[routes[i][0] - 1][1];
        robots[i].cur_task_i = 1;
        
        even[robots[i].cur_loc.first][robots[i].cur_loc.second]++;
        if (even[robots[i].cur_loc.first][robots[i].cur_loc.second] == 2)
            answer++;
    }
    
    for (int time = 1; ; is_someone_move = false, time++) {
        // 1. i + 1번째 로봇이 현재 시간에 배정된 업무 수행
        for (int i = 0; i < routes.size(); i++) {
            task = robots[i].cur_task_i;
            loc = robots[i].cur_loc;
            
            // a. 모든 task를 완료했다면 continue
            if (task == routes[i].size()) {
                if (loc.first != -1) {
                    if (time % 2 == 0) {
                        odd[loc.first][loc.second]--;
                    }
                    else {
                        even[loc.first][loc.second]--;
                    }                   
                    robots[i].cur_loc.first = -1;
                }

                continue;
            }
            else
                is_someone_move = true;
            
            // b. 다음 좌표값 계산
            next.first = loc.first;
            next.second = loc.second;
            	// 1) r이 같다면 c 이동
            if (loc.first == points[routes[i][task] - 1][0])
                next.second += (points[routes[i][task] - 1][1] > loc.second ? 1 : -1);
            	// 2) r이 틀리다면 r 먼저 이동
            else
                next.first += (points[routes[i][task] - 1][0] > loc.first ? 1 : -1);
            
            // c-1. 홀수시간 처리
            if ((time) % 2 == 1) {
                even[loc.first][loc.second]--;
                odd[next.first][next.second]++;
                if (odd[next.first][next.second] == 2)
                    answer++;
            }
            // c-2. 짝수시간 처리
            else {
                odd[loc.first][loc.second]--;
                even[next.first][next.second]++;
                if (even[next.first][next.second] == 2)
                    answer++;
            }
            
            // d. 현재 위치가 도착지점이라면 다음 task로 설정
            if (next.first == points[routes[i][task] - 1][0] && next.second == points[routes[i][task] - 1][1])
                robots[i].cur_task_i++;
            
            // e. cur loc 재설정
            robots[i].cur_loc = next;
            
        }
    	// 2. 해당 시간대에 동작이 한 번이라도 없으면 없으면 정지
        if (!is_someone_move)
            break ;
    }
    
    return answer;
}