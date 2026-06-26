#include <string>
#include <vector>

using namespace std;

bool	is_barrier_row(pair<int, int> loc, int mv, vector<string> & park) {
    int	target = loc.first + mv;
    
    if (target < loc.first) {
        for (; target < loc.first; target++) {
            if (park[target][loc.second] == 'X')
                return (true);
        }
    }
    else {
        for (; loc.first <= target; loc.first++) {
            if (park[loc.first][loc.second] == 'X')
                return (true);
        }
    }
        
    return (false);
}

bool	is_barrier_col(pair<int, int> loc, int mv, vector<string> & park) {
    int	target = loc.second + mv;
    
    if (target < loc.second) {
        for (; target < loc.second; target++) {
            if (park[loc.first][target] == 'X')
                return (true);
        }
    }
    else {
        for (; loc.second <= target; loc.second++) {
            if (park[loc.first][loc.second] == 'X')
                return (true);
        }
    }
        
    return (false);
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int>	loc;
    char	cmd;
    int		mv;
    
    // 0. Init
    for (int r = 0; r < park.size(); r++) {
        for (int c = 0; c < park[r].length(); c++) {
            if (park[r][c] == 'S') {
                loc.first = r;
                loc.second = c;
            }
        }
    }
    
    // 1. Calculate
    for (int i = 0; i < routes.size(); i++) {
        cmd = routes[i][0];
        mv = routes[i][2] - '0';
        
        if (cmd == 'N'
            && (0 <= loc.first - mv && loc.first - mv < park.size())
            && !is_barrier_row(loc, -mv, park)) {
            loc.first -= mv;
        }
        else if (cmd == 'S'
                 && (0 <= loc.first + mv && loc.first + mv < park.size())
                 && !is_barrier_row(loc, mv, park)) {
            loc.first += mv;
        }
        else if (cmd == 'W'
                 && (0 <= loc.second - mv && loc.second - mv < park[loc.first].length())
                 && !is_barrier_col(loc, -mv, park)) {
            loc.second -= mv;
        }
        else if (cmd == 'E'
                 && (0 <= loc.second + mv && loc.second + mv < park[loc.first].length())
                 && !is_barrier_col(loc, mv, park)) {
            loc.second += mv;
        }
    }
    
    // 2. Return Answer
    answer.push_back(loc.first);
    answer.push_back(loc.second);
    return answer;
}