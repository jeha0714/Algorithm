#include <vector>

using namespace std;

/*
1. 좌표를 모두 찍어둔다.
2. 구간별 크기를 계산해둔다.
3. 각 range별 값을 계산한다.
*/
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double>	answer;
    vector<int>		loc;
    vector<int>		area;
    int				a, b;
    
    // 0. Init
    	// a. y좌표를 모두 찍어둔다.
    loc.reserve(201);
    loc.push_back(k);
    while (k > 1) {
        if (k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        loc.push_back(k);
    }
    	// b. 구간별 면적 크기를 누적합으로 계산
    area.resize(loc.size());
    area[0] = 0;
    for (size_t i = 1; i < area.size(); i++)
        area[i] = area[i - 1] + loc[i - 1] + loc[i];
    
    // 1. Calculate
    answer.resize(ranges.size());
    for (size_t i = 0; i < ranges.size(); i++) {
        a = ranges[i][0];
        b = ranges[i][1];
        if (a > static_cast<int>(area.size()) - 1 + b)
            answer[i] = -1.0;
        else
            answer[i] = (area[area.size() - 1 + b] - area[a]) / 2.0;
    }
    
    // 2. Return Answer
    return answer;
}