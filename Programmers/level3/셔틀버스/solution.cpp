#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. timetable을 정렬
2. 현재 도착한 시간의 셔틀버스에 태울 수 있는 사람들을 i로 늘려나감
3. 마지막 셔틀버스에 태울 수 있는 사람들의 index를 파악
	a. 자리가 널널한 경우
    	1) 셔틀 도착 시간에 승차
    b. 자리가 꽉 차는 경우
        1) 마지막 셔틀버스에 타는 사람들의 시간이 모두 같아면 그 시간 -00:01
        2) 마지막 셔틀버스에 타는 사람들의 시간이 조금이라도 다르다면 가장 큰 값 -00:01
*/

void	add_time(string & time, int adding) {
    int hour, min;
    
    hour = stoi(time);
    min = stoi(&time[3]);
    min += adding;
    
    if (min >= 60) {
        hour++;
        min -= 60;
    }
    time[0] = '0' + (hour / 10);
    time[1] = '0' + (hour % 10);
    time[3] = '0' + (min / 10);
    time[4] = '0' + (min % 10);
}

string	sub_time(string time, int subtraction) {
    int hour, min;
    
    hour = stoi(time);
    min = stoi(&time[3]);
    min -= subtraction;
    
    if (min < 0) {
        hour--;
        min += 60;
    }
    time[0] = '0' + (hour / 10);
    time[1] = '0' + (hour % 10);
    time[3] = '0' + (min / 10);
    time[4] = '0' + (min % 10);
    
    return (time);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    string	cur_time, max_time;
    int cur_n, cur_m;
    int	i;
    
    // 0. Init
        // a. timetable을 오름차순으로 정렬
    sort(timetable.begin(), timetable.end(), less<string>());
    
    // 1. Calculate
    // a. 현재 도착한 시간의 셔틀버스에 태울 수 있는 사람들을 i로 늘려나감
    for (cur_time = "09:00", cur_n = 1, cur_m = 0, i = 0; cur_n < n; add_time(cur_time, t), cur_n++, cur_m = 0) {
        while (i < timetable.size() && cur_time.compare(timetable[i]) >= 0 && cur_m < m) {
            i++;
            cur_m++;
        }
    }
    // b. 마지막 셔틀버스에 태울 수 있는 사람들의 index를 파악
    while (i < timetable.size() && cur_time.compare(timetable[i]) >= 0 && cur_m < m) {
        i++;
        cur_m++;
    }
        // 1) 셔틀 자리가 널널한 경우
    if (cur_m < m)
        answer = cur_time;
        // 2) 셔틀 자리가 꽉 찬 경우
    else {
            // a) 마지막 셔틀버스에 타는 사람들의 시간이 모두 같아면 그 시간 -00:01
            // b) 마지막 셔틀버스에 타는 사람들의 시간이 조금이라도 다르다면 가장 큰 값 -00:01
        answer = sub_time(timetable[i - 1] , 1);
    }
    
    // 2. Return answer
    return answer;
}