#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int	angle[3];
    int	mv_value[3];
    int answer = 0;
    
    // 0. Init
    	// 720 * 60 = 43200 이 360도라고 판단
    mv_value[2] = 720;
    mv_value[1] = 12;
    mv_value[0] = 1;
    
    angle[2] = s1 * mv_value[2];
    angle[1] = s1 * mv_value[1] + m1 * 720;
    angle[0] = (s1 * mv_value[0] + m1 * mv_value[1] * 5 + h1 * 3600) % 43200;
    
    	// 최초에 울리고 시작하는지 판단
    if (angle[2] == angle[0] || angle[2] == angle[1])
        answer++;
    
    // 1. Calc
    while (!(h1 == h2 && m1 == m2 && s1 == s2)) {
        // a. check alarm : 1초가 지난 후의 각도 값을 비교
        	// 1) 초침 분침 시침 모두 만났을 때
        if ((angle[2] < angle[1] && angle[1] + mv_value[1] <= angle[2] + mv_value[2]) && (angle[2] < angle[0] && angle[0] + mv_value[0] <= angle[2] + mv_value[2])) {
            if (angle[0] + mv_value[0] == 43200 && angle[1] + mv_value[1] == 43200 && angle[2] + mv_value[2] == 43200)
                answer++;
            else
                answer += 2;
        }
        	// 2) 초침과 분침 만났을 때
        else if (angle[2] < angle[1] && angle[1] + mv_value[1] <= angle[2] + mv_value[2]) {
            answer++;
        }
        	// 3) 초침과 시침 만났을 때
        else if (angle[2] < angle[0] && angle[0] + mv_value[0] <= angle[2] + mv_value[2]) {
            answer++;
        }
        
        // b. move
        angle[0] += mv_value[0];
        angle[1] += mv_value[1];
        angle[2] += mv_value[2];
        s1++;
        
        if (s1 == 60) {
            angle[2] = 0;
            s1 = 0;
            m1++;
        }
        if (m1 == 60) {
            angle[1] = 0;
            m1 = 0;
            h1++;
        }
        if (angle[0] == 43200)
            angle[0] = 0;
    }
    
    // 2. Return answer
    return answer;
}