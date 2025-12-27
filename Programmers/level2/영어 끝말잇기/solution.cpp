#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> word_hash;
    
    // 1. start first person
    for (int t = 1; ; t++) {
        
        // 2. rotate n people
        for (int cur = 1; cur <= n; cur++) {
            int i = (t - 1) * n + (cur - 1);
            
            // a. check range
            if (i >= words.size())
                return (answer);
            
            // b. check correct starting alphabet
                // i > 0 in words[i]
            if (i > 0) {
                char prevEnd = words[i - 1][words[i - 1].length() - 1];
                char curStart = words[i][0];
                
                if (prevEnd != curStart) {
                    answer[0] = cur;
                    answer[1] = t;
                    
                    return (answer);
                }
            }
            
            // c. check existing words
            if (word_hash.find(words[i]) == word_hash.end()) {
                word_hash.insert(words[i]);
            }
            else {
                answer[0] = cur;
                answer[1] = t;

                return (answer);
            }
            
        }
        
    }

    return (answer);
}