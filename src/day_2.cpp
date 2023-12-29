#include <tuple>
#include "day_2.h"
namespace advent_of_code {
bool is_game_possible(std::string line) {
	auto itr = line.begin();
	itr = skip_whitespace(itr, line.end());
	int game_number = 0;
	bool success = false;
	std::tie(itr, success) = match_string(itr, line.end(), "Game");
	itr = skip_whitespace(itr, line.end());
	std::tie(itr, game_number) = parse_int(itr, line.end());

	return false;
}

std::string::iterator skip_whitespace(std::string::iterator it, std::string::iterator end) {
	while (it != end && (*it == ' ' || *it == '\t')) {
		++it;
	};
	return it;
}

std::pair<std::string::iterator, bool> match_string(std::string::iterator itr, std::string::iterator end, std::string pattern) {
	std::string::iterator begin(itr);
	std::string::iterator pattern_itr = pattern.begin();
	while (itr != end && pattern_itr != pattern.end() && (*itr == *pattern_itr)) {
		++itr;
		++pattern_itr;
	}

	if (itr != end && pattern_itr != pattern.end() && (*itr == *pattern_itr)) {
		return { begin, false };
	}

	return { itr, true };
}
	
std::pair<std::string::iterator, int> parse_int(std::string::iterator itr, std::string::iterator end) {
	int result = 0;
	while (itr != end && (*itr >= '0' && *itr <= '9')) {
		result *= 10;
		result += *itr - '0';
		++itr;
	}

	return { itr, result };
}
};
