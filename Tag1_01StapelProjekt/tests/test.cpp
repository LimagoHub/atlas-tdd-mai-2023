//
// Created by JoachimWagner on 31.05.2023.
//
#include "gtest/gtest.h"
TEST(TestSuiteName, TestName) {

    // Arrange
    // Action
    // Assertion

    const char cstring[] = "Hallo";
    const std::string string = "Hello";
    EXPECT_STREQ(cstring,"Hallo");  //
    EXPECT_EQ(string,"Hello");

}
