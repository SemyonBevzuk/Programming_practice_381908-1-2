//
// Created by Leo on 27.02.2020.
//

#include <Matrix.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    auto a = Matrix<int>(3);
    std::cout << a.to_string() << std::endl;
    int **b = new int*[3];
    for (int i = 0; i < 3; ++i) {
        b[i] = new int[3]{1, 2, 3};
    }
    a.init(b);
    std::cout << a.to_string() << std::endl;
    return 1;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
