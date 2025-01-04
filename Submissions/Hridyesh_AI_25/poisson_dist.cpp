#include <iostream>
#include <cmath>

// Function to calculate Poisson PMF
double poisson_pmf(int x, double lambda) {
    return std::pow(lambda, x) * std::exp(-lambda) / std::tgamma(x + 1);
}

int main() {
    double lambda = 4; // Mean (lambda)

    std::cout << "Poisson Distribution (lambda=" << lambda << "):\n";
    for (int x = 0; x <= 15; ++x) {
        std::cout << "P(X=" << x << ") = " << poisson_pmf(x, lambda) << "\n";
    }
    return 0;
}
