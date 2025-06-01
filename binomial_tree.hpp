#ifndef BINOMIAL_TREE_HPP
#define BINOMIAL_TREE_HPP

double binomial_tree_call(double S, double K, double T, double r, double sigma, int steps, bool is_american);
double binomial_tree_put(double S, double K, double T, double r, double sigma, int steps, bool is_american);

#endif
