#include <vector>
#include <bitset>
#include <queue>

using namespace std;

/*
가장 간단한 방법은 20^5을 돌면서 확인하기

각 signal의 노란불 구간은 항상 정해져있음.
1. 켜질 때 
	a. 자기 값을 반전 시킨다.
    b. 모든 값이 켜져 있는지 확인한다.
    	1) 모든 값이 켜져있다면 그대로 return
        2) 하나라도 꺼져있다면 queue에 삽입
    c. queue에 노란불이 꺼지는 순간을 계산해서 <time, index>로 삽입한다.
2. 꺼질 때
	a. 자기 값을 반전 시킨다.
    b. queue에 노란불 순간을 계산해서 <time, index>로 삽입한다
*/

int solution(vector<vector<int>> signals) {
    int answer = -1;
    /* pair.first = time, pair.second = index */
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >	pq;
    bitset<5>	status;
    int	time, index;
    
    // 0. Init
    for (int i = 0; i < signals.size(); i++)
        pq.push(make_pair(signals[i][0] + 1, i));
    
    // 1. Calculate
    while(true) {
        time = pq.top().first;
        index = pq.top().second;
        pq.pop();
        
        if (time > 50000000)
        //if (time > 100)
            break ;
        
        // a. 이제 노란색으로 전환되는 경우
        if (!status[index]) {
            // 1) 자기 값을 반전 시킨다.
            status.flip(index);
            
            // 2) 다음 top이 다른 시간대이고 모든 값이 켜져 있는지 확인한다.
                // 모든 값이 켜져있다면 그대로 return
            if (pq.top().first != time && status.count() == signals.size())
                return (time);
            
            // 3) queue에 노란불이 꺼지는 순간을 계산해서 <time, index>로 삽입한다.
            pq.push(make_pair(time + signals[index][1], index));
        }
        // b. 이제 노란색이 꺼지는 경우
        else {
            // 1) 자기 값을 반전 시킨다.
            status.flip(index);
            
    		// 2) queue에 노란불 순간을 계산해서 <time, index>로 삽입한다
            pq.push(make_pair(time + signals[index][2] + signals[index][0], index));
        }
    }
    
    // 2. Return answer
    return answer;
}