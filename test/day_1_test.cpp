#include <gtest/gtest.h>

#include "day_1.h"

TEST(DAY_1_TEST, GET_LINE_SUM_HAPPY_PATH) {
    int result = advent_of_code::get_line_sum("1abc2");
    EXPECT_EQ(result, 12);
}

TEST(DAY_1_TEST, GET_LINE_SUM_HAPPY_2) {
    int result = advent_of_code::get_line_sum("treb7uchet");
    EXPECT_EQ(result, 77);
}

TEST(DAY_1_TEST, GET_LINE_MATCHERS) {
    int result = advent_of_code::get_line_sum_with_matchers("two1nine");
    EXPECT_EQ(result, 29);
}
