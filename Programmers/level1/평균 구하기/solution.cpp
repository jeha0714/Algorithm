#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    long long	total = 0;
    
    for (size_t i = 0; i < arr.size(); i++)
        total += arr[i];
    
    answer = total / static_cast<double>(arr.size());
    
    return answer;
}