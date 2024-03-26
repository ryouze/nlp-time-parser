#include "lib.hpp"

#include <cstdlib>    // for std::exit, EXIT_FAILURE
#include <exception>  // for std::exception
#include <iostream>   // for std::cout, std::cerr
#include <string>     // for std::string
#include <utility>    // for std::make_pair

/**
 * @brief Entry-point of the application.
 */
int main(int argc, const char **argv)
{
    try {
        // Disable synchronization between the C++ standard streams (e.g., std::cin, std::cout) and their corresponding C equivalents
        std::ios_base::sync_with_stdio(false);
        // Separator string of 80 hyphens (defined outside loop for efficiency)
        const std::string separator(80, '-');
        // Iterate over each command line argument (if no arguments are provided, a placeholder is used)
        for (const auto &input : lib::build_input(argc, argv)) {
            std::cout << "[INFO] Input: " << input << '\n';
            std::cout << "[INFO] Output:\n";
            lib::StringPatternFinder finder(input);
            // Use structured bindings (C++17) to unpack the pair into two variables: label and matches
            // For example, given a pair `std::pair<int, std::string> pair = {1, "example"};`,
            // you can unpack it like so: `auto [number, text] = pair;`
            // In this case, `number` would be an int with the value 1, and `text` would be a std::string with the value "example"
            for (const auto &[label, matches] : {
                     // Create a temporary array of std::pair objects using an initializer list `{...}`
                     // For example, you can create a vector of ints like so: `std::vector<int> numbers = {1, 2, 3, 4, 5};`
                     std::make_pair("\t(1) Date", finder.get_dates()),
                     std::make_pair("\t(2) Time", finder.get_times()),
                     std::make_pair("\t(3) Day of the week", finder.get_days()),
                 }) {
                lib::print_vector(label, matches);
            }
            // Print the separator
            std::cout << separator << '\n';
        }
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    catch (...) {
        std::cerr << "ERROR: Unknown\n";
        std::exit(EXIT_FAILURE);
    }
    return 0;
}
