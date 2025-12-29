#include <string>
#include <vector>

#define MIN2(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> digit_x(10, 0);
    vector<int> digit_y(10, 0);
    vector<int> pair_xy(10, 0);
    
    // 1. init digit_x & digit_y vector
    for (int i = 0; i < X.length(); i++)
        digit_x[X[i] - '0']++;
    for (int i = 0; i < Y.length(); i++)
        digit_y[Y[i] - '0']++;
    
    // 2. init pair_xy
    for (int i = 0; i < 10; i++)
        pair_xy[i] = MIN2(digit_x[i], digit_y[i]);
    
    // 3. set answer
    for (int i = 9; i > 0; i--) {
        for (int cur = 0; cur < pair_xy[i]; cur++) {
            answer.push_back(i + '0');
        }
    }
    if (answer.length() != 0) {
        for (int cur = 0; cur < pair_xy[0]; cur++) {
            answer.push_back('0');
        }   
    }
        // set special case
    else { //(answer.length() == 0)
        if (pair_xy[0] > 0)
            answer.push_back('0');
        else {
            answer.push_back('-');
            answer.push_back('1');
        }
    } 
    
    return answer;
}