#include <iostream>
#include <iomanip>
#include <cmath>

double  a, b, c, d, m, t;

double  custom_floor(double d) {
    return (floor(d * 100) / 100.0);
}

double  fn(double v) {
    return (a * v * v * v + b * v * v + c * v + d - t / m);
}

double  bns(double s, double e) {
    double  m = (s + e) / 2;

    // 1. degenerate case
    if (s > e)
        return (e);

    // 2. continue
    if (fn(m) <= 0) {
        return (bns(m + 0.01, e));
    }
    else {
        return (bns(s, m - 0.01));
    }
}

int main(void) {
    double  optimization_v;
    double  tmp;

    while(1) {
        // 0. Init
        if (!(std::cin >> a >> b >> c >> d >> m >> t))
            break ;
        tmp = 1;
    
        // 1. Find optimization v
        while(fn(tmp) < 0)
            tmp *= 10;
        optimization_v = bns(0.01, tmp);
        optimization_v = custom_floor(optimization_v);
        if (fn(optimization_v + 0.01) <= 0)
            optimization_v = optimization_v + 0.01;
        else if (fn(optimization_v ) > 0)
            optimization_v = optimization_v - 0.01;
    
        // 2. Print result
        std::cout << std::fixed << std::setprecision(2) << optimization_v << "\n";
    }

    return (0);
}