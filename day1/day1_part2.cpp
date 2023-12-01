#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

int main() {
    // A dictionary
    std::unordered_map<std::string, char> digitMap = {
        {"0", '0'},
        {"1", '1'},
        {"2", '2'},
        {"3", '3'},
        {"4", '4'},
        {"5", '5'},
        {"6", '6'},
        {"7", '7'},
        {"8", '8'},
        {"9", '9'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };

    std::ifstream inputFile("../day1/day1_input.txt");

    // Positive lookahead to get overlapping matches 
    std::regex digit_pattern{"(?=(\\d|one|two|three|four|five|six|seven|eight|nine))"};
    std::string line{};
    int cal_val_sum{0};
    while (std::getline(inputFile, line)) {
        // For each line, apply a regex search for digits and add the numerical
        // values to a vector
        std::regex_iterator<std::string::iterator> regexIt(line.begin(), line.end(), digit_pattern);
        std::regex_iterator<std::string::iterator> regexEnd;
        std::vector<int> line_digits{};
        while (regexIt != regexEnd) {
            std::string match = regexIt->str(1);
            line_digits.push_back(digitMap[match]);
            ++regexIt;
        }
        // Concatenate the first and last elements into a string
        std::string cal_val_str = std::string(1,line_digits.front()) + std::string(1,line_digits.back());
        cal_val_sum += std::stoi(cal_val_str);
        line_digits.clear();
    }
    std::cout << "Sum of calibration values: " << cal_val_sum << '\n';
};
