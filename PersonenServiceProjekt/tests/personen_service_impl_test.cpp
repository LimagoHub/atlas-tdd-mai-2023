//
// Created by JoachimWagner on 01.06.2023.
//

#include "personen_service_impl_test.h"
#include <stdexcept>

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