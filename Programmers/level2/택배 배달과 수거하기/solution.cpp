#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    int	i_delivery, i_pickup;
    
    // 0. Init
    i_delivery = n;
    while (i_delivery > 0 && deliveries[i_delivery - 1] == 0)
        i_delivery--;
    i_pickup = n;
    while (i_pickup > 0 && pickups[i_pickup - 1] == 0)
        i_pickup--;
    answer = 0;
    
    // 1. Calculate
    while (i_delivery > 0 || i_pickup > 0) {
        if (i_delivery >= i_pickup) {
            answer += (i_delivery * 2);
        }
        else {//if (i_delivery < i_pickup) {
            answer += (i_pickup * 2);
        }
    	
    	// a. delivery 
        for (int cur = cap; cur > 0 && i_delivery > 0;) {
            if (deliveries[i_delivery - 1] > 0) {
                if (deliveries[i_delivery - 1] <= cur) {
                    cur -= deliveries[i_delivery - 1];
                    deliveries[i_delivery - 1] = 0;
                    i_delivery--;
                }
                else {
                    deliveries[i_delivery - 1] -= cur;
                    cur = 0;
                }
            }
            else
                i_delivery--;
        }
        while (i_delivery > 0 && deliveries[i_delivery - 1] == 0)
            i_delivery--;
        
        // b. pickup
        for (int cur = cap; cur > 0 && i_pickup > 0;) {
            if (pickups[i_pickup - 1] > 0) {
                if (pickups[i_pickup - 1] <= cur) {
                    cur -= pickups[i_pickup - 1];
                    pickups[i_pickup - 1] = 0;
                    i_pickup--;
                }
                else {
                    pickups[i_pickup - 1] -= cur;
                    cur = 0;
                }
            }
            else
                i_pickup--;
        }
        while (i_pickup > 0 && pickups[i_pickup - 1] == 0)
            i_pickup--;
    }
    
    // 2. Return Answer
    return answer;
}