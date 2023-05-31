//
// Created by JoachimWagner on 31.05.2023.
//

#include "MyServiceUsingDependencyTest.h"

TEST_F(MyServiceUsingDependencyTest, footest){

    EXPECT_CALL(dependencyMock, foo("HALLO"));

    objectUnderTest.f("hallo");

//    // Recordmode
//    EXPECT_CALL(dependencyMock, bar())
//        .WillOnce(Return(47))
//        .WillOnce(Return(48))
//        .WillOnce(Return(49))
//        .WillOnce(Throw(std::exception{"Upps"}));
//
//    // Replaymode
//    EXPECT_EQ(47, dependencyMock.bar());
//    EXPECT_EQ(48, dependencyMock.bar());
//    EXPECT_EQ(49, dependencyMock.bar());
//    EXPECT_THROW(dependencyMock.bar(), std::exception);

}

TEST_F(MyServiceUsingDependencyTest, bartest){

    EXPECT_CALL(dependencyMock, bar()).WillOnce(Return(10));

    auto result = objectUnderTest.g();

    EXPECT_EQ(99, result);
    EXPECT_THAT(100, Not(Eq(result)));

}

TEST_F(MyServiceUsingDependencyTest, foobartest){

    EXPECT_CALL(dependencyMock, foobar(_)).WillOnce(Return(10));
    //EXPECT_CALL(dependencyMock, foobar("Hello Welt")).WillOnce(Return(20));

    auto result = objectUnderTest.h("Hallo");
    //auto result2 = objectUnderTest.h("Hello");

    EXPECT_EQ(20, result);

}

