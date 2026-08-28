#include <string>
#include <vector>

using namespace std;

/*
가장 큰 사람과 남는 무게 제한과의 차이가 가장 작은 사람을 함께 태우기
*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    int	weight[241];
    int	i_heavy, i_light, cur_limit;
    
    // 0. Init
    	// a. 사람들의 몸무게 저장
    for (int i = 0; i <= 240 ; i++) weight[i] = 0;
    for (int i = 0; i < people.size(); i++) weight[people[i]]++;
    
    // 1. Calculate
    i_heavy = 240;
    while (i_heavy > 0) {
        if (weight[i_heavy] == 0) i_heavy--;
        else {
            cur_limit = limit - i_heavy;
            weight[i_heavy]--;
            answer++;
            i_light = cur_limit > i_heavy ? i_heavy : cur_limit;
            while (i_light > 0) {
                if (weight[i_light] == 0) i_light--;
                else {
                    weight[i_light]--;
                    break ;
                }
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}