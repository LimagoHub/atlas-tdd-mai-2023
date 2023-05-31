//
// Created by JoachimWagner on 31.05.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "../../source/collections/Stapel.h"

using namespace testing;

namespace collections {

    class StapelTest : public Test{
    protected:
        Stapel objectUnderTest;

        void fillup_to_limit_without_exception() {
            for (int i = 0; i < 10; ++i) {
                EXPECT_NO_THROW(objectUnderTest.push(1));
            }
        }
    };



} // collections
