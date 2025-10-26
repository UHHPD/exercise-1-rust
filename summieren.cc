#include <iostream>
#include <fstream>
#include <string>

int main() {
    {
    std::ifstream file("daten.txt");
    if (!file.is_open()) {
        std::cout << "cannot open" << std::endl;
        return 1;}

    int num1, num2;
    file >> num1 >> num2;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    file.close();
    }


    {
    std::ifstream file("daten.txt");
    if (!file.is_open()) {
        std::cout << "cannot open daten.txt" << std::endl;
        return 1;}

    std::string line;
    int lineNumber = 1;
    
    while (std::getline(file, line) && lineNumber <= 234) {
        std::cout << line << std::endl;
        lineNumber++;}

    file.close();
    }


    {
    std::ifstream input_file("daten.txt");
    if (!input_file.is_open()) {
        std::cout << "cannot open daten.txt" << std::endl;
        return 1;
    }
    
    std::ofstream output_file("datensumme.txt");
    if (!output_file.is_open()) {
        std::cout << "cannot create datensumme.txt" << std::endl;
        input_file.close();
        return 1;
    }
    
    int num1, num2;
    
    while (input_file >> num1 >> num2) {
        int sum = num1 + num2;
        output_file << sum << std::endl;
    }
    
    input_file.close();
    output_file.close();
    }



    return 0;
}