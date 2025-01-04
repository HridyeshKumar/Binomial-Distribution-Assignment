#include <iostream>
#include <vector>
#include <cmath>

// Function to perform Chi-Square Test
double chi_square_test(const std::vector<int>& observed, const std::vector<int>& expected) {
    if (observed.size() != expected.size()) {
        std::cerr << "Error: Observed and expected frequencies must have the same size.\n";
        return -1;
    }

    double chi_square = 0.0;

    for (size_t i = 0; i < observed.size(); ++i) {
        double diff = observed[i] - expected[i];
        chi_square += (diff * diff) / expected[i];
    }

    return chi_square;
}

int main() {
    // Observed and expected frequencies
    std::vector<int> observed = {50, 30, 20};  // Example observed values
    std::vector<int> expected = {40, 40, 20};  // Example expected values

    // Perform Chi-Square Test
    double chi_square_stat = chi_square_test(observed, expected);

    // Degrees of freedom: (number of categories - 1)
    int degrees_of_freedom = observed.size() - 1;

    if (chi_square_stat >= 0) {
        std::cout << "Chi-Square Statistic: " << chi_square_stat << "\n";
        std::cout << "Degrees of Freedom: " << degrees_of_freedom << "\n";
        std::cout << "You can compare this statistic to critical values from a Chi-Square table.\n";
    }

    return 0;
}
