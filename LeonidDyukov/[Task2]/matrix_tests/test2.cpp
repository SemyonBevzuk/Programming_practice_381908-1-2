//
// Created by Leo on 05.03.2020.
//

#include "gtest/gtest.h"
#include "matrix.h"

TEST(LOGICAL, EQUAL) {
    ASSERT_EQ(matrix<long>(), matrix<long>(0));
    ASSERT_EQ(matrix<long>(1), matrix<long>(1));
    ASSERT_EQ(matrix<long>(1, 1), matrix<long>(1));
    ASSERT_EQ(matrix<long>(1, 1), matrix<long>(1, 1, long(0)));
}

TEST(LOGICAL, NOT_EQUAL) {
    ASSERT_NE(matrix<long>(), matrix<long>(1));
    ASSERT_NE(matrix<long>(1), matrix<long>(2));
    ASSERT_NE(matrix<long>(1, 1), matrix<long>(2));
    ASSERT_NE(matrix<long>(1, 1), matrix<long>(2, 1, long(0)));
    ASSERT_NE(matrix<long>(1, 1), matrix<long>(1, 1, long(1)));
}

TEST(LOGICAL, ZERO) {
    ASSERT_TRUE(matrix<int>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}).is_zero());

    ASSERT_FALSE(matrix<int>({{1, 0, 0}, {0, 0, 0}, {0, 0, 1}}).is_zero());
    ASSERT_FALSE(matrix<int>({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}).is_zero());
    ASSERT_FALSE(matrix<int>({{0, 0, 0}, {0, 0, 0}, {0, 0, 1}}).is_zero());
    ASSERT_FALSE(matrix<int>({{0, 0, 1}, {0, 0, 0}, {0, 0, 0}}).is_zero());
}

TEST(LOGICAL, DIAGONAL) {
    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {0, 1, 0},
                                    {0, 0, 1}}).is_diagonal());

    ASSERT_FALSE(matrix<int>({
                                    {1, 0, 1},
                                    {0, 0, 0},
                                    {0, 0, 1}}).is_diagonal());

}

TEST(LOGICAL, HIGH_DIAGONAL) {
    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {0, 1, 0},
                                    {0, 0, 1}}).is_upper_triangle());

    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 1},
                                    {0, 1, 0},
                                    {0, 0, 1}}).is_upper_triangle());

    ASSERT_TRUE(matrix<int>({
                                    {1, 1, 0},
                                    {0, 0, 0},
                                    {0, 0, 0}}).is_upper_triangle());

    ASSERT_FALSE(matrix<int>({
                                     {1, 0, 1},
                                     {0, 0, 0},
                                     {0, 1, 1}}).is_upper_triangle());
}

TEST(LOGICAL, LOW_DIAGONAL) {
    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {0, 1, 0},
                                    {0, 0, 1}}).is_lower_triangle());

    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {0, 1, 0},
                                    {1, 0, 1}}).is_lower_triangle());

    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {1, 0, 0},
                                    {0, 0, 0}}).is_lower_triangle());

    ASSERT_FALSE(matrix<int>({
                                     {1, 0, 1},
                                     {0, 0, 0},
                                     {0, 1, 1}}).is_lower_triangle());

}

TEST(LOGICAL, SQUARE) {
    ASSERT_FALSE(matrix<int>({
                                     {0, 1, 0},
                                     {0, 0, 1}}).is_square());

    ASSERT_FALSE(matrix<int>({
                                     {1, 0, 0},
                                     {0, 1, 0},
                                     {0, 1, 0},
                                     {0, 0, 1}}).is_square());

    ASSERT_FALSE(matrix<int>({
                                     {1, 0, 0},
                                     {0, 1, 0},
                                     {0, 1, 0},
                                     {0, 0, 1}}).is_square());
    ASSERT_FALSE(matrix<int>({
                                     {1, 0},
                                     {1, 0},
                                     {0, 1}}).is_square());

    ASSERT_FALSE(matrix<int>(3, 2).is_square());
    ASSERT_FALSE(matrix<int>(2, 3).is_square());


    ASSERT_TRUE(matrix<int>({
                                    {1, 0, 0},
                                    {0, 1, 0},
                                    {0, 1, 0}}).is_square());

    ASSERT_TRUE(matrix<int>(2).is_square());
    ASSERT_TRUE(matrix<int>(2, 2).is_square());
    ASSERT_TRUE(matrix<int>(2).is_square());
    ASSERT_TRUE(matrix<int>(1).is_square());
}

