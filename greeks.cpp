#include "greeks.hpp"
#include "math_utils.hpp"

double bs_delta_call(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_cdf(d1);
}

double bs_delta_put(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_cdf(d1) - 1.0;
}

double bs_gamma(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

double bs_vega(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return S * std::sqrt(T) * norm_pdf(d1);
}

double bs_theta_call(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    double first = - (S * norm_pdf(d1) * sigma) / (2 * std::sqrt(T));
    double second = - r * K * std::exp(-r * T) * norm_cdf(d2);
    return first + second;
}

double bs_rho_call(double S, double K, double T, double r, double sigma) {
    double d2 = (std::log(S / K) + (r - 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    return K * T * std::exp(-r * T) * norm_cdf(d2);
}
