#include <vector>
#include <cmath>
#include <algorithm>
#include "binomial_tree.hpp"

double binomial_tree_call(double S, double K, double T, double r, double sigma, int steps, bool is_american) {
    double dt = T / steps;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double p = (std::exp(r * dt) - d) / (u - d);
    double discount = std::exp(-r * dt);

    std::vector<double> prices(steps + 1);
    std::vector<double> values(steps + 1);

    for (int i = 0; i <= steps; ++i) {
        prices[i] = S * std::pow(u, steps - i) * std::pow(d, i);
        values[i] = std::max(prices[i] - K, 0.0);
    }

    for (int step = steps - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            prices[i] = prices[i] / u;
            values[i] = discount * (p * values[i] + (1 - p) * values[i + 1]);
            if (is_american) {
                values[i] = std::max(values[i], prices[i] - K);
            }
        }
    }

    return values[0];
}

double binomial_tree_put(double S, double K, double T, double r, double sigma, int steps, bool is_american) {
    double dt = T / steps;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double p = (std::exp(r * dt) - d) / (u - d);
    double discount = std::exp(-r * dt);

    std::vector<double> prices(steps + 1);
    std::vector<double> values(steps + 1);

    for (int i = 0; i <= steps; ++i) {
        prices[i] = S * std::pow(u, steps - i) * std::pow(d, i);
        values[i] = std::max(K - prices[i], 0.0);
    }

    for (int step = steps - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            prices[i] = prices[i] / u;
            values[i] = discount * (p * values[i] + (1 - p) * values[i + 1]);
            if (is_american) {
                values[i] = std::max(values[i], K - prices[i]);
            }
        }
    }

    return values[0];
}
