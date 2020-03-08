//
// Created by Leo on 27.02.2020.
//

#include <big_integer.h>
#include "gtest/gtest.h"

TEST(Tester, 1) {
    ASSERT_EQ(big_integer(1) + 1, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
