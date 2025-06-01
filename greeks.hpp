#ifndef GREEKS_HPP
#define GREEKS_HPP

double bs_delta_call(double S, double K, double T, double r, double sigma);
double bs_delta_put(double S, double K, double T, double r, double sigma);
double bs_gamma(double S, double K, double T, double r, double sigma);
double bs_vega(double S, double K, double T, double r, double sigma);
double bs_theta_call(double S, double K, double T, double r, double sigma);
double bs_rho_call(double S, double K, double T, double r, double sigma);


#endif
