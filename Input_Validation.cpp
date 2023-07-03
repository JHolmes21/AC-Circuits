#include "Input_Validation.h"
#include <iostream>
#include <algorithm>
#include <sstream>


int get_menu_option() {
    while (true) {
        std::cout << "Enter your choice: ";
        std::string input;
        std::cin >> input;

        if (std::all_of(input.begin(), input.end(), ::isdigit)) {
            return std::stoi(input);
        }
        else {
            std::cout << "Invalid input. Please enter an integer in the specified range.\n";
        }
    }
}
double get_positive_number() {
    std::string input;
    bool valid_input = false;
    double number;

    while (!valid_input) {
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (ss >> number && !(ss >> input) && number > 0) {
            valid_input = true;
        }
        else {
            std::cout << "Invalid input. Please enter a positive number: ";
        }
    }

    return number;
}