#include <cstdio>
#include <cmath>

double  a, b, c, d, m, t;

double  fn(double v) {
    return (a * v * v * v + b * v * v + c * v + d - t / m);
}

int main(void) {
    while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &m, &t) == 6) {
        // 1. Find upper bound
        double hi = 1;
        while (fn(hi) < 0)
            hi *= 2;

        // 2. Binary search (200 iterations, no recursion)
        double lo = 0;
        for (int i = 0; i < 200; i++) {
            double mid = (lo + hi) / 2;
            if (fn(mid) <= 0)
                lo = mid;
            else
                hi = mid;
        }

        // 3. Print result (truncate to 2 decimal places)
        printf("%.2f\n", floor(lo * 100) / 100.0);
    }

    return (0);
}