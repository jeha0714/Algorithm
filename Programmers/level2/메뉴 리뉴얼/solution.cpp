#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
bitset으로 등록해두고 1~2^26까지 숫자를 증가시키면서 비트가 동일한지 확인하는 방법
-> 시간복잡도가 말이 안됨.
*/

/*
1. orders를 순회하면서 course에서 언급한 가능한 조합들을 모두 파악 한 후 +1
	-> 조합들을 어떻게 구할건데? 이건 cpp임
2. 조합들이 >= 2 인 경우 모두 answer에 push
3. answer 오름차순으로 sort
4. 중복되는 값 버리기
시간복잡도 -> 10C0 + ... + 10C10 = 2^10 = 1024 * 20
공간복잡도 -> 모든 조합 26C2 + ... + 26C10
*/

void	set_comb(int cur_depth, int max_depth, int last_pick, 
                 string comb, const string & s, 
                 vector<unordered_map<string, int>>	& v) {
    if (cur_depth < max_depth) {
        for (int i = last_pick + 1; i <= s.length() - max_depth + comb.length(); i++)
            set_comb(cur_depth + 1, max_depth, i, comb + s[i], s, v);
    }
    else { // cur_depth == max_depth
        if (v[max_depth].find(comb) == v[max_depth].end())
            v[max_depth][comb] = 1;
        else
            v[max_depth][comb] += 1;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<unordered_map<string, int>>	v(11);
    vector<int>							v_max(11, 2);
    
    // 0. Init
    	// a. sort orders
    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end(), less<char>());
    	// b. Set unordered_map with comb
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < course.size(); j++) {
            if (orders[i].length() >= course[j])
                set_comb(0, course[j], -1, "", orders[i], v);
        }
    }
    
    // 1. Calculate
    	// a. 가장 많이 등장한 값 찾기
    for (int i = 0; i < course.size(); i++) {
        for (unordered_map<string, int>::iterator it = v[course[i]].begin();
            it != v[course[i]].end(); it++) {
            if (v_max[course[i]] < it->second)
                v_max[course[i]] = it->second;
        }
    }
    	// b. 값에 해당되는 문자열 추가
     for (int i = 0; i < course.size(); i++) {
        for (unordered_map<string, int>::iterator it = v[course[i]].begin();
            it != v[course[i]].end(); it++) {
            if (v_max[course[i]] == it->second)
                answer.push_back(it->first);
        }
    }   
    	// c. 정렬
    sort(answer.begin(), answer.end(), less<string>());
    
    // 2. Return Answer
    return answer;
}