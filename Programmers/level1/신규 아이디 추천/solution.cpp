#include <string>
#include <vector>

using namespace std;

bool	is_valid(char c) {
    string	cmp = "-_.";
    
    if (isalnum(c))
        return (true);
    
    for (int i = 0; i < 3; i++) {
        if (cmp[i] == c)
            return (true);
    }
    
    return (false);
}

string solution(string new_id) {
    string answer = "";
    int	i;
    
    // 1. Calculate
	for (i = 0; i < new_id.length(); i++) {
        // step 2
        if (is_valid(new_id[i])) {
            // step 1
            if ('A' <= new_id[i] && new_id[i] <= 'Z') {
                answer.push_back(new_id[i] + ('a' - 'A'));
            }
            else {
                // step 3
                if (answer.length() > 0
                    && answer[answer.length() - 1] == '.' && new_id[i] == '.')
                    continue;
                else
                    answer.push_back(new_id[i]);
            }
                
        }
    }
        // step 4
    i = 0;
    while (i < answer.length() && answer[i] == '.') i++; 
    answer.erase(0, i);
    i = static_cast<int>(answer.length()) - 1;
    while (i >= 0 && answer[i] == '.') i--; 
    answer.erase(i + 1, answer.length() - i + 1);
    
    	// step 6
    if (answer.length() > 15) {
        i = 15;
        while (i > 0 && answer[i - 1] == '.') i--;
        answer.erase(i, answer.length() - i);
    }
    
    	// step 5
    if (answer.length() == 0)
        answer.push_back('a');
    
    	// step 7
    if (answer.length() <= 2) {
        while (answer.length() < 3)
            answer.push_back(answer[answer.length() - 1]);
    }
    
    // 2. Return answer
    return answer;
}