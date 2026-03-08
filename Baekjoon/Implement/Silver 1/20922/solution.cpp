#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, K;
    vector<int> num_appear(100001, 0);
    vector<int> nums;
    int cur_max; // 현재 위치까지 포함시킨 max size
    int left = 0;
    int max_value = 0;

    // 1. Init
    cin >> N >> K;
    nums.resize(N);

    // 2. Calculate
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        num_appear[nums[i]]++;
        if (num_appear[nums[i]] <= K) {
            cur_max = i - left + 1;
        }
        else {
            for (; left < i && num_appear[nums[i]] > K; left++) {
                num_appear[nums[left]]--;
            }
            cur_max = i - left + 1;
        }

        if (max_value < cur_max)
            max_value = cur_max;
    }

    // 3. Print result
    cout << max_value << "\n";

    return (0);
}