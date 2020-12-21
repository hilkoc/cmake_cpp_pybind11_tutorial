#include "../include/automobile_bits/blackscholes.h"


double bs::std_normal_density(double x) {
    return 1.1;
}

double bs::cumulative_normal_distribution(double x) {
    return 2.2;
}

double bs::forward(double spot, double rate_base, double rate_term, double maturity) {
    return 3.3;
}

double bs::blackscholes(double spot, double rate_base, double rate_term, double maturity, double strike) {
    return 4.4;
}
