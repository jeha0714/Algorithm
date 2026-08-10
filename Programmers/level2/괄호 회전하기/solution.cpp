#include <string>
#include <vector>
#include <deque>

using namespace std;

/*
O(n^2)으로 풀지말아보자
규칙을 찾자.
움직일때는 한 덩치가 연속으로 존재해야한다. 끊기면 안되는거지.
그렇다면 가장 먼저 파악해야 하는건
s가 '올바른 괄호 문자열' 이 되는 경우가 존재할때가 있는가?
-> 이걸 어떻게 파악할 수 있는가.
-> deque로 올바른 괄호열은 바로바로 제거하고 남은 경우에 대해서 front와 back을 봤을 때 쌍이 맞다면 올바른 문자열
*/

int solution(string s) {
    int answer = 0;
    deque<char>	dq;
    bool		is_possible = false;
    int			mv = -1;
    
    // 0. Init
        // a. 올바른 괄호열이 가능한 때가 있는지 파악
    	// 1) deque에 현재 상태 push & pop
    for (int i = 0; i < s.length(); i++) {
        if (dq.empty()) {
            dq.push_back(s[i]);
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') mv = i;
        }
        else {
            if (s[i] == ')' && dq.back() == '(') dq.pop_back();
            else if (s[i] == '}' && dq.back() == '{') dq.pop_back();
            else if (s[i] == ']' && dq.back() == '[') dq.pop_back();
            else {
                dq.push_back(s[i]);
                if (s[i] == ')' || s[i] == '}' || s[i] == ']') mv = i;
            }
        }
    }
    	// 2) deque에 남은 값이 있다면 front & back을 확인하며 Push & pop
    while (!dq.empty()) {
        if (dq.front() == ')' && dq.back() == '(') {
            dq.pop_front();
            dq.pop_back();
        }
        else if (dq.front() == '}' && dq.back() == '{') {
            dq.pop_front();
            dq.pop_back();
        }
        else if (dq.front() == ']' && dq.back() == '[') {
            dq.pop_front();
            dq.pop_back();
        }
        else break ;
    }
    if (dq.empty()) is_possible = true;
    
        // b. 올바른 괄호열이 처음부터 불가능하다면 회전을 할 필요가 없음.
    if (!is_possible) return (0);
    
    // 1. Calculate
   	// -> 이제 올바른 괄호열이 가능한 경우만 남은 상태 
    // -> '올바른 괄호열'의 경계 수만 찾으면 됨
    for (int i = mv + 1; i < s.length(); i++) {
        if (dq.empty()) dq.push_back(s[i]);
        else {
            if (s[i] == ')' && dq.back() == '(') dq.pop_back();
            else if (s[i] == '}' && dq.back() == '{') dq.pop_back();
            else if (s[i] == ']' && dq.back() == '[') dq.pop_back();
            else dq.push_back(s[i]);
            if (dq.empty()) answer++;
        }
    }
    if (mv != -1) answer++;
    
    // 2. Return Answer
    return answer;
}