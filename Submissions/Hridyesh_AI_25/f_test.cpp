#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the mean of a dataset
double calculate_mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (const auto& value : data) {
        sum += value;
    }
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

// Function to perform F-Test
double f_test(const std::vector<double>& sample1, const std::vector<double>& sample2) {
    double mean1 = calculate_mean(sample1);
    double mean2 = calculate_mean(sample2);

    double variance1 = calculate_variance(sample1, mean1);
    double variance2 = calculate_variance(sample2, mean2);

    // F statistic is the ratio of larger variance to smaller variance
    return (variance1 > variance2) ? (variance1 / variance2) : (variance2 / variance1);
}

int main() {
    // Example datasets
    std::vector<double> sample1 = {12.1, 13.5, 14.2, 15.3, 16.0};
    std::vector<double> sample2 = {10.2, 11.3, 12.1, 10.8, 11.5};

    // Perform F-Test
    double f_statistic = f_test(sample1, sample2);

    // Degrees of freedom
    size_t df1 = sample1.size() - 1;
    size_t df2 = sample2.size() - 1;

    std::cout << "F Statistic: " << f_statistic << "\n";
    std::cout << "Degrees of Freedom: df1 = " << df1 << ", df2 = " << df2 << "\n";
    std::cout << "Compare this F statistic with critical values from an F-table.\n";

    return 0;
}
