#include <vector>

using namespace std;

vector<int>	ret_answer(const vector<int> & v) {
    vector<int>	ret;
    int			top;
    
    // 1. v[0] 삽입
    ret.push_back(1);
    top = 1;
    
    // 2. v[1] 비교
    if (v[top - 1] < v[1]) {
        while (!ret.empty()) ret.pop_back();
        ret.push_back(2);
        top = 2;
    }
    else if (v[top - 1] == v[1]) ret.push_back(2);
    
    // 3. v[2] 비교
    if (v[top - 1] < v[2]) {
        while (!ret.empty()) ret.pop_back();
        ret.push_back(3);
    }
    else if (v[top - 1] == v[2]) ret.push_back(3);
    
    return (ret);
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>	first = {1, 2, 3, 4, 5};
    vector<int>	second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int>	third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int>	correct = {0, 0, 0};
    
    // 0. Init
    
    // 1. Calculate
    	// a. Check answers
    for (size_t i = 0; i < answers.size(); i++) {
        if (answers[i] == first[i % first.size()]) correct[0]++;
        if (answers[i] == second[i % second.size()]) correct[1]++;
        if (answers[i] == third[i % third.size()]) correct[2]++;
    }
    	// b. Set answer
    answer = ret_answer(correct);
    
    // 2. Return Answer
    return answer;
}