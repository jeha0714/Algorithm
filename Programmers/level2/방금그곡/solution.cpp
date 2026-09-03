#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

#define CHAR 'a'

size_t conv_time(const string & s) {
    size_t start, end;

    // 1. set s
    start = atoi(s.c_str()) * 60;
    start += atoi(s.c_str() + 3);

    // 2. set e
    end = atoi(s.c_str() + 6) * 60;
    end += atoi(s.c_str() + 9);

    return (end - start);
}

string solution(string m, vector<string> musicinfos) {
    string      answer = "";
    int			answer_time;
    vector<size_t> times(musicinfos.size());
    /* #붙은건 안 붙은거 + 1이라고 생각 */
    unordered_map<char, int>	um = {{'C', CHAR + 0}, {'D', CHAR + 2}, {'E', CHAR + 4}, {'F', CHAR + 5}, {'G', CHAR + 7}, {'A', CHAR + 9}, {'B', CHAR + 11}};
    // {"C#", CHAR + 1} {"D#", CHAR + 3} {'F#', CHAR + 6} {"G#", CHAR + 8} {"A#", CHAR + 10}
    vector<string>	music(musicinfos.size());
    string	v_m;

    // 0. Init
        // a. 총 재생시간을 분으로 변환
    for (size_t i = 0; i < times.size(); i++) times[i] = conv_time(musicinfos[i]);
    	// b. 음이름을 숫자로 저장
    for (size_t i = 0; i < musicinfos.size(); i++) {
        music[i].reserve(musicinfos[i].length() - 12);
        for (size_t j = musicinfos[i].find(',', 12) + 1; j < musicinfos[i].length(); j++) {
            // 1). 뒤에 #이 붙지 않은 음
            if (musicinfos[i][j + 1] != '#') music[i].push_back(um[musicinfos[i][j]]);
            // 2). 뒤에 #이 붙은 음
            else {
                music[i].push_back(um[musicinfos[i][j]] + 1);
                j++;
            }
        }
    }
    	// c. m도 숫자로 저장
    v_m.reserve(m.length());
    for (size_t i = 0; i < m.length(); i++) {
        // 1). 뒤에 #이 붙지 않은 음
        if (m[i + 1] != '#') v_m.push_back(um[m[i]]);
        // 2). 뒤에 #이 붙은 음
        else {
            v_m.push_back(um[m[i]] + 1);
            i++;
        }
    }

    // 1. Calculate
        // a. 맞는 곡이 존재하는지 찾기
    for (size_t i = 0; i < music.size(); i++) {
        for (size_t j = 0, k = 0; j < times[i] && j < music[i].length(); j++, k = 0) {
            // 1). 가장 앞이 똑같으면 비교 시작
            if (v_m[0] == music[i][j]) {
                for (k = 1; j + k < times[i]; k++) {
                    // a). k의 범위가 music을 벗어날 때
                    if (j + k >= music[i].length()) {
                        if (v_m[k] != music[i][(j + k) % music[i].length()]) break ;
                    }
                    // b). k의 범위가 music을 벗어나지 않을 때
                    else {
                        if (v_m[k] != music[i][j + k]) break ;
                    }
                }
            }
            // 2). k가 끝까지 갔는지 검사
            if (k == v_m.length()) {
                // a). answer가 존재하는 경우
                if (answer.size() == 0) {
                    answer = musicinfos[i].substr(12, musicinfos[i].find(',', 12) - 12);
                    answer_time = times[i];
                }
                // b). answer가 존재하지 않는 경우
                else {
                    if (answer_time < times[i]) {
                        answer = musicinfos[i].substr(12, musicinfos[i].find(',', 12) - 12);
                        answer_time = times[i];
                    }
                }
                break ;
            }
        }
    }

        // b. 맞는 곡이 없다면 초기화
    if (answer.size() == 0) answer = "(None)";

    // 2. Return Answer
    return answer;
}