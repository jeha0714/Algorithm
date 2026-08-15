#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
1. s를 집합 단위로 분리해서 삽입한다.
2. size 단위로 오름차순 정렬한다
3. 맨 앞 집합부터 하나씩 answer에 추가해가며 unordered_set에도 삽입한다
*/

bool compare(const vector<int> & a, const vector<int> & b) {
    return (a.size() < b.size());
}

vector<int> solution(string s) {
    vector<int> answer;
    const char *	ss = s.c_str();
    vector<vector<int>>	v;
    unordered_set<int>	us;
    
    // 0. Init
    v.resize(500);
    	// a. s를 집합 단위로 분리해서 삽입한다.
    for (int i_s = 1, i_v = -1; i_s < s.length(); i_s++) {
        	// 1) 집합의 시작인 경우
        if (s[i_s] == '{') {
            i_v++;
            // 2) 해당 집합이 끝날 때 까지 삽입
            while (s[i_s] != '}') {
                // a) 숫자를 찾는다
                while (!('0' <= s[i_s] && s[i_s] <= '9')) i_s++;
                // b) 숫자를 변환해서 vector에 삽입한다.
                v[i_v].push_back(atoi(ss + i_s));
                // c) 숫자를 건너뛴다.
                while (('0' <= s[i_s] && s[i_s] <= '9')) i_s++;
            }
        }
    }
		// b. size 단위로 오름차순 정렬한다
    sort(v.begin(), v.end(), compare);
    
    // 1. Calculate
		// a. 맨 앞 집합부터 하나씩 answer에 추가해가며 unordered_set에도 삽입한다
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (us.find(v[i][j]) == us.end()) {
                us.insert(v[i][j]);
                answer.push_back(v[i][j]);
                break ;
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}