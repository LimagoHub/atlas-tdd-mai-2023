//
// Created by JoachimWagner on 01.06.2023.
//

#include "personen_service_impl_test.h"
#include <stdexcept>

TEST_P(personen_service_impl_parameter_test, speichern__throws_personen_service_exception) {
    try {

        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), expectedErrorMessage.c_str());
    }
}


TEST_F(personen_service_impl_test, speichern__vorname_tooShort__throws_personen_service_exception) {
    try {
        person invalidPerson{"j", "doe"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Vorname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_tooShort__throws_personen_service_exception) {
    try {
        person invalidPerson{"john", "d"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Nachname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__unerwuenschtePerson__throws_personen_service_exception) {
    try {
        EXPECT_CALL(blacklistServiceMock, is_blacklisted(_)).Times(1).WillOnce(Return(true));
        person unerwuenschtePerson{"John", "Doe"};
        object_under_test.speichern(unerwuenschtePerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Unerwuenschte Person");
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_service__throws_personen_service_exception) {
    try {
        person validPerson{"John", "Doe"};
        //EXPECT_CALL(blacklistServiceMock, is_blacklisted(_)).Times(1).WillOnce(Return(false));

        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::out_of_range{"Upps"}));

        object_under_test.speichern(validPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Unexpected Exception in underlying Service");

    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__parameter_passed_to_repo) {

        InSequence s1;
        person validPerson{"John", "Doe"};

        EXPECT_CALL(blacklistServiceMock, is_blacklisted(validPerson)).WillOnce(Return(false));
        EXPECT_CALL(repoMock, save_or_update(validPerson)).Times(1);

        object_under_test.speichern(validPerson);

}

TEST_F(personen_service_impl_test, speichern_overloaded__happy_day__parameter_passed_to_repo) {

    person captured_person{"",""};

    EXPECT_CALL(blacklistServiceMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    object_under_test.speichern("Max", "Doe");

    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), "Doe");
    EXPECT_THAT(captured_person.getId(), IsEmpty());
;
}


INSTANTIATE_TEST_SUITE_P(
        speichern_invalid_names, // Name der Testa frei waehlbar
        personen_service_impl_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(person{"","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"J","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"John",""},"Nachname zu kurz" ),
                std::make_pair(person{"John","D"},"Nachname zu kurz" )
        )
);
