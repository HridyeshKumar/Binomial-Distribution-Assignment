#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

// Function to calculate the mean of a dataset
double calculate_mean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Function to calculate the variance of a dataset
double calculate_variance(const std::vector<double>& data, double mean) {
    double variance = 0.0;
    for (const auto& value : data) {
        variance += std::pow(value - mean, 2);
    }
    return variance / (data.size() - 1); // Sample variance
}

// Function to calculate the T statistic
double t_test(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double mean1 = calculate_mean(sample1);
    double mean2 = calculate_mean(sample2);

    double variance1 = calculate_variance(sample1, mean1);
    double variance2 = calculate_variance(sample2, mean2);

    size_t n1 = sample1.size();
    size_t n2 = sample2.size();

    // Pooled standard error
    double pooled_std_error = std::sqrt((variance1 / n1) + (variance2 / n2));

    // T statistic
    return (mean1 - mean2) / pooled_std_error;
}

int main() {
    // Example datasets
    std::vector<double> sample1 = {2.3, 3.1, 2.8, 3.5, 2.9};
    std::vector<double> sample2 = {3.0, 3.4, 3.1, 3.8, 3.6};

    // Perform T-Test
    double t_statistic = t_test(sample1, sample2);

    // Degrees of freedom (approximate for unequal variances)
    size_t df = sample1.size() + sample2.size() - 2;

    std::cout << "T Statistic: " << t_statistic << "\n";
    std::cout << "Degrees of Freedom: " << df << "\n";
    std::cout << "Compare this T statistic with a critical value from a T-table.\n";

    return 0;
}
