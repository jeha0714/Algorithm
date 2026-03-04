#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int T;
    int x1, y1, r1;
    int x2, y2, r2;
    double  dist_point, dist_r;

    cin >> T;
    for (int test = 0; test < T; test++) {
        // 0. Init input
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
        // 1. Print result
        dist_point = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        dist_r = r1 + r2;
            // a. Infinite Case
            if (x1 == x2 && y1 == y2 && r1 == r2)
                cout << "-1\n";
            // b. 한 원안에 다른 원의 중심이 있는 경우
            else if (dist_point < r1 || dist_point < r2) {
                if (r1 > r2) {
                    // 1. Two point of contact
                    if (dist_point + r2 > r1)
                        cout << "2\n";
                    // 2. One point of contact
                    else if (dist_point + r2 == r1)
                        cout << "1\n";
                    // 3. Zero point of contact
                    else 
                        cout << "0\n";
                }
                else {
                    // 1. Two point of contact
                    if (dist_point + r1 > r2)
                        cout << "2\n";
                    // 2. One point of contact
                    else if (dist_point + r1 == r2)
                        cout << "1\n";
                    // 3. Zero point of contact
                    else 
                        cout << "0\n";
                }
            }
            // c. 서로의 원이 중심이 포함되지 않는 경우
            else {
                // 1. Two point of contact
                if (dist_point < dist_r)
                    cout << "2\n";
                // 2. One point of contact
                else if (dist_point == dist_r)
                    cout << "1\n";
                // 3. Zero point of contact
                else
                    cout << "0\n";
            }
    }    
    return (0);
}
