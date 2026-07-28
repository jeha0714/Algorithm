#include <string>
#include <vector>

using namespace std;

enum {
    i_hour = 0,
    i_min = 3,
    i_num_car = 6,
    i_condition = 11,
};

int	time_stoi(const string & s) {
    int	time = 0;
    
    time = atoi(s.c_str()) * 60;
    time += atoi(s.c_str() + i_min);
    
    return (time);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<int> total(10000, 0);
    vector<int> time_in(10000, -1);
    
    // 0. Init
    
    // 1. Calculate
        // 1-1. Calculate total time
    for (int i = 0, num_car, gap; i < records.size(); i++) {
        // a. Check Condition
        if (records[i].compare(i_condition, 2, "IN") == 0) {
            // 1) set num_car
            num_car = atoi(records[i].c_str() + i_num_car);
            
            // 2) set time_in[num_car] to time
            time_in[num_car] = time_stoi(records[i]);
        }
        else { // OUT
            // 1) set num_car index
            num_car = atoi(records[i].c_str() + i_num_car);
            
            // 2) Calculate total time
            gap = time_stoi(records[i]);
            gap = gap - time_in[num_car];
            total[num_car] += gap;
            
            // 3) Init time_in
            time_in[num_car] = -1;
        }
    }
    for (int i = 0; i < 10000; i++) {
        if (time_in[i] != -1)
            total[i] += (1439 - time_in[i]);
    }
    
    	// 1-2. Calculate fee
    for (int i = 0, remain; i < total.size(); i++) {
        if (0 < total[i] && total[i] <= fees[0])
            answer.push_back(fees[1]);
        else if (fees[0] < total[i]) {
            remain = (total[i] - fees[0]) % fees[2];
            if (remain == 0)
                answer.push_back(fees[1] + (total[i] - fees[0]) / fees[2] * fees[3]);
            else
                answer.push_back(fees[1] + ((total[i] - fees[0]) / fees[2] + 1) * fees[3]);
        }
    }
    
    // 2. Return Answer
    return answer;
}