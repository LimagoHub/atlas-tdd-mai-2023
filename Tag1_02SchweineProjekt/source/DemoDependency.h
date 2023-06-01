//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once

#include "Dependency.h"
class DemoDependency : public Dependency{
public:
    void foo(std::string message) const override {

    }

    int bar() const override {
        return 0;
    }

    int foobar(std::string message) const override {
        return 0;
    }
};
