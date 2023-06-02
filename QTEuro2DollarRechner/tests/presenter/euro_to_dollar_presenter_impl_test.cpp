//
// Created by JoachimWagner on 13.04.2023.
//

#include "euro_to_dollar_presenter_impl_test.h"

TEST_F(euro_to_dollar_presenter_impl_test, beenden__happyDay__GameOver){
    EXPECT_CALL(euro_to_dollar_viewMock, dispose()).Times(1);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test, populate_items__happyDay__maskInitialized){
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0")).Times(1);
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true)).Times(1);
    object_under_test.populate_items();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__NANInEuroField__errorMessageInDollarfield){
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl")).Times(1);
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__unexpected_exception_in_underlying_service__errorMessageInDollarfield){
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return(validEuroValue));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Ein Fehler ist aufgetreten")).Times(1);
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(_)).Times(1).WillOnce(Throw(std::out_of_range{"Upps"}));
    object_under_test.rechnen();
}

//TEST_F(euro_to_dollar_presenter_impl_test, rechnen__validEuro__parameter_passed_to_service){
//    const auto validEuroValue = "10";
//    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return(validEuroValue));
//
//    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).Times(1);
//    object_under_test.rechnen();
//}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__HappyDay__result_in_dollar_field){
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return(validEuroValue));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).Times(1).WillOnce(Return(100.));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("100.00")).Times(1);
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__validNumberInEuroField__rechnen_enabled){
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return(validEuroValue));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true)).Times(1);
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__NANInEuroField__rechnen_disabled){

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).Times(1).WillOnce(Return("Not a Number"));

    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false)).Times(1);
    object_under_test.update_rechnen_action_state();
}



void euro_to_dollar_presenter_impl_test::SetUp() {
    object_under_test.set_view(&euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}
