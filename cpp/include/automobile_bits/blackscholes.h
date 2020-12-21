//#pragma once
#ifndef BS_H
#define BS_H

namespace bs {

double std_normal_density(double x);

double cumulative_normal_distribution(double x);

double forward(double spot, double rate_base, double rate_term, double maturity);

double blackscholes(double spot, double rate_base, double rate_term, double maturity, double strike);

}

#endif