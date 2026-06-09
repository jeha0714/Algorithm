#include <string>
#include <vector>
#include <cmath>

using namespace std;

int	len(pair<int, int> & tmp, int num) {
    pair<int, int> n;
    
    if (num == 0)
        n.first = 3;
    else
        n.first = num / 3;
    n.second = 1;
    
    return (abs(tmp.first - n.first) + abs(tmp.second - n.second));
}

void	set(pair<int, int> & tmp, int num) {
    if (num == 0)
        tmp.first = 3;
    else
        tmp.first = num / 3;
    tmp.second = 1;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int>	l, r;
    
    // 0. Init
    l = make_pair(3, 0);
    r = make_pair(3, 2);
    
    // 1. Calculate
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) {
            answer.push_back('L');
            l.first = numbers[i] / 3;
            l.second = 0;
        }
        else if (numbers[i] != 0 && numbers[i] % 3 == 0) {
            answer.push_back('R');
            r.first = numbers[i] / 3 - 1;
            r.second = 2;
        }
        else {
            if (len(l, numbers[i]) < len(r, numbers[i])) {
                answer.push_back('L');
                set(l, numbers[i]);
            }
            else if (len(l, numbers[i]) > len(r, numbers[i])) {
                answer.push_back('R');
                set(r, numbers[i]);
            }
            else {
                if (!hand.compare("left")) {
                    answer.push_back('L');
                    set(l, numbers[i]);
                }
                else {
                    answer.push_back('R');
                    set(r, numbers[i]);
                }
            }
        }
    }
    
    // 2. Return answer
    return answer;
}