#include "day_1.h"
#include <algorithm>
#include <istream>
#include <map>
#include <string>

namespace advent_of_code {
bool match_string_offset(std::string input, std::string matcher, int offset);

int get_line_sum(std::string line) {
    std::string::iterator left_digit =
        std::find_if(line.begin(), line.end(),
                     [](char c) -> bool { return c >= '0' && c <= '9'; });

    std::string::reverse_iterator right_digit =
        std::find_if(line.rbegin(), line.rend(),
                     [](char c) -> bool { return c >= '0' && c <= '9'; });

    if (left_digit == line.end() || right_digit == line.rend()) {
        return 0;
    }

    int left = *left_digit - '0';
    int right = *right_digit - '0';
    return (left * 10) + right;
}

int sum_stream(std::istream &ins) {
    int result = 0;
    std::string output;
    while (std::getline(ins, output)) {
        // result += get_line_sum(output);
        result += get_line_sum_with_matchers(output);
    }

    return result;
}

bool match_string_offset(std::string input, std::string matcher, int offset) {
    if (offset + matcher.size() > input.size()) {
        return false;
    }

    for (int i = 0; i < matcher.size(); ++i) {
        if (input[offset + i] != matcher[i]) {
            return false;
        }
    }

    return true;
}

int get_line_sum_with_matchers(std::string line) {
    std::map<std::string, int> matchers = { 
        { "one", 1 },
        { "two", 2 },
        { "three", 3 },
        { "four", 4 },
        { "five", 5 },
        { "six", 6 },
        { "seven", 7 },
        { "eight", 8 },
        { "nine", 9}
    };
    
    int left = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] > '0' && line[i] <= '9') {
            left = line[i] - '0';
            break;
        }

        for (std::pair<std::string, int> matcher : matchers) {
            if (match_string_offset(line, matcher.first, i)) {
                    left = matcher.second;
                    break;
            }
        }

        if (left != 0) {
            break;
        }
    }


    int right = 0;
    for (int i = line.size() - 1; i >= 0; --i) {
        if (line[i] > '0' && line[i] <= '9') {
            right = line[i] - '0';
            break;
        }

        for (std::pair<std::string, int> matcher : matchers) {
            if (match_string_offset(line, matcher.first, i)) {
                    right = matcher.second;
                    break;
            }
        }

        if (right != 0) {
            break;
        }
    }

    return (10 * left) + right;
}
} // namespace advent_of_code
