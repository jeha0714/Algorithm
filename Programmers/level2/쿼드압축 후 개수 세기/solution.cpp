#include <vector>

using namespace std;

/*
처음(r1, c1)과 끝(r2, c2)이 주어졌을 때
1. 해당 공간이 모두 동일한 숫자인지 판단
	동일하다면 현재 area에 값 추가
2. 해당 공간이 모두 동일한 숫자가 아니라면 
	a. compress를 호출할건데
    	- 해당 공간을 4공간으로 나눠야 함
	b. 다시 compress를 호출
*/
pair<int, int>	compress(const int r1, const int c1,
                 const int r2, const int c2,
                 const vector<vector<int>> & arr) {
    pair<int, int>	area(0, 0), tmp;
    int				pivot;
    bool			flag;
    
    // 1. 해당 공간이 모두 동일한 숫자인지 판단
    pivot = arr[r1][c1];
    flag = true;
    for (int r = r1; r < r2 && flag; r++) {
        for (int c = c1; c < c2 && flag; c++) {
            if (pivot != arr[r][c])
                flag = false;
        }
    }
    if (flag) {
        if (pivot == 0) area.first++;
        else area.second++;
    }
    else {
        // a. 좌측 상단
        tmp = compress(r1, c1, (r1 + r2) / 2, (c1 + c2) / 2, arr);
        area.first += tmp.first;
        area.second += tmp.second;
        
        // b. 우측 상단
        tmp = compress(r1, (c1 + c2) / 2, (r1 + r2) / 2, c2, arr);
        area.first += tmp.first;
        area.second += tmp.second;
        
        // c. 좌측 하단
        tmp = compress((r1 + r2) / 2, c1, r2, (c1 + c2) / 2, arr);
        area.first += tmp.first;
        area.second += tmp.second;
        
        // d. 우측 하단
        tmp = compress((r1 + r2) / 2, (c1 + c2) / 2, r2, c2, arr);
        area.first += tmp.first;
        area.second += tmp.second;
    }
    
    return (area);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    pair<int, int>	area;
    
    // 0. Init
    
    // 1. Calculate
    	// a. 영역을 나눈다.
    area = compress(0, 0, arr.size(), arr.size(), arr);
    
    	// b. 최대 영역 값을 answer에 삽입
    answer.push_back(area.first);
    answer.push_back(area.second);
    
    // 2. Return Answer
     return answer;
}