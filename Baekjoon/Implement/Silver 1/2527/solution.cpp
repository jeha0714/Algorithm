#include <iostream>

bool    is_space_case(int r1[4], int r2[4]) {
    // 1. r1좌측하단 점이 r2 x 범위 사이에 존재할 때
    if (r2[0] <= r1[0] && r1[0] < r2[2]) {
        // a. r1 좌측 하단 y가 r2 밑변보다 아래이면서 r1 우측상단 y가 r2 밑변보다 크면 
        if (r1[1] < r2[1] && r2[1] < r1[3])
            return true;
        // b. r1 좌측 하단 점이 r2 y 사이에 있다면
        else if (r2[1] <= r1[1] && r1[1] < r2[3])
            return true;
    }
    return (false);
}

bool    is_line_case(std::pair<int, int> r1[4], int r2[4]) {
    // 1. up side
    if ((r2[0] <= r1[0].first && r1[0].first < r2[2] && r2[3] == r1[0].second)
        || (r2[0] < r1[3].first && r1[3].first <= r2[2] && r2[3] == r1[3].second))
        return (true);

    // 2. right side
    if ((r2[1] <= r1[0].second && r1[0].second < r2[3] && r2[2] == r1[0].first)
        || (r2[1] < r1[1].second && r1[1].second <= r2[3] && r2[2] == r1[1].first))
        return (true);

    // 3. down side
    if ((r2[0] <= r1[1].first && r1[1].first < r2[2] && r2[1] == r1[1].second)
        || (r2[0] < r1[2].first && r1[2].first <= r2[2] && r2[1] == r1[2].second))
        return (true);

    // 4. left side
    if ((r2[1] < r1[2].second && r1[2].second <= r2[3] && r2[0] == r1[2].first)
        || (r2[1] <= r1[3].second && r1[3].second < r2[3] && r2[0] == r1[3].first))
        return (true);

    return (false);
}

bool    is_dot_case(std::pair<int, int> r1[4], std::pair<int, int> r2[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (r1[i] == r2[j])
                return (true);
        }
    }
    return (false);
}

int main(void) {
    int r1[4];
    int r2[4];
    std::pair<int, int> vertices_r1[4];
    std::pair<int, int> vertices_r2[4];

    for (int test_case = 0; test_case < 4; test_case++) {
        // 0. Init
        for (int i = 0; i < 4; i++)
            std::cin >> r1[i];
        for (int j = 0; j < 4; j++)
            std::cin >> r2[j];
        
        // 1. Find vertices
        vertices_r1[0] = std::make_pair(r1[0], r1[1]);
        vertices_r1[1] = std::make_pair(r1[0], r1[3]);
        vertices_r1[2] = std::make_pair(r1[2], r1[3]);
        vertices_r1[3] = std::make_pair(r1[2], r1[1]);
        vertices_r2[0] = std::make_pair(r2[0], r2[1]);
        vertices_r2[1] = std::make_pair(r2[0], r2[3]);
        vertices_r2[2] = std::make_pair(r2[2], r2[3]);
        vertices_r2[3] = std::make_pair(r2[2], r2[1]);

        // 2. Calculate and print
            // a. space case
        if (is_space_case(r1, r2) || is_space_case(r2, r1))
            std::cout << "a\n";
            // b. line case
        else if (is_line_case(vertices_r1, r2) || is_line_case(vertices_r2, r1))
            std::cout << "b\n";
            // c. dot case
        else if (is_dot_case(vertices_r1, vertices_r2))
            std::cout << "c\n";
            // d. nothing
        else
            std::cout << "d\n";
    }

    return (0);
}