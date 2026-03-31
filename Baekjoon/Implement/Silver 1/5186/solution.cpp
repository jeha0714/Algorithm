#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int K;
    int n, c, l;
    int num_area, num_seat;
    char status;
    std::vector<std::vector<int> >  area;
    std::vector<std::pair<int, int> >  car;
    int remain;

    std::cin >> K;
    for (int test_num = 1; test_num <= K; test_num++) {
        // 0. Init
        std::cin >> n >> c >> l;
        area.resize(l + 1);
        for (int i = 1; i <= l; i++) {
            area[i].resize(2);
            area[i][0] = 0;
            area[i][1] = 0;
        }
        for (int i = 0; i < n; i++) {
            std::cin >> num_area >> status;
            if (status == 'S')
                area[num_area][0]++;
            else
                area[num_area][1]++;
        }
        car.clear();
        for (int i = 0; i < c; i++) {
            std::cin >> num_area >> num_seat;
            car.push_back(std::make_pair(num_seat, num_area));
        }
        std::sort(car.begin(), car.end(), std::greater<std::pair<int, int> >());

        // 1. Calculate
        for (int i = 0; i < c; i++) {
            num_seat = car[i].first;
            num_area = car[i].second;

            if (area[num_area][0] == 0) {
                continue ;
            }
            else { // (area[num_area][0] != 0)
                if (num_seat - 1 <= area[num_area][1]) {
                    area[num_area][0]--;
                    area[num_area][1] -= (num_seat - 1);
                }
                else { // (num_seat - 1 > area[num_area][1])
                    if (num_seat - area[num_area][1] <= area[num_area][0]) {
                        area[num_area][0] -= (num_seat - area[num_area][1]);
                        area[num_area][1] = 0;
                    }
                    else {
                        area[num_area][0] = 0;
                        area[num_area][1] = 0;
                    }
                }
            }
        }
    
        // 2. Print number of remain ppl
        remain = 0;
        for (int i = 1; i <= l; i++) {
            remain += area[i][0];
            remain += area[i][1];
        }
        std::cout << "Data Set "<< test_num << ":\n";
        std::cout << remain << "\n";
    }

    return (0);
}