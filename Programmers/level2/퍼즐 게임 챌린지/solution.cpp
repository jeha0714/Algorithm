#include <string>
#include <vector>

using namespace std;

bool is_possible(int level, const vector<int> & diffs, const vector<int> & times, long long limit) {
    long long    total = 0;
    long long    cur;

    for (int i_puzzle = 0; i_puzzle < diffs.size(); i_puzzle++) {
        if (diffs[i_puzzle] <= level) {
            total += times[i_puzzle];
        }
        else {
            cur = (diffs[i_puzzle] - level) * static_cast<long long>((times[i_puzzle - 1] + times[i_puzzle]));
            total += (cur + times[i_puzzle]);
        }

        if (total > limit)
            return (false);
    }

    return (true);
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int    s, e, m;

    s = diffs[0];
    e = 100000;
    while (s <= e) {
        m = (s + e) / 2;

        if (is_possible(m, diffs, times, limit))
            e = m - 1;
        else
            s = m + 1;
    }
    answer = s;

    return answer;
}
