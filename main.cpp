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

    double price = (type == "call") ? black_scholes_call(S, K, T, r, sigma)
                                     : black_scholes_put(S, K, T, r, sigma);

    std::cout << "Option Price: " << price << std::endl;
    return 0;
}
