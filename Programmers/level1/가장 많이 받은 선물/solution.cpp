#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
< 필요한 정보 >
1. 자신이 타인에게 준 선물의 총 개수
2. 자신이 타인에게 받은 선물의 총 개수

3. 자신이 특정 A에게 준 선물의 총 개수
4. 자신이 특정 A에게 받은 선물의 총 개수
*/

void	set_name(const string & names, string & a, string & b) {
    int	i;
    
    for (i = 0; i < names.length(); i++) {
        if (names[i] == ' ')
            break ;
    }
    a = names.substr(0, i);
    b = names.substr(i + 1);
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int>	um; // name과 index 매핑
    /*
		특정 A가 주고 받은 선물의 총 수
    	row[0] 은 total give
    	row[1] 은 total receive
    */
    vector<vector<int> >		total(2, vector<int>(friends.size(), 0));
    // 특정 A와 B가 주고 받은 선물의 총 수
    vector<vector<int> >		specific(friends.size(), vector<int>(friends.size(), 0)); 
    string	a, b;
    
    // 0. Init
    	// a. name과 index 매핑 값을 um에 삽입
    for (int i = 0; i < friends.size(); i++) {
        um[friends[i]] = i;
    }
    	// b. gifts를 순회하며 total과 specific 값 반영
    for (int i = 0; i < gifts.size(); i++) {
        set_name(gifts[i], a, b);
        	// 1) total 주고 받기 기록
        total[0][um[a]]++;
        total[1][um[b]]++;
        
        	// 2) specific 주고 받기 기록
        specific[um[a]][um[b]]++;
    }
    
    // 1. Calculate
    for (int i = 0, tmp; i < friends.size(); i++) {
        tmp = 0;
        
        // 내가 아닌 누군가와 선물을 주고 받은 기록을 확인
        for (int j = 0; j < friends.size(); j++) {
            if (i != j) {
                // a. 두 사람이 선물을 주고 받은 기록이 있고 차이가 있다면
                if ((specific[i][j] != 0 || specific[j][i] != 0) 
                    && specific[i][j] > specific[j][i]) {
                    tmp++;
                }
                // b. 두 사람이 선물을 주고 받은 기록이 없거나 주고 받았어도 수가 같다면
                else if ((specific[i][j] == 0 && specific[j][i] == 0) 
                         || ((specific[i][j] != 0 || specific[j][i] != 0) 
                             && specific[i][j] == specific[j][i])) {
                //else {
                    if (total[0][i] - total[1][i] > total[0][j] - total[1][j]) {
                        tmp++;
                    }
                }
            }
        }
        
        // answer 최신화
        if (tmp > answer)
            answer = tmp;
    }
    
    // 2. Return answer
    return answer;
}