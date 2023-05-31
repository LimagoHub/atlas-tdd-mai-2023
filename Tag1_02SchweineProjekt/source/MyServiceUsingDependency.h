//
// Created by JoachimWagner on 31.05.2023.
//

#ifndef BLANKCMAKEPROJECT_MYSERVICEUSINGDEPENDENCY_H
#define BLANKCMAKEPROJECT_MYSERVICEUSINGDEPENDENCY_H
#include "algorithm"
#include "Dependency.h"

using namespace std;
class MyServiceUsingDependency {
    Dependency &dependency;

public:
    explicit MyServiceUsingDependency(Dependency &dependency) : dependency(dependency) {}

    void f(std::string value) {
        transform(value.begin(), value.end(), value.begin(), ::toupper);
        dependency.foo(value);
    }

    int g() {
       auto result = dependency.bar();
        return result * result;
    }

    int h(std::string message) {
        std::string parameter = message + " Welt";
        return dependency.foobar(parameter) + 10;
    }
};

#endif //BLANKCMAKEPROJECT_MYSERVICEUSINGDEPENDENCY_H
