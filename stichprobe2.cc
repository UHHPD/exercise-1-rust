#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main() {
    {
    std::ifstream file("datensumme.txt");
    if (!file.is_open()) {
        std::cout << "cannot open datensumme.txt" << std::endl;
        return 1;}

    int arr[234];
    
    for (int i = 0; i < 234; ++i) {
        file >> arr[i];
    }
    int num = 234/9;
    int sum[num];
    for (int i = 0; i < num; ++i) {
        sum[i] = 0;
        for (int j = 0; j < 9; ++j) {
            sum[i] += arr[i * 9 + j];
        }
    }

    double mean[num];
    for (int i = 0; i < num; ++i) {
        mean[i] = sum[i] / 9;
    }

    double variance[num];
    for (int i = 0; i < num; ++i) {
        variance[i] = 0.0;
        for (int j = 0; j < 9; ++j) {
            variance[i] += (arr[i * 9 + j] - mean[i]) * (arr[i * 9 + j] - mean[i]);
        }
        variance[i] /= 9.0;
    }

    std::ofstream output_file_mean("mittelwerte.txt");
    if (!output_file_mean.is_open()) {
        std::cout << "cannot create mittelwerte.txt" << std::endl;
        return 1;
    }
    for (int i = 0; i < num; ++i) {
        output_file_mean << mean[i] << std::endl;
    }

    std::ofstream output_file_variance("varianzen.txt");
    if (!output_file_variance.is_open()) {
        std::cout << "cannot create varianzen.txt" << std::endl;
        return 1;
    }
    for (int i = 0; i < num; ++i) {
        output_file_variance << variance[i] << std::endl;
    }

    double mean_mean = 0.0;
    for (int i = 0; i < num; ++i) {
        mean_mean += mean[i];
    }
    mean_mean /= num;

    double variance_mean = 0.0;
    double variance_mean_bessel = 0.0;
    for (int i = 0; i < num; ++i) {
        variance_mean += variance[i];
    }
    variance_mean /= num;
    variance_mean_bessel = variance_mean * num / (num - 1);
    std::cout << "Mean of Means: " << mean_mean << std::endl;
    std::cout << "Mean of Variances: " << variance_mean << std::endl;
    std::cout << "Mean of Variances (Bessel corrected): " << variance_mean_bessel << std::endl;

    file.close();
    output_file_mean.close();
    output_file_variance.close();
    }
    return 0;
}