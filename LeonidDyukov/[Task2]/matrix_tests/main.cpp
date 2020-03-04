//
// Created by Leo on 27.02.2020.
//

#include <matrix.h>
#include "gtest/gtest.h"


int main(int argc, char **argv) {
    auto a = matrix<int>({{1, 1}, {0, 1}});
    auto c = matrix<int>({{2, 0}, {0, 2}});
    a *= c;
    std::cout << a << std::endl << c << std::endl << a * c * 3 << std::endl;
    return 1;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
