//
// Created by JoachimWagner on 31.05.2023.
//

#include "StapelTest.h"

TEST_F(StapelTest, demo) {
    EXPECT_TRUE(objectUnderTest.is_empty());
}

TEST_F(StapelTest, demo2) {
    objectUnderTest.push(1);
    EXPECT_FALSE(objectUnderTest.is_empty());
}
