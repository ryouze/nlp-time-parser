#pragma once

#include <algorithm>  // for std::copy
#include <iostream>   // for std::cout
#include <iterator>   // for std::ostream_iterator
#include <string>     // for std::string
#include <vector>     // for std::vector

namespace lib {

/**
 * @brief Create a vector of strings from command line arguments. If no arguments are provided, a placeholder vector containing example dates and days is used.
 *
 * @param argc Number of command-line arguments (e.g., "2").
 * @param argv Array of command-line arguments (e.g., {"./bin", "-h"}).
 *
 * @return All arguments as strings or a placeholder if no arguments were given.
 */
[[nodiscard]] std::vector<std::string> build_input(const int argc, const char **argv);

/**
 * @brief Print a labeled vector to the standard output.
 *
 * This function prints a label followed by a vector's contents to the standard output. The output format is similar to Python's list representation (e.g., "label = [1, 2, 3]"). Each item is separated by a comma, except the last item.
 *
 * @tparam T Type of the items in the vector.
 * @param label Label to print before the vector's contents.
 * @param items Items to print.
 */
template <typename T>
void print_vector(const std::string &label, const std::vector<T> &items)
{
    std::cout << label << " = [";

    // If the vector is not empty, print its elements, otherwise close the square brackets immediately
    if (!items.empty()) {
        // Use std::copy to print all elements in 'items' except the last one, each followed by a comma and a space
        // The range for std::copy is [first, last), where 'first' is inclusive and 'last' is exclusive
        // 'items.cbegin()' is the 'first' iterator (points to the first element)
        // 'items.cend() - 1' is the 'last' iterator (points to the last element; std:copy is exclusive)
        // std::ostream_iterator<T> is an output iterator that writes elements to std::cout, separating them with a comma and a space
        std::copy(items.cbegin(), items.cend() - 1, std::ostream_iterator<T>(std::cout, ", "));

        // Print the last element of the vector without a comma and a space after it
        std::cout << items.back();
    }

    std::cout << "]\n";
}

/**
 * @brief Class that finds dates, times, and days in a string.
 *
 * On construction, the input string is converted to lowercase and all commas are removed. The class provides methods to get all dates, times, and days found in the input string.
 */
class StringPatternFinder {
  public:
    /**
     * @brief Construct a new String Pattern Finder object.
     *
     * @param str String to search. This string will be converted to lowercase and its commas will be removed inside this constructor.
     */

    /**
     * @brief Construct a new String Pattern Finder object.
     *
     * @param str String to search (e.g., "The first version was released on 12-07-2008 (12th of july 2008").
     */
    explicit StringPatternFinder(std::string str);  // Explicit prevents implicit conversion from std::string to StringPatternFinder

    /**
     * @brief Get the dates found in the string.
     *
     * @return All dates, with each represented as a string in the format it was found (e.g., "2008-07-12").
     */
    [[nodiscard]] std::vector<std::string> get_dates();

    /**
     * @brief Get the times found in the string.
     *
     * @return All times, with each represented as a string in the format it was found (e.g., "12:00").
     */
    [[nodiscard]] std::vector<std::string> get_times();

    /**
     * @brief Get the days found in the string.
     *
     * @return All days, with each represented as a string in the format it was found (e.g., "monday").
     */
    [[nodiscard]] std::vector<std::string> get_days();

  private:
    /**
     * @brief Input string (lowercase, without commas).
     */
    const std::string str_;
};

}  // namespace lib
