#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>

// Function to calculate the mean of a dataset
double calculate_mean(const std::vector<std::vector<double>>& data) {
    double sum = 0.0;
    size_t count = 0;
    for (const auto& row : data) {
        sum += std::accumulate(row.begin(), row.end(), 0.0);
        count += row.size();
    }
    return sum / count;
}

// Function to calculate sums of squares
void calculate_sums_of_squares(const std::vector<std::vector<double>>& data,
                               const std::vector<int>& factorA,
                               const std::vector<int>& factorB,
                               double grand_mean,
                               double& SSA, double& SSB, double& SSI, double& SSW) {
    size_t n = data.size();
    size_t m = data[0].size(); // Assume all groups have the same size for simplicity

    // Map to store means by factor levels
    std::map<int, double> meansA, meansB;
    std::map<std::pair<int, int>, double> meansInteraction;

    // Calculate means for Factor A
    for (int i = 0; i < n; ++i) {
        double row_mean = std::accumulate(data[i].begin(), data[i].end(), 0.0) / m;
        meansA[factorA[i]] += row_mean;
    }

    // Normalize Factor A means
    for (auto& [level, mean] : meansA) {
        mean /= (n / meansA.size()); // Divide by number of groups per level
    }

    // Calculate means for Factor B
    for (int j = 0; j < m; ++j) {
        double col_sum = 0.0;
        for (int i = 0; i < n; ++i) {
            col_sum += data[i][j];
        }
        meansB[factorB[j]] += col_sum / n;
    }

    // Normalize Factor B means
    for (auto& [level, mean] : meansB) {
        mean /= (m / meansB.size()); // Divide by number of groups per level
    }

    // Calculate interaction means
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            meansInteraction[{factorA[i], factorB[j]}] += data[i][j];
        }
    }

    for (auto& [key, mean] : meansInteraction) {
        mean /= n; // Average across all occurrences
    }

    // Calculate SSA, SSB, SSI, and SSW
    SSA = 0.0;
    SSB = 0.0;
    SSI = 0.0;
    SSW = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double observed = data[i][j];
            double predicted = grand_mean + (meansA[factorA[i]] - grand_mean)
                                             + (meansB[factorB[j]] - grand_mean)
                                             + (meansInteraction[{factorA[i], factorB[j]}] - meansA[factorA[i]] - meansB[factorB[j]] + grand_mean);
            double residual = observed - predicted;

            SSW += residual * residual;
            SSA += (meansA[factorA[i]] - grand_mean) * (meansA[factorA[i]] - grand_mean);
            SSB += (meansB[factorB[j]] - grand_mean) * (meansB[factorB[j]] - grand_mean);
            SSI += (meansInteraction[{factorA[i], factorB[j]}] - meansA[factorA[i]] - meansB[factorB[j]] + grand_mean) *
                   (meansInteraction[{factorA[i], factorB[j]}] - meansA[factorA[i]] - meansB[factorB[j]] + grand_mean);
        }
    }
}

int main() {
    // Example dataset: 3 levels of Factor A and 3 levels of Factor B
    std::vector<std::vector<double>> data = {
        {8.5, 9.0, 8.7}, // Level 1, Factor A
        {10.2, 10.8, 10.5}, // Level 2, Factor A
        {12.1, 11.9, 12.3}  // Level 3, Factor A
    };

    // Factor levels
    std::vector<int> factorA = {0, 1, 2}; // Factor A levels for rows
    std::vector<int> factorB = {0, 1, 2}; // Factor B levels for columns

    // Calculate grand mean
    double grand_mean = calculate_mean(data);

    // Sums of squares
    double SSA = 0.0, SSB = 0.0, SSI = 0.0, SSW = 0.0;

    calculate_sums_of_squares(data, factorA, factorB, grand_mean, SSA, SSB, SSI, SSW);

    // Degrees of freedom
    size_t dfA = factorA.size() - 1;
    size_t dfB = factorB.size() - 1;
    size_t dfInteraction = dfA * dfB;
    size_t dfWithin = factorA.size() * factorB.size() - dfA - dfB - dfInteraction - 1;

    // Mean squares
    double MSA = SSA / dfA;
    double MSB = SSB / dfB;
    double MSI = SSI / dfInteraction;
    double MSW = SSW / dfWithin;

    // F-statistics
    double FA = MSA / MSW;
    double FB = MSB / MSW;
    double FI = MSI / MSW;

    // Output results
    std::cout << "Grand Mean: " << grand_mean << "\n";
    std::cout << "SSA: " << SSA << ", SSB: " << SSB << ", SSI: " << SSI << ", SSW: " << SSW << "\n";
    std::cout << "Degrees of Freedom (A): " << dfA << "\n";
    std::cout << "Degrees of Freedom (B): " << dfB << "\n";
    std::cout << "Degrees of Freedom (Interaction): " << dfInteraction << "\n";
    std::cout << "Degrees of Freedom (Within): " << dfWithin << "\n";
    std::cout << "FA: " << FA << ", FB: " << FB << ", FI: " << FI << "\n";
    std::cout << "Compare F-statistics with critical values in an F-table.\n";

    return 0;
}
