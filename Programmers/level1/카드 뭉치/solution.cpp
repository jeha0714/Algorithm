#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int	i_c1, i_c2;
    
    // 0. Init
    i_c1 = 0; i_c2 = 0;
    
    // 1. Calculate
    for (int i = 0; i < goal.size(); i++) {
        if (i_c1 < cards1.size() && goal[i].compare(cards1[i_c1]) == 0) i_c1++;
        else if (i_c2 < cards2.size() && goal[i].compare(cards2[i_c2]) == 0) i_c2++;
        else {
            answer = "No";
            break ;
        }
    }
    
    // 2. Return Answer
    return answer;
}