#include <string>
#include <vector>

using namespace std;

/*
1. stage n-1을 2번째 칸에 옮기기
2. n을 3번째 칸에 옮기기
3. stage n-1을 2에서 3으로 옮기기

stage 2
[1,2] [1,3] [2,3]

stage 3
[1,3] [1,2] [3,2] [1,3] [2,1] [2,3] [1,3]
x [1,2] [1,3] [2,3] [1,2] [3,2] [3,1] [2,3] [1,2] [1,3] [2,3]

stage 4
[1,2] [1,3] [2,3] [1,2] [3,1] [3,2] [1,2] [1,3]
*/

/*
기존에 2가 3으로 바뀌고 3이 2로 바뀜
*/
void	mv_one_to_two(int n, vector<vector<vector<int>>> & record) {
    vector<int>	tmp;
    
    for (int i = 0; i < record[n].size(); i++) {
        tmp = record[n][i];
        
        for (int j = 0; j < 2; j++) {
            if (tmp[j] == 2)
                tmp[j] = 3;
            else if (tmp[j] == 3)
                tmp[j] = 2;
        }
        record[n + 1].push_back(tmp);
    }
}

/*
기존에 1가 2으로 바뀌고 2이 1로 바뀜
*/
void	mv_two_to_three(int n, vector<vector<vector<int>>> & record) {
    vector<int>	tmp;
    
    for (int i = 0; i < record[n].size(); i++) {
        tmp = record[n][i];
        
        for (int j = 0; j < 2; j++) {
            if (tmp[j] == 1)
                tmp[j] = 2;
            else if (tmp[j] == 2)
                tmp[j] = 1;
        }
        record[n + 1].push_back(tmp);
    }   
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    vector<vector<vector<int>>>	record;
    
    // 0. Init
    	// a. n = 1 일때 정의
    record.resize(n + 1);
    record[1].resize(1);
    record[1][0].resize(2);
    record[1][0][0] = 1;
    record[1][0][1] = 3;
    
    // 1. 2부터 순회
    for (int size = 2; size <= n; size++) {
        // a. stage n-1을 2번째 칸에 옮기기
        mv_one_to_two(size - 1, record);

        // b. n을 3번째 칸에 옮기기
        vector<int>	tmp = {1, 3};
        record[size].push_back(tmp);

        // c. stage n-1을 2에서 3으로 옮기기
        mv_two_to_three(size - 1, record);
    }
    
    // 2. Return answer
    answer = record[n];
    return answer;
}