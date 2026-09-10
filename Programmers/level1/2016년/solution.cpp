#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int>	day = {0, 31, 29, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    vector<string> week = {"FRI", "SAT", "SUN", "MON",
                          "TUE", "WED", "THU"};
    int	days;
    
    // 0. Init
    days = 0;
    
    // 1. Calculate
    for (int i = 1; i < a; i++) days += day[i];
    days += (b - 1);
    answer = week[days % 7];
    
    // 2. Return Answer
    return answer;
}