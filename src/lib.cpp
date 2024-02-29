#include "lib.hpp"  // for lib::build_input, lib::StringPatternFinder

#include <algorithm>  // for std::transform, std::remove
#include <cctype>     // for std::tolower
#include <iterator>   // for std::back_inserter, std::next
#include <regex>      // for std::regex, std::sregex_iterator, std::smatch
#include <string>     // for std::string
#include <vector>     // for std::vector

namespace lib {

// Helper functions that are not available outside this file
namespace {

/**
 * @brief Convert a string to lowercase and remove all comma characters.
 *
 * This is a helper function that is not available outside this file.
 *
 * @param str String to convert.
 *
 * @return Lowercased string without commas.
 */
std::string turn_lowercase_and_remove_commas(const std::string &str)
{
    // Create copy of the input string (so we can use RVO when returning the result)
    std::string result = str;
    // Convert the string to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    // Remove commas
    result.erase(std::remove(result.begin(), result.end(), ','), result.end());
    return result;
}

/**
 * @brief Find all matches of a pattern in a string.
 *
 * This is a helper function that is not available outside this file.
 *
 * @param str String to search in.
 * @param pattern Pattern to search for.
 *
 * @return All matches of the pattern in the string.
 */
[[nodiscard]] std::vector<std::string> find_matches_in_string(const std::string &str, const std::regex &regex_pattern)
{
    std::vector<std::string> result;
    // Create const iterators pointing to the start and end of the sequence of matches
    std::sregex_iterator begin(str.cbegin(), str.cend(), regex_pattern), end;
    // Use std::transform to iterate over each match in the sequence
    // For each match, convert it to a string and add it to the result vector
    std::transform(begin, end, std::back_inserter(result),
                   [](const std::smatch &match) { return match.str(); });
    result.shrink_to_fit();
    return result;
}

}  // namespace

std::vector<std::string> build_input(const int argc, const char **argv)
{
    // If no arguments were provided, return a placeholder std::vector
    if (argc < 2) {
        return {
            "The first version was released on 12-07-2008 (12th of july 2008).",
            "Next Release will might come on 12 July 2009.",
            "The due date for payment is 2023-09-1.",
            "The date on which the Constitution of Poland came into effect on 17 october 1997.",
            "The meeting is scheduled for 05/12/2022.",
            "The lunar eclipse will occur on Monday, 16/05/2022.",
            "The solar eclipse will occur on 2022-10-25.",
            "The event is on 2-Jan-2023.",
            "The marathon is on 3rd Jan 2023 (Tue).",
            "The festival is on 4th january 23.",
            "The concert is on 5-may-19 (5th may 19).",
            "The exhibition is on 6 jan-23.",
            "The fair is on 7 Jan-13.",
            "The event is on 8 apr 23 (8th of april 2023).",
            "See you on Sunday at 10:30 am.",
            "See you on Tuesday at 18:30.",
            "I work from 9am to to 5pm and he works from 8:00 am to 4:30 pm.",
            "The meeting is scheduled for Wednesday, 3rd June 2023 at 3:30 pm.",
            "The webinar begins at 2:00 pm on 5th August 2023.",
            "The workshop is on Thursday, 6th September 2023 at 4:00 pm.",
        };
    }
    // Construct a std::vector<std::string> from the command line arguments, excluding the program's name
    // Note: std::next() returns a pointer to the next element in the array
    // Note: The range used to construct the vector is half-open (exclusive), similar to Python's range function (the last element is not included)
    return std::vector<std::string>(
        std::next(argv),       // Start from the second element, skipping the program's name (argv + 1)
        std::next(argv, argc)  // End one past the last command line argument (argv + argc), because range is exclusive
    );
}

StringPatternFinder::StringPatternFinder(std::string str)
    : str_(turn_lowercase_and_remove_commas(str)) {}

std::vector<std::string> StringPatternFinder::get_dates()
{
    // Define a pattern that matches various date formats
    static const std::regex date_pattern(R"((\d{1,2}(st|nd|rd|th)?[./-]\d{1,2}[./-]\d{2,4}|\d{1,2}(st|nd|rd|th)?[\s-]?(of )?(january|february|march|april|may|june|july|august|september|october|november|december|jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec)\s?-?\d{2,4}|\d{4}-\d{1,2}-\d{1,2}))");
    // Find all matches of the date pattern in the string (must be lowercase)
    return find_matches_in_string(this->str_, date_pattern);
}

std::vector<std::string> StringPatternFinder::get_times()
{
    // Define a pattern that matches various time formats
    static const std::regex time_pattern(R"((2[0-3]|[01]?\d):\d{2}(:\d{2})?(?:\s([ap]m))?|(1[0-2]|0?[1-9]):\d{2}(:\d{2})?(?:\s([ap]m))|(1[0-2]|0?[1-9])[ap]m)");
    // Find all matches of the time pattern in the string (must be lowercase)
    return find_matches_in_string(this->str_, time_pattern);
}

std::vector<std::string> StringPatternFinder::get_days()
{
    // Define a pattern that matches the names of the days of the week
    static const std::regex day_pattern(R"((mon(day)?|tue(sday)?|wed(nesday)?|thu(rsday)?|fri(day)?|sat(urday)?|sun(day)?))");
    // Find all matches of the day pattern in the string (must be lowercase)
    return find_matches_in_string(this->str_, day_pattern);
}

}  // namespace lib
