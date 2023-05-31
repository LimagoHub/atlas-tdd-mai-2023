#include <iostream>
#include "DependencyImpl.h"
#include "MyServiceUsingDependency.h"

int main() {
    DependencyImpl impl;
    MyServiceUsingDependency myServiceUsingDependency{impl};
	std::cout << "Hallo" << std::endl;
}