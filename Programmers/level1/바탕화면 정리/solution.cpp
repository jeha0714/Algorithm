#include <string>
#include <vector>

using namespace std;

/* solution
    
    find minimum left up location
    find maximum right down location

*/
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, 0);
    int row, col;
    
    // 0. set answer, row, col
        // answer[0] -> up location -> set minumum
        // answer[1] -> left location -> set minumum
        // answer[0] -> down location -> set maximum
        // answer[0] -> right location -> set maximum
    answer[0] = 2147483647;
    answer[1] = 2147483647;
    answer[2] = -2147483648;
    answer[3] = -2147483648;
        
        // init row, col
    row = wallpaper.size();
    col = wallpaper[0].length();
    
    // 1. explore all location
    for (int curRow = 0; curRow < row; curRow++) {
        for (int curCol = 0; curCol < col;) {
            if (wallpaper[curRow][curCol] == '#') {
                // a. compare up value
                if (answer[0] > curRow)
                    answer[0] = curRow;
                // b. compare left value
                if (answer[1] > curCol)
                    answer[1] = curCol;
                // c. compare down value
                if (answer[2] < curRow + 1)
                    answer[2] = curRow + 1;
                // d. compare right value
                if (answer[3] < curCol + 1)
                    answer[3] = curCol + 1;
                curCol++;
            }
            else if (wallpaper[curRow][curCol] == '.')
                curCol++;
        }
    }
    
    return answer;
}