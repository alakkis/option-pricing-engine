#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cmath>

inline double norm_pdf(double x) {
    return (1.0 / std::sqrt(2 * M_PI)) * std::exp(-0.5 * x * x);
}

inline double norm_cdf(double x) {
    return 0.5 * erfc(-x / std::sqrt(2));
}

#endif
