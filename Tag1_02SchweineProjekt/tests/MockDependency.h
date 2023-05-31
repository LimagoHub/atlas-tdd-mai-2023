//
// Created by JoachimWagner on 31.05.2023.
//

#pragma once



#include "gmock/gmock.h"
#include "../source/Dependency.h"

class MockDependency : public Dependency {
public:
    MOCK_METHOD(void, foo, (std::string message), (const, override));
    MOCK_METHOD(int, bar, (), (const, override));
    MOCK_METHOD(int, foobar, (std::string message), (const, override));
};



