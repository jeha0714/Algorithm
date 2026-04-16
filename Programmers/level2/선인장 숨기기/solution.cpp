#include <set>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer = {0, 0};
    vector<vector<int>> area(m, vector<int>(n, 500001));
    set<int>    s;

    // 0. Init area
    for (int drop = 0; drop < drops.size(); drop++) {
        area[drops[drop][0]][drops[drop][1]] = drop + 1;
    }

    // 1. slice width
    for (int r = 0; r < m; r++) {
        s.clear();
        for (int c = 0; c < w - 1; c++)
            s.insert(area[r][c]);

        for (int c = 0, tmp; c <= n - w; c++) {
            s.insert(area[r][c + w - 1]);
            tmp = area[r][c];
            area[r][c] = *(s.begin());
            s.erase(tmp);
        }
    }

    // 2. slice height
    for (int c = 0; c < n; c++) {
        s.clear();
        for (int r = 0; r < h - 1; r++)
            s.insert(area[r][c]);

        for (int r = 0, tmp; r <= m - h; r++) {
            s.insert(area[r + h - 1][c]);
            tmp = area[r][c];
            area[r][c] = *(s.begin());
            s.erase(tmp);
        }
    }

    // 3. Find Max
    for (int r = 0; r <= m - h; r++) {
        for (int c = 0; c <= n - w; c++) {
            if (area[answer[0]][answer[1]] < area[r][c]) {
                answer[0] = r;
                answer[1] = c;
            }
        }
    }

    return answer;
}
