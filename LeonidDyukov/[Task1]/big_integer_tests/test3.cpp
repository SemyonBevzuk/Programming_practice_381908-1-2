//
// Created by Leo on 22.02.2020.
//

#include <random>
#include "gtest/gtest.h"
#include "big_integer.h"


//######################################################################################################################
//######################################################################################################################


TEST(MATH_SUM, ONE_SIGN) {
    ASSERT_EQ(big_integer(0), big_integer(0) + big_integer(0));
    ASSERT_EQ(big_integer(1), big_integer(0) + big_integer(1));
    ASSERT_EQ(big_integer(2), big_integer(1) + big_integer(1));
    ASSERT_EQ(big_integer(-2), big_integer(-1) + big_integer(-1));

    ASSERT_NE(big_integer(1), big_integer(1) + big_integer(1));
    ASSERT_NE(big_integer(0), big_integer(0) + big_integer(1));
    ASSERT_NE(big_integer(1), big_integer(0) + big_integer(0));
    std::cout << "Sum one sign values math tests status: ...................OK!" << std::endl;
}

TEST(MATH_SUM, DIFF_SIGN) {
    ASSERT_EQ(big_integer(0), big_integer(-1) + big_integer(1));
    ASSERT_EQ(big_integer(0), big_integer(1) + big_integer(-1));
    ASSERT_EQ(big_integer(2), big_integer(3) + big_integer(-1));
    ASSERT_EQ(big_integer(2), big_integer(-1) + big_integer(3));

    ASSERT_NE(big_integer(1), big_integer(-1) + big_integer(1));
    ASSERT_NE(big_integer(1), big_integer(0) + big_integer(-1));
    ASSERT_NE(big_integer(1), big_integer(-2) + big_integer(1));
    std::cout << "Sum diff sign values math tests status: ..................OK!" << std::endl;
}

TEST(MATH_SUM, RANDOM) {
    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xfffffffffffffff), (1 * 0xfffffffffffffff));

    for (int i = 0; i < 1000; ++i) {
        auto a = long(distribution(generator));
        auto b = long(distribution(generator));

        ASSERT_EQ(big_integer(a) + big_integer(b), a + b);
    }
    std::cout << "Sum random value test status: ............................OK!" << std::endl;
}


//######################################################################################################################
//######################################################################################################################


TEST(MATH_SUB, ONE_SIGN) {
    ASSERT_EQ(big_integer(0), big_integer(0) - big_integer(0));
    ASSERT_EQ(big_integer(0), big_integer(1) - big_integer(1));
    ASSERT_EQ(big_integer(-1), big_integer(0) - big_integer(1));
    ASSERT_EQ(big_integer(0), big_integer(-1) - big_integer(-1));

    ASSERT_NE(big_integer(1), big_integer(1) - big_integer(1));
    ASSERT_NE(big_integer(0), big_integer(0) - big_integer(1));
    ASSERT_NE(big_integer(1), big_integer(0) - big_integer(0));
    std::cout << "Sub one sign values math tests status: ...................OK!" << std::endl;
}

TEST(MATH_SUB, DIFF_SIGN) {
    ASSERT_EQ(big_integer(-1), big_integer(-1) - big_integer(0));
    ASSERT_EQ(big_integer(1), big_integer(0) - big_integer(-1));
    ASSERT_EQ(big_integer(2), big_integer(1) - big_integer(-1));
    ASSERT_EQ(big_integer(-2), big_integer(-1) - big_integer(1));

    ASSERT_NE(big_integer(-1), big_integer(-1) - big_integer(1));
    ASSERT_NE(big_integer(-1), big_integer(0) - big_integer(-1));
    ASSERT_NE(big_integer(-2), big_integer(1) - big_integer(-1));
    std::cout << "Sub diff sign values math tests status: ..................OK!" << std::endl;
}

TEST(MATH_SUB, RANDOM) {
    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xfffffffffffffff), (1 * 0xfffffffffffffff));

    for (int i = 0; i < 1000; ++i) {
        auto a = long(distribution(generator));
        auto b = long(distribution(generator));

        ASSERT_EQ(big_integer(a) - big_integer(b), a - b);
    }
    std::cout << "Sub random value test status: ............................OK!" << std::endl;
}


//######################################################################################################################
//######################################################################################################################


TEST(MATH_MUL, ONE_SIGN) {
    ASSERT_EQ(big_integer(0), big_integer(0) * big_integer(0));
    ASSERT_EQ(big_integer(1), big_integer(1) * big_integer(1));
    ASSERT_EQ(big_integer(6), big_integer(2) * big_integer(3));
    ASSERT_EQ(big_integer(6), big_integer(-2) * big_integer(-3));

    ASSERT_NE(big_integer(1), big_integer(1) * big_integer(0));
    ASSERT_NE(big_integer(0), big_integer(1) * big_integer(1));
    ASSERT_NE(big_integer(1), big_integer(1) * big_integer(2));
    std::cout << "Mul one sign values math tests status: ...................OK!" << std::endl;
}

TEST(MATH_MUL, DIFF_SIGN) {
    ASSERT_EQ(big_integer(-1), big_integer(-1) * big_integer(1));
    ASSERT_EQ(big_integer(-1), big_integer(1) * big_integer(-1));
    ASSERT_EQ(big_integer(-2), big_integer(2) * big_integer(-1));
    ASSERT_EQ(big_integer(-2), big_integer(-1) * big_integer(2));

    ASSERT_NE(big_integer(1), big_integer(-1) * big_integer(1));
    ASSERT_NE(big_integer(-1), big_integer(0) * big_integer(-1));
    ASSERT_NE(big_integer(-2), big_integer(1) * big_integer(-1));
    std::cout << "Mul diff sign values math tests status: ..................OK!" << std::endl;
}

TEST(MATH_MUL, RANDOM) {
    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xfffffff), (1 * 0xfffffff));

    for (int i = 0; i < 1000; ++i) {
        long long int a = long(distribution(generator));
        long long int b = long(distribution(generator));

        ASSERT_EQ(big_integer(a) * big_integer(b), a * b);
    }
    std::cout << "Mul random value test status: ............................OK!" << std::endl;
}


//######################################################################################################################
//######################################################################################################################


TEST(MATH_DIV, ONE_SIGN) {
    ASSERT_THROW(big_integer(1) / big_integer(0), std::invalid_argument);

    ASSERT_EQ(big_integer(1), big_integer(1) / big_integer(1));
    ASSERT_EQ(big_integer(2), big_integer(2) / big_integer(1));
    ASSERT_EQ(big_integer(3), big_integer(3) / big_integer(1));

    ASSERT_EQ(big_integer(0), big_integer(1) / big_integer(2));
    ASSERT_EQ(big_integer(1), big_integer(2) / big_integer(2));
    ASSERT_EQ(big_integer(1), big_integer(3) / big_integer(2));

    ASSERT_EQ(big_integer(0), big_integer(1) / big_integer(3));
    ASSERT_EQ(big_integer(1), big_integer(3) / big_integer(3));
    ASSERT_EQ(big_integer(3), big_integer(9) / big_integer(3));

    ASSERT_EQ(big_integer(0), big_integer(0) / big_integer(3));
    ASSERT_EQ(big_integer(0), big_integer(0) / big_integer(5));
    ASSERT_EQ(big_integer(4), big_integer(9) / big_integer(2));

    std::cout << "Div one sign values math tests status: ...................OK!" << std::endl;
}

TEST(MATH_DIV, DIFF_SIGN) {
    ASSERT_THROW(big_integer(-1) / big_integer(0), std::invalid_argument);

    ASSERT_EQ(big_integer(-1), big_integer(-1) / big_integer(1));
    ASSERT_EQ(big_integer(-1), big_integer(1) / big_integer(-1));
    ASSERT_EQ(big_integer(-2), big_integer(-2) / big_integer(1));
    ASSERT_EQ(big_integer(-2), big_integer(2) / big_integer(-1));
    ASSERT_EQ(big_integer(-3), big_integer(-3) / big_integer(1));
    ASSERT_EQ(big_integer(-3), big_integer(3) / big_integer(-1));

    ASSERT_EQ(big_integer(0), big_integer(-1) / big_integer(2));
    ASSERT_EQ(big_integer(-1), big_integer(-2) / big_integer(2));
    ASSERT_EQ(big_integer(-1), big_integer(-3) / big_integer(2));

    ASSERT_EQ(big_integer(0), big_integer(-1) / big_integer(3));
    ASSERT_EQ(big_integer(-1), big_integer(-3) / big_integer(3));
    ASSERT_EQ(big_integer(-3), big_integer(-9) / big_integer(3));

    ASSERT_EQ(big_integer(0), big_integer(0) / big_integer(3));
    ASSERT_EQ(big_integer(0), big_integer(0) / big_integer(5));
    ASSERT_EQ(big_integer(-4), big_integer(-9) / big_integer(2));
    std::cout << "Div diff sign values math tests status: ..................OK!" << std::endl;
}

TEST(MATH_DIV, RANDOM) {
    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xffffffffffffff), (1 * 0xffffffffffffff));

    for (int i = 0; i < 1000; ++i) {
        long long int a = long(distribution(generator));
        long long int b = long(distribution(generator));

        ASSERT_EQ(big_integer(a) / big_integer(b), a / b);
    }
    std::cout << "Div random value test status: ............................OK!" << std::endl;
}
