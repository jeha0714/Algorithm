#include <string>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

void cal_pipe(pair<pair<vector<int>, bitset<100> >, pair<int, int> > & info, int n, vector<vector<int>> & edges) {
    int cur_open_pipe = info.second.first;
    int target;

    // 1. 현재 감염된 배양체를 순회
    for (int i = 0; i < info.first.first.size(); i++) {
        target = info.first.first[i];

        for (int j = 0; j < edges.size(); j++) {
            // 2. 감염된 경우 연결된 파이프라인을 파악
            // 3. 현재 열린 파이프라인과 동일한 경우 감염
            if (edges[j][0] - 1 == target && edges[j][2] == cur_open_pipe && info.first.second[edges[j][1] - 1] == 0) {
                info.first.first.push_back(edges[j][1]- 1);
                info.first.second[edges[j][1]- 1] = 1;
            }
            if (edges[j][1] - 1 == target && edges[j][2] == cur_open_pipe && info.first.second[edges[j][0] - 1] == 0) {
                info.first.first.push_back(edges[j][0] - 1);
                info.first.second[edges[j][0]- 1] = 1;
            }
        }
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    // 첫번째 pair의 first는 감염된 배양체 순서, second는 배양체 감염 유무 O(1)
    // 두번째 pair의 first는 열린 파이프의 종류, second는 현재까지 파이프 사용 횟수
    queue<pair<pair<vector<int>, bitset<100> >, pair<int, int> > >    q;
    pair<pair<vector<int>, bitset<100> >, pair<int, int> >    tmp;

    // 0. 초기값 삽입
    tmp.first.first.push_back(infection - 1);
    tmp.first.second[infection - 1] = 1;
    tmp.second.second = 0;
    for (int i = 1; i <= 3; i++) {
        tmp.second.first = i;
        q.push(tmp);
    }

    // 1. queue 순회
    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        // a. 이미 파이프를 k번 사용한 경우나 이미 모두 감염시킨 경우
        if (tmp.second.second == k || tmp.first.first.size() == n) {
            if (answer < tmp.first.first.size())
                answer = tmp.first.first.size();
        }
        // b. 더 감염 가능한 경우
        else {

            // 1) 현재 열린 파이프로 추가 감염 계산
            cal_pipe(tmp, n, edges);
            tmp.second.second += 1;

            // 2) 다음에 열 파이프라인 설정 후 queue에 넣기
            for (int i = 1; i <= 3; i++) {
                tmp.second.first = i;
                q.push(tmp);
            }
        }
    }

    return answer;
}
