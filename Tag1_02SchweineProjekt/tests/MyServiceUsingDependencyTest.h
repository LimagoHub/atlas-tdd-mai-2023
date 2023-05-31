//
// Created by JoachimWagner on 31.05.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockDependency.h"
#include "../source/MyServiceUsingDependency.h"
using namespace testing;
class MyServiceUsingDependencyTest : public Test{
protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};
};
