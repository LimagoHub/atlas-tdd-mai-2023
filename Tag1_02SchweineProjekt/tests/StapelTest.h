//
// Created by JoachimWagner on 31.05.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/Stapel.h"

using namespace testing;
class StapelTest : public Test{

protected:
    Stapel objectUnderTest;
};
