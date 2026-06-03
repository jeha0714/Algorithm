#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1. 완전한 문자를 hash에 담아둔다.
2. 스포 방지 단어를 하나씩 오픈하면서 hash에 담겨진 값이 존재하는지 확인한다

1. 모든 단어를 hash에 담는다.
2. 스포 방지 단어를 하나씩 확인하며 해당 단어가 하나밖에 없는지 확인한다.
*/

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    unordered_map<string, int>	um;
    string	str;
    int	s, e;
    
    // 0. 모든 단어를 hash에 담는다.
    for (int i = 0; i < message.length(); i++) {
        if (message[i] != ' ') {
            s = i;
            while (message[i] != ' ' && message[i] != '\0')
                i++;
            e = i - 1;
            str = message.substr(s, e - s + 1);
            if (um.find(str) == um.end())
                um[str] = 1;
            else
                um[str] += 1;
        }
    }
    
    // 1. 스포 방지 단어를 하나씩 확인하며 해당 단어가 하나밖에 없는지 확인한다.
    for (int i = 0, sub_s = 0; i < spoiler_ranges.size(); i++) {
        s = spoiler_ranges[i][0];
        e = spoiler_ranges[i][1];
        while (message[s] == ' ' || sub_s > s)
            s++;
        sub_s = s;
        
        /* 스포 구간에 여러 단어가 포함될 수 있다. */
        // a. s 이전의 단어 최초 시작 부분을 찾는다.
        while (sub_s >= 0 && message[sub_s] != ' ')
            sub_s--;
        sub_s++;
        // b. 한 단어씩 um.second에 1인지 확인한다.
        while (s <= e) {
            while (message[s] != ' ' && message[s] != '\0')
                s++;
            str = message.substr(sub_s, s - sub_s);
            if (um[str] == 1) {
                answer++;
                um[str]--;
            }
            else
                um[str]--;
            s++;
            sub_s = s;
        }
    }
    
    // 2. Return answer
    return answer;
}