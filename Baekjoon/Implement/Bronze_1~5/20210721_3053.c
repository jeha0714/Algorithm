#include <stdio.h>

const long double circle_Pie = 3.14159265358979;

int main() {
    
    int R;
    scanf("%d", &R);
    
    printf("%.6Lf\n", (long double)(R * R * circle_Pie));
    printf("%.6Lf\n", (long double)(R * R * 2));
    
    return 0;
}