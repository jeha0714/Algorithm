#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

// 오름차순
int	compare(const void * a, const void * b) {
    
    return (*((int *)a) - *((int *)b));
}

/*
1. 정렬을 먼저한다.
*/

int solution(vector<int> citations) {
    int answer = 0;
    int * v;
    
    // 0. Init
    v = (int *)(malloc(sizeof(int) * citations.size()));
    for (int i = 0; i < citations.size(); i++) v[i] = citations[i];
    	// a. sorting
    qsort((void *)v, citations.size(), sizeof(int), compare);
    
    // 1. Calculate
    for (int h = 0, i = 0; h <= 1000;) {
        if (v[i] >= h) {
            if (citations.size() - i >= h)
                answer = h;
            h++;
        }
        else { // v[i] < h
            if (i < citations.size() - 1) i++;
            else break;
        }
    }
    
    // 2. Return Answer
    free(v);
    return answer;
}