#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

enum {
    NONVISITED = 0,
    VISITED = 1,
};

int solution(vector<int> cards) {
    int answer = 0;
    bitset<101>	isVisited, standard;
    int	cur;
    
    // 0. Init
    
    // 1. Calculate
    for (int first = 0; first < cards.size(); first++) {
        // a. first를 시작으로 방문한곳이 나올 때 까지 방문
        standard.reset();
        cur = first;
        while (standard[cur] != VISITED) {
            standard[cur] = VISITED;
            cur = cards[cur] - 1;
        }
        
        // b. second 시작
        for (int second = 0; second < cards.size(); second++) {
            // 1). 방문하지 않은곳만 방문
            if (isVisited[second] == VISITED)
                continue;
            else {
                // 2). isVisted를 standard로 set
                isVisited = standard;
                // 3). isVisited 방문한 값이 나올때까지 방문
                cur = second;
                while (isVisited[cur] != VISITED) {
                    isVisited[cur] = VISITED;
                    cur = cards[cur] - 1;
                }
                // 4). answer 값과 비교
                answer = max((size_t)answer, standard.count() * (isVisited.count() - standard.count()));
            }
        }
    }
    
    // 2. Return answer
    return answer;
}