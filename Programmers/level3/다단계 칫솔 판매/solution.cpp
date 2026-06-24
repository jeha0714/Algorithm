#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
< 풀이방법 >
원기옥으로 한 번에 주면 안됨 ex) 5월을 계속 이자 받는데 한 번에 부모에게 주면 안됨
answer에 그 때 그때 바로 주기

< 필요한 변수 >
unordered_map<name, index> 필요

*/

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, int>	um;
    string	cur;
    int		i_cur;
    int		money_cur, money_parent;
    
    // 0. Init
    	// a. unordered_map에 key=name, value=index로 삽입
    for (int i = 0; i < enroll.size(); i++) {
        um[enroll[i]] = i;
    }
    
    // 1. Calculate
    for (int i = 0; i < seller.size(); i++) {
        // a. Set info
        cur = seller[i];
        i_cur = um[cur];
        money_cur = amount[i] * 100;
        
        // b. 90% 자신 10% 부모 반복
        while (money_cur != 0) {
            if (money_cur < 10) {
                answer[i_cur] += money_cur;
                money_cur = 0;
            }
            else {
                money_parent = money_cur / 10;
                answer[i_cur] += money_cur - money_parent;
                
                cur = referral[i_cur];
                if (cur == "-") {
                    break ;
                }
                else {
                    i_cur = um[cur];
                    money_cur = money_parent;
                }
            }
        }
    }
    
    // 2. Return answer
    return answer;
}