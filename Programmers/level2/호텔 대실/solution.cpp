#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
1. pq에 모두 넣는다.
	- pq는 시간을 오름차순으로 정렬한다.
    - pq는 시간과 해당 book_time의 index 두 가지 정보를 pair로 받는다.

2. pq가 empty할 때까지 순회
	- in이 이면 n++하고 answer와 max값 비교, out시간을 pq에 push
    - out이면 n--
*/

class compare {
public:
    bool	operator() (const pair<string, int> & a, const pair<string, int> & b) {
        if (a.first != b.first)
            return (a.first > b.first);
        else
            return (a.second > b.second);
    }
};

string	calc(const string & s) {
    string	str = s;;
    
    str[3] += 1;
    
    if (str[3] == '6') {
        str[3] = '0';
        str[1] += 1;
    }
    if (str[1] == '9' + 1) {
        str[1] = '0';
        str[0] += 1;
    }
    return (str);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare>	pq;
    pair<string, int>	tmp;
    int	n = 0;
    
    // 0. Init
    for (int i = 0; i < book_time.size(); i++) {
        tmp = make_pair(book_time[i][0], i);
        pq.push(tmp);
    }
    
    // 1. Calculate
    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        
        if (tmp.second != -1) {
            tmp.first = calc(book_time[tmp.second][1]);
            tmp.second = -1;
            pq.push(tmp);
            n++;
            answer = answer >= n ? answer : n;
        }
        else { // tmp.second == 'O'
            n--;
        }
    }
    
    // 2. Return Answer
    return answer;
}