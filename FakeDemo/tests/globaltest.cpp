//
// Created by JoachimWagner on 14.12.2022.
//

#include "globaltest.h"
#include <iostream>


class Foo {
public:
    void bar() {
        std::cout << mult(7,8) << std::endl;
    }
};


TEST(demo, mult_demo) {
    EXPECT_GLOBAL_CALL(mult,mult(_,_)).WillOnce(Return(5.0));
    Foo out;
    out.bar();
}