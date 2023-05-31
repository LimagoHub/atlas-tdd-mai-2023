//
// Created by JoachimWagner on 31.05.2023.
//

#ifndef BLANKCMAKEPROJECT_DEPENDENCY_H
#define BLANKCMAKEPROJECT_DEPENDENCY_H

#include <string>

class Dependency {
public:
    virtual void foo(std::string message) const = 0;
    virtual int bar() const = 0;
    virtual int foobar(std::string message) const = 0;

};


#endif //BLANKCMAKEPROJECT_DEPENDENCY_H
