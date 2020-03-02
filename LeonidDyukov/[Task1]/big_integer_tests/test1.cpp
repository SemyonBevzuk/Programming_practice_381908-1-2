//
// Created by Leo on 22.02.2020.
//

#include <random>
#include "gtest/gtest.h"
#include "big_integer.h"

TEST(CONSTRUCTOR, EMPTY) {
    ASSERT_EQ(big_integer().to_string(), "0");
    ASSERT_NE(big_integer().to_string(), "1");
    std::cout << "Base test status: ........................................OK!" << std::endl;
}

TEST(CONSTRUCTOR, ZERO) {
    ASSERT_EQ(big_integer(0).to_string(), "0");
    ASSERT_NE(big_integer(0).to_string(), "1");
    ASSERT_NE(big_integer(0).to_string(), "-1");
    ASSERT_NE(big_integer(1).to_string(), "0");
    ASSERT_NE(big_integer(-1).to_string(), "0");
    std::cout << "Zero test status: ........................................OK!" << std::endl;
}

TEST(CONSTRUCTOR, POSITIVE_VALUE) {
    ASSERT_EQ(big_integer(1).to_string(), "1");
    ASSERT_EQ(big_integer(2).to_string(), "2");
    ASSERT_NE(big_integer(1).to_string(), "2");
    ASSERT_NE(big_integer(2).to_string(), "1");
    std::cout << "Positive test status: ....................................OK!" << std::endl;
}

TEST(CONSTRUCTOR, NEGATIVE_VALUE) {
    ASSERT_EQ(big_integer(-1).to_string(), "-1");
    ASSERT_EQ(big_integer(-2).to_string(), "-2");
    ASSERT_NE(big_integer(-1).to_string(), "-2");
    ASSERT_NE(big_integer(-2).to_string(), "-1");
    ASSERT_NE(big_integer(1).to_string(), "-1");
    ASSERT_NE(big_integer(-1).to_string(), "1");
    std::cout << "Negative test status: ....................................OK!" << std::endl;
}

TEST(CONSTRUCTOR, RANDOM_LONG_LONG) {
    std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
    std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
    std::uniform_int_distribution<long long> uniformIntDistribution;
    long long value;

    for (int i = 0; i < 10; ++i) {
        value = uniformIntDistribution(eng);
        ASSERT_EQ(big_integer(value).to_string(), std::to_string(value));
    }

    for (int i = 0; i < 10; ++i) {
        value = -1 * uniformIntDistribution(eng);
        ASSERT_EQ(big_integer(value).to_string(), std::to_string(value));
    }
    std::cout << "Random tests status: .....................................OK!" << std::endl;
}

TEST(CONSTRUCTOR, RANDOM_STRING) {
    std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
    std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
    std::uniform_int_distribution<long long> uniformIntDistribution;

    for (int i = 0; i < 10; ++i) {
        auto value = std::to_string(uniformIntDistribution(eng));
        ASSERT_EQ(big_integer(value).to_string(), value);
    }

    for (int i = 0; i < 10; ++i) {
        auto value = std::to_string(-1 * uniformIntDistribution(eng));
        ASSERT_EQ(big_integer(value).to_string(), value);
    }
    std::cout << "Random string tests status: ..............................OK!" << std::endl;
}

TEST(CONSTRUCTOR, ANOTHER_BI) {
    std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
    std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator
    std::uniform_int_distribution<long long> uniformIntDistribution;

    for (int i = 0; i < 10; ++i) {
        auto value = std::to_string(-1 * uniformIntDistribution(eng));
        ASSERT_EQ(big_integer(big_integer(value)).to_string(), value);
    }

    for (int i = 0; i < 10; ++i) {
        auto value = std::to_string(-1 * uniformIntDistribution(eng));
        ASSERT_EQ(big_integer(big_integer(value)).to_string(), value);
    }
    std::cout << "Random string with second constructor tests status: ......OK!" << std::endl;
}
