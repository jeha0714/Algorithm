#include <stdio.h>
#include <math.h>

int main() {
    
    int T;
    scanf("%d ", &T);
    
    for (int i = 0 ; i < T ; i++) {
        
        int x1,y1,r1;
        int x2,y2,r2;
        double length_Of_Location, sum_R; //length_Of_Location는 중심의 거리 sum_R은 반지름 합.
        
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        length_Of_Location = pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
        sum_R = r1 + r2;
        
        
        //중심이 같은 경우
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n");
            continue;
        }
        
        
        //중심은 다르지만 한 원이 다른 원에 포함되는 경우
        if (length_Of_Location + r2 <= r1 || length_Of_Location + r1 <= r2) {
            
            if (length_Of_Location + r1 == r2 || length_Of_Location + r2 == r1) { //내접원.
                printf("1\n");
                continue;
            }
            else {
                printf("0\n");
                continue;
            }
        }
        
        
        //중심도 다르고 한 원이 다른 원에 포함되지 않는 경우.
        if (length_Of_Location > sum_R) {
            printf("0\n");
        }
        else if (length_Of_Location == sum_R) {
            printf("1\n");
        }
        else {
            printf("2\n");
        }
        
        
        
    }
    
    
    
    
    return 0;
}