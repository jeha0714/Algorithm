#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	compare0(const vector<int> & a, const vector<int> & b) {
    return a[0] < b[0];
}
bool	compare1(const vector<int> & a, const vector<int> & b) {
    return a[1] < b[1];
}
bool	compare2(const vector<int> & a, const vector<int> & b) {
    return a[2] < b[2];
}
bool	compare3(const vector<int> & a, const vector<int> & b) {
    return a[3] < b[3];
}

void	sorting(vector<vector<int>> & answer, int v_i) {
    if (v_i == 0) sort(answer.begin(), answer.end(), compare0);
    else if (v_i == 1) sort(answer.begin(), answer.end(), compare1);
    else if (v_i == 2) sort(answer.begin(), answer.end(), compare2);
    else if (v_i == 3) sort(answer.begin(), answer.end(), compare3);
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int v_i;
    
    // 0. Init
    if (ext == "code") v_i = 0;
    else if (ext == "date") v_i = 1;
    else if (ext == "maximum") v_i = 2;
    else if (ext == "remain") v_i = 3;
    
    // 1. Calculate
    	// a. add val_ext > ext to answer
    for (int i = 0; i < data.size(); i++) {
        if (val_ext > data[i][v_i])
            answer.push_back(data[i]);
    }
    	// b. sort by standard
    if (sort_by == "code") v_i = 0;
    else if (sort_by == "date") v_i = 1;
    else if (sort_by == "maximum") v_i = 2;
    else if (sort_by == "remain") v_i = 3;
    sorting(answer, v_i);
    
    // 2. Return answer
    return answer;
}