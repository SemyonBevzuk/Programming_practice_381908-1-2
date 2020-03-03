//
// Created by Leo on 27.02.2020.
//

#include <matrix.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    matrix<int> a = matrix<int>(10);
    return 1;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
