#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
1. 누가 누구를 신고했는지도 알아야 함. -> unordered_set
2. 누가 몇 번 신고 받았는지도 알아야 함. -> unordered_map
3. 누가 벤인지 알아야 함 -> vector
*/

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int>		num_report;
    unordered_map<string, int>		name_map_index;
    vector<unordered_set<string>>	who_report;
    vector<string>					who_ban;
    string							ban_name;
    
    // 0. Init
    	// a. init num_report & name_map_index
    for (int i = 0; i < id_list.size(); i++) {
        num_report[id_list[i]] = 0;
        name_map_index[id_list[i]] = i;
    }
    	// b. init who_report & set num_report
    who_report.resize(id_list.size());
    for (int i = 0, i_space, i_name; i < report.size(); i++) {
        i_space = report[i].find(' ');
        i_name = name_map_index[report[i].substr(0, i_space)];
        ban_name = report[i].substr(i_space + 1);
        
        if (who_report[i_name].find(ban_name) == who_report[i_name].end()) {
            who_report[i_name].insert(ban_name);
            num_report[ban_name] += 1;
        }
    }
    
    // 1. Calculate
    for (unordered_map<string ,int>::iterator it = num_report.begin();
        it != num_report.end(); it++) {
        if (it->second >= k) {
            for (int i = 0; i < id_list.size(); i++) {
                if (who_report[i].find(it->first) != who_report[i].end()) {
                    answer[i]++;
                }
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}