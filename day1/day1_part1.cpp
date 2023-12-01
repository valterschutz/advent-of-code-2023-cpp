#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ifstream inputFile("../day1/day1_test_input.txt");

    std::string line{};
    int cal_val_sum{0};
    while (std::getline(inputFile, line)) {
        // Loop through each char in line
        std::vector<char> line_digits{};
        for (auto c: line) {
            // If the char matches a digit, add it to vector of digits
            if (std::isdigit(c)) {
                line_digits.push_back(c);
            }
        }
        // Concatenate the first and last elements into a string
        std::string cal_val_str = std::string(1,line_digits.front()) + std::string(1,line_digits.back());
        cal_val_sum += std::stoi(cal_val_str);
        line_digits.clear();
    }
    std::cout << "Sum of calibration values: " << cal_val_sum << '\n';
};
