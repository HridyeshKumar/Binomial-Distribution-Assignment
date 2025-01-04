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

// Function to calculate the total sum of squares (SST)
double calculate_total_sum_of_squares(const std::vector<std::vector<double>>& groups, double grand_mean) {
    double SST = 0.0;
    for (const auto& group : groups) {
        for (const auto& value : group) {
            SST += std::pow(value - grand_mean, 2);
        }
    }
    return SST;
}

// Function to calculate the between-group sum of squares (SSB)
double calculate_between_group_sum_of_squares(const std::vector<std::vector<double>>& groups, double grand_mean) {
    double SSB = 0.0;
    for (const auto& group : groups) {
        double group_mean = calculate_mean(group);
        SSB += group.size() * std::pow(group_mean - grand_mean, 2);
    }
    return SSB;
}

// Function to calculate the within-group sum of squares (SSW)
double calculate_within_group_sum_of_squares(const std::vector<std::vector<double>>& groups) {
    double SSW = 0.0;
    for (const auto& group : groups) {
        double group_mean = calculate_mean(group);
        for (const auto& value : group) {
            SSW += std::pow(value - group_mean, 2);
        }
    }
    return SSW;
}

int main() {
    // Example groups of data
    std::vector<std::vector<double>> groups = {
        {12.1, 13.5, 14.2, 15.3, 16.0}, // Group 1
        {10.2, 11.3, 12.1, 10.8, 11.5}, // Group 2
        {8.5, 9.0, 9.3, 8.7, 9.1}       // Group 3
    };

    // Calculate grand mean
    double total_sum = 0.0;
    size_t total_count = 0;
    for (const auto& group : groups) {
        total_sum += std::accumulate(group.begin(), group.end(), 0.0);
        total_count += group.size();
    }
    double grand_mean = total_sum / total_count;

    // Calculate sums of squares
    double SST = calculate_total_sum_of_squares(groups, grand_mean);
    double SSB = calculate_between_group_sum_of_squares(groups, grand_mean);
    double SSW = calculate_within_group_sum_of_squares(groups);

    // Degrees of freedom
    size_t df_between = groups.size() - 1; // Number of groups - 1
    size_t df_within = total_count - groups.size(); // Total observations - Number of groups

    // Mean squares
    double MSB = SSB / df_between;
    double MSW = SSW / df_within;

    // F statistic
    double F_statistic = MSB / MSW;

    // Output results
    std::cout << "Grand Mean: " << grand_mean << "\n";
    std::cout << "Total Sum of Squares (SST): " << SST << "\n";
    std::cout << "Between-Group Sum of Squares (SSB): " << SSB << "\n";
    std::cout << "Within-Group Sum of Squares (SSW): " << SSW << "\n";
    std::cout << "Degrees of Freedom (Between): " << df_between << "\n";
    std::cout << "Degrees of Freedom (Within): " << df_within << "\n";
    std::cout << "Mean Squares (Between): " << MSB << "\n";
    std::cout << "Mean Squares (Within): " << MSW << "\n";
    std::cout << "F Statistic: " << F_statistic << "\n";
    std::cout << "Compare this F statistic with a critical value from an F-table.\n";

    return 0;
}
