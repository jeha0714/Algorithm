#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct loc{
    int	r;
    int	c;
} loc;

int	free_n_ret(int ret, int *is_visit[], int len) {
    for (int r = 0; r < len; r++)
        free(is_visit[r]);
    return (ret);
}

// maps_len은 배열 maps의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(char* maps[], size_t maps_len) {
    int answer = 0;
    loc	cur;
    loc	st[10001];
    int	i, max_i;
    int	*is_visit[maps_len];
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    
    // 0. Init
    	// a. find S
    for (int r = 0, max_c; r < maps_len; r++) {
        max_c = strlen(maps[r]);
        is_visit[r] = (int *)malloc(sizeof(int) * max_c);
        for (int c = 0; c < max_c; c++) {
            is_visit[r][c] = 0;
            if (maps[r][c] == 'S') {
                cur.r = r;
                cur.c = c;
            }
        }
    }
    
    // 1. Calculate
    	// a. find lever
    max_i = 0;
    st[0].r = cur.r;
    st[0].c = cur.c;
    is_visit[cur.r][cur.c] = 0;
    for (i = 0; i <= max_i; i++) {
        // 1). st의 가장 꼭대기를 받는다.
        cur.r = st[i].r;
        cur.c = st[i].c;
        if (maps[cur.r][cur.c] == 'L') break;
        // 2). cur에서 가보지 않은 곳을 st에 저장한다. (그만큼 i를 증가시킨다)
        for (int j = 0; j < 4; j++) {
            if ((0 <= cur.r + dr[j] && cur.r + dr[j] < maps_len)
               && (0 <= cur.c + dc[j] && cur.c + dc[j] < strlen(maps[cur.r + dr[j]]))
               && maps[cur.r + dr[j]][cur.c + dc[j]] != 'X' 
               && is_visit[cur.r + dr[j]][cur.c + dc[j]] == 0) {
                is_visit[cur.r + dr[j]][cur.c + dc[j]] = is_visit[cur.r][cur.c] + 1;
                max_i++;
                st[max_i].r = cur.r + dr[j];
                st[max_i].c = cur.c + dc[j];
            }
        }
    }
    if (i > max_i) return (free_n_ret(-1, is_visit, maps_len));
    	// b. find exit
    max_i = 0;
    st[0].r = cur.r;
    st[0].c = cur.c;
    maps[cur.r][cur.c] = 'X';
    for (i = 0; i <= max_i; i++) {
        // 1). st의 가장 꼭대기를 받는다.
        cur.r = st[i].r;
        cur.c = st[i].c;
        if (maps[cur.r][cur.c] == 'E') break;
        // 2). cur에서 가보지 않은 곳을 st에 저장한다. (그만큼 i를 증가시킨다)
        for (int j = 0; j < 4; j++) {
            if ((0 <= cur.r + dr[j] && cur.r + dr[j] < maps_len)
               && (0 <= cur.c + dc[j] && cur.c + dc[j] < strlen(maps[cur.r + dr[j]]))
               && maps[cur.r + dr[j]][cur.c + dc[j]] != 'X') {
                is_visit[cur.r + dr[j]][cur.c + dc[j]] = is_visit[cur.r][cur.c] + 1;
                max_i++;
                st[max_i].r = cur.r + dr[j];
                st[max_i].c = cur.c + dc[j];
                if (maps[cur.r + dr[j]][cur.c + dc[j]] == 'E') {
                    cur.r = cur.r + dr[j];
                    cur.c = cur.c + dc[j];
                    i = max_i - 1;
                    break ;
                }
                maps[cur.r + dr[j]][cur.c + dc[j]] = 'X';
            }
        }
    }
    if (i > max_i) return (free_n_ret(-1, is_visit, maps_len));
    
    // 2. Return Answer
    answer = is_visit[cur.r][cur.c];
    return (free_n_ret(answer, is_visit, maps_len));
}