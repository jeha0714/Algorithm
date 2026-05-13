#include <vector>
#include <algorithm>

using namespace std;

bool	compare(const pair<int, int> & a, const pair<int, int> & b) {
    return (a.second > b.second);
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<pair<int, int>>	info;
    int total;
    
    // 0. Init
    answer += picks[0];
    answer += picks[1];
    answer += picks[2];
    total = 0;
    for (int i = 1; i <= minerals.size() && i <= answer * 5; i++) {
        if (!minerals[i - 1].compare("diamond"))
            total += 25;
        else if (!minerals[i - 1].compare("iron"))
            total += 5;
        else
            total += 1;
        
        if (i % 5 == 0) {
            info.push_back(make_pair(i / 5, total));
            total = 0;
        }
    }
    if (total != 0)
        info.push_back(make_pair(info.size() + 1, total));
    sort(info.begin(), info.end(), compare);
    
    total = 0;
    for (int i = 0; i < info.size(); i++) {
        if (picks[0] > 0) {
            for (int j = 0; j < 5 && (info[i].first - 1) * 5 + j < minerals.size(); j++)
                total += 1;
            picks[0]--;
        }
        else if (picks[1] > 0) {
            for (int j = 0; j < 5 && (info[i].first - 1) * 5 + j < minerals.size(); j++) {
                if (!minerals[(info[i].first - 1) * 5 + j].compare("diamond"))
                    total += 5;
                else
                    total += 1;
            }
            picks[1]--;
        }
        else if (picks[2] > 0) {
            total += info[i].second;
            picks[2]--;
        }
        else
            break ;
    }
    answer = total;
    
    return answer;
}