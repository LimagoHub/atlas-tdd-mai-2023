//
// Created by JoachimWagner on 31.05.2023.
//

#include "StapelTest.h"


namespace collections {
    TEST_F(StapelTest, is_empty__empty_stack__returnsTrue) {
        // Assertion
        EXPECT_TRUE(objectUnderTest.is_empty());
    }

    TEST_F(StapelTest, is_empty__not_empty_stack__returnsFalse) {
       // Arrange
       objectUnderTest.push(1);
       // Act
        auto result = objectUnderTest.is_empty();
       // Assertion
        EXPECT_FALSE(result);

    }
    TEST_F(StapelTest, push__fill_up_to_Limit__no_Exception_is_thrown) {
        // Arrange

        fillup_to_limit_without_exception();


    }
    TEST_F(StapelTest, push__overflow__throwsStapelException) {
        // Arrange

        fillup_to_limit_without_exception();

        EXPECT_THROW(objectUnderTest.push(1), StapelException);
    }

    TEST_F(StapelTest, push__overflow__throwsStapelException__variante) {
        // Arrange
        try {
            fillup_to_limit_without_exception();

            objectUnderTest.push(1);
            FAIL() << "Fehler: StapelException erwartet";
        } catch(const StapelException & ex) {
            EXPECT_STREQ("Overflow", ex.what());
        }
    }
}