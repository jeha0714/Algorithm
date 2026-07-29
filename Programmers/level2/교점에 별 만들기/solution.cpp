#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*

1. 모든 교점의 좌표값을 구해서 하나의 vector안에 저장한다.
2. 상하좌우 가장 바깥쪽에 위치한 좌표값을 구한다.
3. 전체 좌표값을 2에서 측정한 기준을 기반으로 재배치한다.

*/

bool	is_int(const vector<int> & line1, const vector<int> & line2) {
    long long	a, b, c, d, e, f;
    
    a = line1[0];
    b = line1[1];
    e = line1[2];
    c = line2[0];
    d = line2[1];
    f = line2[2];
    
    if ((b * f - e * d) % (a * d - b * c) == 0 
       && (e * c - a * f) % (a * d - b * c) == 0 )
        return (true);
    else
        return (false);
}

pair<long long, long long>	find_intersection(const vector<int> & line1, const vector<int> & line2) {
    pair<long long, long long>	intersection;
    long long	a, b, c, d, e, f;
    
    a = line1[0];
    b = line1[1];
    e = line1[2];
    c = line2[0];
    d = line2[1];
    f = line2[2];
    
    intersection.first = (b * f - e * d) / (a * d - b * c);
    intersection.second = (e * c - a * f) / (a * d - b * c);
    
    return (intersection);
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>>	intersections;
    long long	a, b, c, d;
    vector<long long>	sides(4);
    
    // 0. Init
    	// a. 전체 교점을 구한다.
    for (int i = 0; i < line.size(); i++) {
        a = line[i][0];
        b = line[i][1];
        for (int j = i + 1; j < line.size(); j++) {
            c = line[j][0];
            d = line[j][1];
            if (a * d - b * c != 0 && is_int(line[i], line[j]))
                intersections.push_back(find_intersection(line[i], line[j]));
        }
    }
    	// b. 상하 좌우 가장 바깥 좌표값을 구한다.
    sides[0] = intersections[0].second;
    sides[1] = intersections[0].second;
    sides[2] = intersections[0].first;
    sides[3] = intersections[0].first;
    for (int i = 1; i < intersections.size(); i++) {
        // 1) 상
        if (sides[0] < intersections[i].second)
            sides[0] = intersections[i].second;
        // 2) 하
        if (sides[1] > intersections[i].second)
            sides[1] = intersections[i].second;
        // 3) 좌
        if (sides[2] > intersections[i].first)
            sides[2] = intersections[i].first;
        // 4) 우
        if (sides[3] < intersections[i].first)
            sides[3] = intersections[i].first;
    }
    	// c. answer 범위를 set
    answer.resize(sides[0] - sides[1] + 1);
    for (int i = 0; i < answer.size(); i++) {
        answer[i].resize(sides[3] - sides[2] + 1);
        for (int j = 0; j < answer[i].size(); j++)
            answer[i][j] = '.';
    }
    
    // 1. Calculate
        // a. 전체 좌표값을 1-b에서 측정한 기준을 기반으로 재배치한다.
    for (int i = 0, x, y; i < intersections.size(); i++) {
            // 1) 값 받기
        x = intersections[i].first;
        y = intersections[i].second;
        
        	// 2) 값 변형
        x = x - sides[2];
        y = abs(y - sides[0]);
        
        	// 3) 값 삽입
        answer[y][x] = '*';
    }
    
    // 2. Return Answer
    return answer;
}
