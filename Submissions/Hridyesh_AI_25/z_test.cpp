#include <iostream>
#include <cmath>
#include <vector>

// Function to calculate the mean of a dataset
double calculate_mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (const auto& value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Function to calculate the Z statistic
double z_test(double mean1, double mean2, double std_dev1, double std_dev2, size_t n1, size_t n2) {
    // Standard error for the difference in means
    double standard_error = std::sqrt((std_dev1 * std_dev1 / n1) + (std_dev2 * std_dev2 / n2));

    // Z statistic
    return (mean1 - mean2) / standard_error;
}

int main() {
    // Example datasets
    std::vector<double> sample1 = {100, 102, 98, 105, 99};
    std::vector<double> sample2 = {95, 97, 96, 94, 96};

    // Population standard deviations (known)
    double std_dev1 = 5.0; // Standard deviation of sample1
    double std_dev2 = 4.0; // Standard deviation of sample2

    // Sample sizes
    size_t n1 = sample1.size();
    size_t n2 = sample2.size();

    // Calculate means
    double mean1 = calculate_mean(sample1);
    double mean2 = calculate_mean(sample2);

    // Perform Z-Test
    double z_statistic = z_test(mean1, mean2, std_dev1, std_dev2, n1, n2);

    std::cout << "Sample 1 Mean: " << mean1 << "\n";
    std::cout << "Sample 2 Mean: " << mean2 << "\n";
    std::cout << "Z Statistic: " << z_statistic << "\n";
    std::cout << "Compare this Z statistic with critical values from a Z-table.\n";

    return 0;
}
