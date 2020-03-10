//
// Created by Leo on 03.03.2020.
//

#include "gtest/gtest.h"
#include "matrix.h"


TEST(CONSTRUCTOR, BASE) {
    ASSERT_EQ(matrix<bool>().to_string(), "");
    ASSERT_EQ(matrix<char>().to_string(), "");
    ASSERT_EQ(matrix<char>().to_string(), "");
    ASSERT_EQ(matrix<int>().to_string(), "");
    ASSERT_EQ(matrix<long int>().to_string(), "");
    ASSERT_EQ(matrix<long long int>().to_string(), "");
}

TEST(CONSTRUCTOR, STRING_1x1) {
    ASSERT_EQ("                0\n", matrix<int>(1).to_string());
    ASSERT_EQ("                0\n", matrix<int>(1, 1).to_string());
    ASSERT_EQ("                1\n", matrix<int>(1, 1, 1).to_string());
    ASSERT_EQ("                2\n", matrix<int>(1, 1, 2).to_string());
}

TEST(CONSTRUCTOR, VECTOR_2x2) {
    ASSERT_EQ(matrix<int>({{0, 0}, {0, 0}}), matrix<int>(2));
    ASSERT_EQ(matrix<int>({{0, 0}, {0, 0}}), matrix<int>(2, 2));
    ASSERT_EQ(matrix<int>({{1, 1}, {1, 1}}), matrix<int>(2, 2, 1));
    ASSERT_EQ(matrix<int>({{2, 2}, {2, 2}}), matrix<int>(2, 2, 2));
}

TEST(CONSTRUCTOR, VECTOR_3x3) {
    ASSERT_EQ(matrix<int>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}), matrix<int>(3));
    ASSERT_EQ(matrix<int>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}), matrix<int>(3, 3));
    ASSERT_EQ(matrix<int>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}), matrix<int>(3, 3, 1));
    ASSERT_EQ(matrix<int>({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}), matrix<int>(3, 3, 2));
}

TEST(CONSTRUCTOR, VECTOR_4x4) {
    ASSERT_EQ(matrix<int>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<int>(4));
    ASSERT_EQ(matrix<int>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<int>(4, 4));
    ASSERT_EQ(matrix<int>({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}), matrix<int>(4, 4, 1));
    ASSERT_EQ(matrix<int>({{2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}}), matrix<int>(4, 4, 2));

    ASSERT_EQ(matrix<char>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<char>(4));
    ASSERT_EQ(matrix<char>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<char>(4, 4));
    ASSERT_EQ(matrix<char>({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}), matrix<char>(4, 4, 1));
    ASSERT_EQ(matrix<char>({{2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}}), matrix<char>(4, 4, 2));

    ASSERT_EQ(matrix<long>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<long>(4));
    ASSERT_EQ(matrix<long>({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}), matrix<long>(4, 4));
    ASSERT_EQ(matrix<long>({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}), matrix<long>(4, 4, 1));
    ASSERT_EQ(matrix<long>({{2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}}), matrix<long>(4, 4, 2));
}