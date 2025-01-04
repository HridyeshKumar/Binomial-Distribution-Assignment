#include <iostream>
#include <cmath>

// Function to calculate Normal PDF
double normal_pdf(double x, double mu, double sigma) {
    return (1.0 / (sigma * std::sqrt(2 * M_PI))) * std::exp(-0.5 * std::pow((x - mu) / sigma, 2));
}

int main() {
    double mu = 0;   // Mean
    double sigma = 1; // Standard deviation

    std::cout << "Normal Distribution (mu=" << mu << ", sigma=" << sigma << "):\n";
    for (double x = mu - 4 * sigma; x <= mu + 4 * sigma; x += 0.5) {
        std::cout << "f(" << x << ") = " << normal_pdf(x, mu, sigma) << "\n";
    }
    return 0;
}
