#include <vector>
#include <algorithm>

using namespace std;

class Cmp {
public:
    const int col;
    Cmp(int col) : col(col) {}
    bool operator() (const vector<int> & a, const vector<int> & b) {
    	if (a[col - 1] == b[col - 1]) {
        	return (a[0] > b[0]);
        }
        else return (a[col - 1] < b[col - 1]);
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int			answer = 0;
    vector<int>	s;
    
    // 0. Init
    	// a. sorting data with standard of col
    sort(data.begin(), data.end(), Cmp(col));
    
    	// b. init s_i
    s.resize(data.size());
    for (size_t i = 0; i < data.size(); i++) {
        s[i] = 0;
        for (size_t j = 0; j < data[i].size(); j++)
            s[i] += (data[i][j] % (i + 1));
    }
    
    // 1. Calculate
    answer = s[row_begin - 1];
    for (int i = row_begin; i < row_end; i++) {
        answer = (answer ^ s[i]);
    }
    
    // 2. Return Answer
    return answer;
}