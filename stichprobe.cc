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
    int sum = 0;

    for (int i = 0; i < 234; ++i) {
        sum += arr[i];
    }

    double average = sum / 234.0;
    std::cout << "Average: " << average << std::endl;

    file.close();
    }


    {
    std::ifstream file("datensumme.txt");
    if (!file.is_open()) {
        std::cout << "cannot open datensumme.txt" << std::endl;
        return 1;}

    int arr[234];
    
    for (int i = 0; i < 234; ++i) {
        file >> arr[i];
    }
    int sum = 0;

    for (int i = 0; i < 234; ++i) {
        sum += arr[i];
    }

    double average = sum / 234.0;
    double variance = 0.0;

    for (int i = 0; i < 234; ++i) {
        variance += (arr[i] - average) * (arr[i] - average);
    }
    
    variance /= 234.0;
    std::cout << "Variance: " << variance << std::endl;
    double stddev = std::sqrt(variance);
    std::cout << "Standard Deviation: " << stddev << std::endl;
    file.close();
    }
    return 0;
}