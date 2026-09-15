#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int>	us;
    
    // 0. Init
    for (size_t i = 0; i < nums.size(); i++) us.insert(nums[i]);
    
    // 1. Calculate
    if (us.size() >= nums.size() / 2) answer = nums.size() / 2;
    else answer = us.size();
    
    // 2. Return Answer
    return answer;
}