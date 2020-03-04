//
// Created by Leo on 27.02.2020.
//

#include <matrix.h>
#include "gtest/gtest.h"


int main(int argc, char **argv) {
    auto a = matrix<int>(3, 3, 1);
    auto b = matrix<int>(3, 3, 1);

    int **list = new int*[3];
    list[0] = new int[3]{1, 0, 0};
    list[1] = new int[3]{0, 1, 0};
    list[2] = new int[3]{1, 0, 1};
    a.init(list);

    a.at(1, 1) = 2;

    auto c = matrix<int>({{1, 2, 1}, {1, 3, 1}, {1, 3, 1}});
    std::cout << a << c << a + c << std::endl;

    std::cout << a.is_upper_triangle() << std::endl;
    std::cout << a.is_lower_triangle() << std::endl;
    return 1;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
