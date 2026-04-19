#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int num_last_depth_child;
    int	num_dist;
    int	max_split;
    int	num_leaf;
}infos;

int solution(int dist_limit, int split_limit) {
    int answer = 0;
    infos	info, tmp;
    queue<infos>	q;
    
    // 0. Init
    info.num_last_depth_child = 1;
    info.num_dist = 0;
    info.max_split = 1;
    info.num_leaf = 1;
    q.push(info);
    
    // 1. 현재 상태를 들고옴
    while (!q.empty()) {
        info = q.front();
        q.pop();
        
        if (info.num_dist < dist_limit) {
            // a. 마지막 depth에 2개의 node를 붙임 
            // 1 ~ 현재 depth의 leaf 수 만큼
            for (int i = 1; i <= info.num_last_depth_child; i++) {
                tmp = info;
                tmp.num_dist += i;
                tmp.max_split *= 2;
                tmp.num_leaf = tmp.num_leaf - i + i * 2;
                tmp.num_last_depth_child = i * 2;
                if (tmp.max_split <= split_limit && tmp.num_dist <= dist_limit)
                    q.push(tmp);
                else
                    break ;
            }
            
            // b. 마지막 depth에 3개의 node를 붙임 
            // 1 ~ 현재 depth의 leaf 수 만큼
            for (int i = 1; i <= info.num_last_depth_child; i++) {
                tmp = info;
                tmp.num_dist += i;
                tmp.max_split *= 3;
                tmp.num_leaf = tmp.num_leaf - i + i * 3;
                tmp.num_last_depth_child = i * 3;
                if (tmp.max_split <= split_limit && tmp.num_dist <= dist_limit)
                    q.push(tmp);
                else
                    break ;
            }
            
        }
        answer = max(answer, info.num_leaf);
    }
    
    return answer;
}
