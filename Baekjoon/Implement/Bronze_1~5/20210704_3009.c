#include <stdio.h>
#include <math.h>

int main() {
    
    int x1,x2,x3;
    int y1,y2,y3;
    double length1,length2,length3,max_Length;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    
    length1 = sqrt((double)(((x1 - x2)*(x1-x2) + (y1-y2)*(y1-y2))));
    length2 = sqrt((double)(((x2 - x3)*(x2-x3) + (y2-y3)*(y2-y3))));
    length3 = sqrt((double)(((x3 - x1)*(x3-x1) + (y3-y1)*(y3-y1))));
    
    
    max_Length = (length1 >= length2 && length1 >= length3) ? length1 : ((length2 >= length1 && length2 >= length3) ? length2 : length3);
    
    if(max_Length == length1) {
        printf("%d %d",x1 + x2 - x3 , y1 + y2 -y3);
    }
    else if (max_Length == length2) {
        printf("%d %d",x2 + x3 - x1 , y2 + y3 -y1);
    }
    else { // max_Length == length3
        printf("%d %d",x3 + x1 - x2 , y3 + y1 -y2);
    }
    
    return 0;
}