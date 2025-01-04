#include <iostream>
#include <cmath>

// Function to calculate binomial PMF
double binomial_pmf(int x, int n, double p) {
    double combination = 1;
    for (int i = 0; i < x; ++i) {
        combination *= (n - i) / (i + 1.0);
    }
    return combination * std::pow(p, x) * std::pow(1 - p, n - x);
}

int main() {
    int n = 10;    // Number of trials
    double p = 0.5; // Probability of success

    std::cout << "Binomial Distribution (n=" << n << ", p=" << p << "):\n";
    for (int x = 0; x <= n; ++x) {
        std::cout << "P(X=" << x << ") = " << binomial_pmf(x, n, p) << "\n";
    }

    return 0;
}
