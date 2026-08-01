#include <vector>

using namespace std;

/*
8!를 순서를 기반으로 모두 해봐야 함. -> 백트래킹
*/

enum {
    VISITED = true,
    NONVISITED = false,
};

void bt(int & answer, int & cur_k, vector<bool> & is_visited, const vector<vector<int>> & dungeons) {
    int	visited;
    
    // a. Rotate
    for (int i = 0; i < dungeons.size(); i++) {
        if (is_visited[i] == NONVISITED && cur_k >= dungeons[i][0]) {
            is_visited[i] = VISITED;
            cur_k -= dungeons[i][1];
            
            bt(answer, cur_k, is_visited, dungeons);
            
            is_visited[i] = NONVISITED;
            cur_k += dungeons[i][1];
        }
    }
    
    // b. Check Answer
    visited = 0;
    for (int i = 0; i < is_visited.size(); i++) {
        if (is_visited[i] == VISITED) visited++;
    }
    if (answer < visited) answer = visited;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool>	is_visited;
    
    // 0. Init
    is_visited.resize(dungeons.size());
    for (int i = 0; i < is_visited.size(); i++)
        is_visited[i] = NONVISITED;
    
    // 1. Calculate
    bt(answer, k, is_visited, dungeons);
    
    // 2. Return Answer
    return answer;
}