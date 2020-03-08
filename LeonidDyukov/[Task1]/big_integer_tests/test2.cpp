//
// Created by Leo on 27.02.2020.
//

#include "gtest/gtest.h"
#include "big_integer.h"

TEST(LOGICAL, EQUAL) {
    ASSERT_EQ(big_integer(0), big_integer(0));
    ASSERT_EQ(big_integer(1), big_integer(1));
    ASSERT_EQ(big_integer(-1), big_integer(-1));
    std::cout << "Equal logical test status: ...............................OK!" << std::endl;
}

TEST(LOGICAL, NOT_EQUAL) {
    ASSERT_NE(big_integer(0), big_integer(1));
    ASSERT_NE(big_integer(0), big_integer(-1));
    ASSERT_NE(big_integer(1), big_integer(-1));
    std::cout << "NOT equal logical test status: ...........................OK!" << std::endl;
}

TEST(LOGICAL, LESS_OR_EQUAL) {
    ASSERT_LE(big_integer(0), big_integer(1));
    ASSERT_LE(big_integer(-1), big_integer(0));
    ASSERT_LE(big_integer(-1), big_integer(1));
    std::cout << "Less or equal logical test status: .......................OK!" << std::endl;
}

TEST(LOGICAL, LESS) {
    ASSERT_LT(big_integer(0), big_integer(1));
    ASSERT_LT(big_integer(-1), big_integer(0));
    ASSERT_LT(big_integer(-1), big_integer(1));
    std::cout << "Less logical test status: ................................OK!" << std::endl;
}

TEST(LOGICAL, GREAT_OR_EQUAL) {
    ASSERT_GE(big_integer(0), big_integer(0));
    ASSERT_GE(big_integer(1), big_integer(0));
    ASSERT_GE(big_integer(0), big_integer(-1));
    ASSERT_GE(big_integer(1), big_integer(-1));
    std::cout << "Great or equal logical test status: ......................OK!" << std::endl;
}

TEST(LOGICAL, GREAT) {
    ASSERT_GT(big_integer(1), big_integer(0));
    ASSERT_GT(big_integer(0), big_integer(-1));
    ASSERT_GT(big_integer(1), big_integer(-1));
    std::cout << "Great logical test status: ...............................OK!" << std::endl;
}

