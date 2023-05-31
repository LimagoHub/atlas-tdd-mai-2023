//
// Created by JoachimWagner on 31.05.2023.
//

#ifndef BLANKCMAKEPROJECT_DEPENDENCYIMPL_H
#define BLANKCMAKEPROJECT_DEPENDENCYIMPL_H

#include <iostream>
#include "Dependency.h"

class DependencyImpl : public Dependency {
public:
    void foo(std::string message) const override {
        std::cout << message << std::endl;
    }

    int bar() const override {
        return 42;
    }

    int foobar(std::string message) const override {
        return message.length();
    }
};

#endif //BLANKCMAKEPROJECT_DEPENDENCYIMPL_H
