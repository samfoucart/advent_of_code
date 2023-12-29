#ifndef DAY_2_H
#define DAY_2_H
#include <string>
namespace advent_of_code {
bool is_game_possible(std::string line);
std::string::iterator skip_whitespace(std::string::iterator it, std::string::iterator end);
std::pair<std::string::iterator, bool> match_string(std::string::iterator itr, std::string::iterator end, std::string pattern);
};
std::pair<std::string::iterator, int> parse_int(std::string::iterator itr, std::string::iterator end);
#endif
