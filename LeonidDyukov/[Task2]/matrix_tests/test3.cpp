//
// Created by Leo on 05.03.2020.
//


#include <random>
#include "gtest/gtest.h"
#include "matrix.h"


TEST(MATH_SUM, ZERO) {
    auto a = matrix<int>(10, 10, 0);
    auto b = matrix<int>(10, 10, 1);
    auto c = matrix<int>(10, 10, 2);

    ASSERT_EQ(a + b, b);
    ASSERT_EQ(a + c, c);
}

TEST(MATH_SUM, ONE) {
    auto a = matrix<int>(10, 10, 0);
    auto b = matrix<int>(10, 10, 1);
    auto c = matrix<int>(10, 10, 2);

    ASSERT_EQ(b + b, c + a);
}

TEST(MATH_SUM, UNARY_ONE) {
    auto b = matrix<int>(10, 10, 1);
    auto c = matrix<int>(10, 10, 2);
    auto a = matrix<int>(10, 10, -1);

    ASSERT_EQ(c + a, b);
}

TEST(MATH_SUM, ONE_RANDOM) {
    size_t row = 50;
    size_t str = 50;

    auto a = matrix<long long int>(row, str, 1);
    auto b = matrix<long long int>(row, str, (long long int)(0));
    auto c = matrix<long long int>(row, str);

    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xfffffffffffffff), (1 * 0xfffffffffffffff));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < str; ++j) {
            c[i][j] = long(distribution(generator));
        }
    }

    ASSERT_EQ(c + b, c);

    a = c;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < str; ++j) {
            c[i][j] += 10;
        }
    }
    b = matrix<long long int>(row, str, 10);

    ASSERT_EQ(a + b, c);
}


TEST(MATH_SUM, TWO_RANDOM) {
    size_t row = 50;
    size_t str = 50;

    auto a = matrix<long long int>(row, str);
    auto b = matrix<long long int>(row, str);
    auto c = matrix<long long int>(row, str);

    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(
            (-1 * 0xfffffffffffffff), (1 * 0xfffffffffffffff));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < str; ++j) {
            a[i][j] = long(distribution(generator));
            b[i][j] = long(distribution(generator));
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    ASSERT_EQ(a + b, c);
}

