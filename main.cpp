#include <iostream>
#include <cstdlib>  // for atof
#include <string>
#include "black_scholes.hpp"
#include "greeks.hpp"

int main(int argc, char* argv[]) {
    if (argc < 7) {
        std::cerr << "Usage: ./pricing_engine S K r T sigma call/put\n";
        return 1;
    }

    double S = atof(argv[1]);
    double K = atof(argv[2]);
    double r = atof(argv[3]);
    double T = atof(argv[4]);
    double sigma = atof(argv[5]);
    std::string type = argv[6];

    // Input validation
    if (S <= 0.0 || K <= 0.0 || T <= 0.0 || sigma <= 0.0) {
        std::cerr << "Error: S, K, T, and sigma must be positive numbers.\n";
        return 1;
    }

    if (type != "call" && type != "put") {
        std::cerr << "Error: Option type must be 'call' or 'put'.\n";
        return 1;
    }

    // Optional: warn about negative rates
    if (r < 0.0) {
        std::cerr << "Warning: Negative interest rate entered.\n";
    }

    // Price calculation
    double price = (type == "call") ? black_scholes_call(S, K, T, r, sigma)
                                    : black_scholes_put(S, K, T, r, sigma);

    // Clean output
    std::cout << "----------------------------\n";
    std::cout << "Option Type : " << type << "\n";
    std::cout << "Price       : " << price << "\n";
    std::cout << "----------------------------\n";

    return 0;
}
